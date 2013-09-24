/*
 * MFileEventsSim.cxx
 *
 *
 * Copyright (C) by Andreas Zoglauer.
 * All rights reserved.
 *
 *
 * This code implementation is the intellectual property of
 * Andreas Zoglauer.
 *
 * By copying, distributing or modifying the Program (or any work
 * based on the Program) you indicate your acceptance of this statement,
 * and all its terms.
 *
 */


////////////////////////////////////////////////////////////////////////////////
//
// MFileEventsSim
//
////////////////////////////////////////////////////////////////////////////////


// Include the header:
#include "MFileEventsSim.h"

// Standard libs:
#include <string>
using namespace std;

// ROOT libs:
#include "Rtypes.h"

// MEGAlib libs:
#include "MAssert.h"
#include "MStreams.h"


////////////////////////////////////////////////////////////////////////////////


#ifdef ___CINT___
ClassImp(MFileEventsSim)
#endif


////////////////////////////////////////////////////////////////////////////////


MFileEventsSim::MFileEventsSim(MDGeometryQuest* Geo) : MFileEvents()
{
  // Construct an instance of MFileEventsSim

  m_Geo = Geo;
  Init();
}


////////////////////////////////////////////////////////////////////////////////


MFileEventsSim::MFileEventsSim() : MFileEvents()
{
  // Construct an instance of MFileEventsSim

  m_Geo = 0;

  Init();
}


////////////////////////////////////////////////////////////////////////////////


MFileEventsSim::~MFileEventsSim()
{
  // Delete this instance of MFileEventsSim
}


////////////////////////////////////////////////////////////////////////////////


void MFileEventsSim::Init()
{
  // Construct an instance of MFileEventsSim

  m_EventId = c_NoId;
  m_IsFirstEvent = true;

  m_FileType = "sim";

  m_SimulationStartAreaFarField = 0.0;
}


////////////////////////////////////////////////////////////////////////////////


bool MFileEventsSim::Open(MString FileName, unsigned int Way)
{
  // Open the file

  if (m_Geo == 0) {
    mout<<"Error while opening file "<<m_FileName<<": "<<endl;
    mout<<"No geometry present"<<endl;    
    return false;
  }

  massert(m_Geo != 0);

  m_IncludeFileUsed = false;
  m_IncludeFile = new MFileEventsSim();
  dynamic_cast<MFileEventsSim*>(m_IncludeFile)->SetGeometry(m_Geo);
  m_IncludeFile->SetIsIncludeFile(true);

  if (MFileEvents::Open(FileName, Way) == false) {
    return false;
  }

  if (Way == c_Read) {
    if (m_Geo->IsScanned() == false) {
      mout<<"We do not have a properly initialized geometry!"<<endl;
      return false;
    }
    m_EventId = -1;
    m_IsFirstEvent = true;

    // Find some initial keyword:
    MString Line;
    unsigned int MaxAdvanceRead = 100;
    while(!m_File.eof()) {
      if (MaxAdvanceRead-- == 0) break;
      Line.ReadLine(m_File);
      
      if (Line.BeginsWith("SimulationStartAreaFarField") == true) {
        MTokenizer Tokens;
        Tokens.Analyze(Line);
        if (Tokens.GetNTokens() != 2) {
          mout<<"Error while opening file "<<m_FileName<<": "<<endl;
          mout<<"Unable to read SimulationStartAreaFarField"<<endl;              
        } else {
          m_SimulationStartAreaFarField = Tokens.GetTokenAtAsDouble(1);
          break;
        }
      }
    }

    // Now go to the end of the file to find the TS keyword
    bool FoundTS = false;
    int Start = 1;
    int StartMax = 100000;
    while (FoundTS == false) {
      Start *= 10;
      if (Start > StartMax) break;

      m_SimulatedEvents = 0;

      m_File.clear();
      if (m_FileLength > (streampos) Start) {
        m_File.seekg(m_FileLength - streamoff(Start));
      } else {
        // start from the beginning...
        MFile::Rewind();
      }

     MString Line;
     Line.ReadLine(m_File); // Ignore the first line
      while(!m_File.eof()) {
        Line.ReadLine(m_File);
      
        // In case the job crashed badly we might have no TS, thus use the last ID
        if (Line.BeginsWith("ID") == true) {
          MTokenizer Tokens;
          Tokens.Analyze(Line);
          if (Tokens.GetNTokens() == 3) {
            m_SimulatedEvents = Tokens.GetTokenAtAsInt(2);
          }
        }
        if (FoundTS == false) {
          if (Line.BeginsWith("TS") == true) {
            MTokenizer Tokens;
            Tokens.Analyze(Line);
            if (Tokens.GetNTokens() != 2) {
              mout<<"Error while opening file "<<m_FileName<<": "<<endl;
              mout<<"Unable to read TS keyword"<<endl;              
            } else {
              m_SimulatedEvents = Tokens.GetTokenAtAsInt(1);
              FoundTS = true;
              break;
            }
          }
        }
      }
      MFile::Rewind();

      if (m_SimulatedEvents > 0) break;
    }
  }

  return true;
}


////////////////////////////////////////////////////////////////////////////////


MSimEvent* MFileEventsSim::GetNextEvent(bool Analyze)
{
  // Return the next event... or 0 if it is the last one
  // So remember to test for more events!

  if (m_IncludeFileUsed == true) {
    MSimEvent* RE = ((MFileEventsSim*) m_IncludeFile)->GetNextEvent(Analyze);
    if (RE == 0) {
      m_IncludeFile->Close();
      m_IncludeFileUsed = false;
    } else {
      return RE;
    }
  }

  if (UpdateProgress() == false) return 0;

  // Unfortunately the SE has options which need to be parsed and the event has no
  // end event tag. This complicates the reading process as follows:

  MSimEvent* Event = new MSimEvent();
  Event->SetGeometry(m_Geo);
  if (m_EventId != c_NoId) {
    Event->SetID(m_EventId);
  }

  MString Line;
  while(!m_File.eof()) {
    Line.ReadLine(m_File);
    if (Line.Length() < 2) continue;

    if (Line[0] == 'S' && Line[1] == 'E') {
      
      if (sscanf(Line.Data(), "SE %ld", &m_EventId) != 1) {
        if (sscanf(Line.Data(), "SE %ld;%*ld;%*ld;%*ld", &m_EventId) != 1) {
          m_EventId = c_NoId;
        }
        m_EventId = c_NoId;
      }

      if (m_IsFirstEvent == false) {
        if (Analyze == true) {
          Event->Analyze();
        }
        return Event;
      } else {
        m_IsFirstEvent = false;
      }

    } else if (Line[0] == 'N' && Line[1] == 'F') {
      if (OpenNextFile(Line) == 0) {
        mout<<"Did not find a valid continuation file..."<<endl;
        return 0;
      }

      if (m_IsFirstEvent == false) {
        if (Analyze == true) {
          Event->Analyze();
        }
        m_IsFirstEvent = true;
        return Event;
      } 
    } 
    // Include another file:
    else if (Line[0] == 'I' && Line[1] == 'N') {

      if (OpenIncludeFile(Line) == true) {
        // We we already had an event, but its empty
        if (m_IsFirstEvent == false && Event->GetNIAs() == 0 && Event->GetNHTs() == 0) {
          merr<<"A file should not have events AND \"IN\" keywords! The *last* event is lost"<<show;
        }
        delete Event;
        Event = ((MFileEventsSim*) m_IncludeFile)->GetNextEvent(Analyze);
        if (Event == 0) {
          m_IncludeFile->Close();
          m_IncludeFileUsed = false;

          // Since we always need to have an event here:
          Event = new MSimEvent();
          Event->SetGeometry(m_Geo);
        } else {
          return Event;
        }
      } else {
        m_IncludeFile->Close();
        m_IncludeFileUsed = false;
       }
    } 
    // The end of file keyword
    else if (Line[0] == 'E' && Line[1] == 'N') {
      if (m_IsFirstEvent == false) {
        if (Analyze == true) {
          Event->Analyze();
        }
        m_IsFirstEvent = true;
        return Event;
      } 
    } 
    // All other keyword directly related to an event
    else {
      // Let the raw event scan the line 
      Event->AddRawInput(Line, m_Version);
    }
  }

  // That's a dirty little trick, but currently no case exits where a sim file has neither no IAs or no HTs...
  if (Event->GetNIAs() != 0 || Event->GetNHTs() != 0) {
    return Event;
  }

  // The end of the (master) file has been reached...
  ShowProgress(false);
  delete Event;

  return 0;
}


////////////////////////////////////////////////////////////////////////////////


bool MFileEventsSim::AddText(const MString& Text)
{
  // Write some text:

  if (m_Way == c_Read) {
    merr<<"Only valid if file is in write-mode!"<<endl;
    massert(m_Way != c_Read);
    return false;
  }

  if (m_IsOpen == false) return false;

  if (m_IncludeFileUsed == true) {
    ((MFileEventsSim*) m_IncludeFile)->AddText(Text);
    if (m_IncludeFile->GetFileLength() > m_MaxFileLength) {
      return CreateIncludeFile();
    }
  } else {
    m_File<<Text<<flush;
    if (m_IsIncludeFile == false && GetFileLength() > m_MaxFileLength) {
      return CreateIncludeFile();
    }
  }

  return true;
}


////////////////////////////////////////////////////////////////////////////////


bool MFileEventsSim::AddEvent(MSimEvent* Event)
{
  // Write this event:

  if (m_Way == c_Read) {
    merr<<"Only valid if file is in write-mode!"<<endl;
    massert(m_Way != c_Read);
    return false;
  }
  
  if (m_IsOpen == false) return false;

  if (m_IncludeFileUsed == true) {
    ((MFileEventsSim*) m_IncludeFile)->AddEvent(Event);
    if (m_IncludeFile->GetFileLength() > m_MaxFileLength) {
      return CreateIncludeFile();
    }
  } else {
    m_File<<Event->ToSimString(MSimEvent::c_StoreSimulationInfoAll, 0)<<flush;
    if (m_IsIncludeFile == false && GetFileLength() > m_MaxFileLength) {
      return CreateIncludeFile();
    }
  }

  return true;
}


////////////////////////////////////////////////////////////////////////////////


bool MFileEventsSim::OpenIncludeFile(const MString& Line)
{
  bool Return = MFileEvents::OpenIncludeFile(Line);

  if (Return == true) {
    m_SimulatedEvents += dynamic_cast<MFileEventsSim*>(m_IncludeFile)->GetSimulatedEvents();
  }

  return Return;
}


////////////////////////////////////////////////////////////////////////////////


bool MFileEventsSim::CloseEventList()
{
  // Close the event list after last event (per default add "EN"(D))

  if (m_Way == c_Read) {
    merr<<"Only valid if file is in write-mode!"<<endl;
    massert(m_Way != c_Read);
    return false;
  }

  m_File<<"EN"<<endl;
  m_File<<endl;
  m_File<<"TE "<<m_ObservationTime<<endl;
  m_File<<"TS "<<m_SimulatedEvents<<endl;
  m_File<<endl;
  
  return true;
}


// MFileEventsSim.cxx: the end...
////////////////////////////////////////////////////////////////////////////////
