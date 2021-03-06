/*
 * MSettingsEventSelections.h
 *
 * Copyright (C) by Andreas Zoglauer.
 * All rights reserved.
 *
 * Please see the source-file for the copyright-notice.
 *
 */


#ifndef __MSettingsEventSelections__
#define __MSettingsEventSelections__


////////////////////////////////////////////////////////////////////////////////


// Standard libs:
#include <vector>
using namespace std;

// Root libs:

// MEGAlib libs:
#include "MGlobal.h"
#include "MTime.h"
#include "MSettings.h"
#include "MPointSource.h"

// Forward declarations:


////////////////////////////////////////////////////////////////////////////////


class MSettingsEventSelections : public MSettingsInterface
{
  // public Session:
 public:
  MSettingsEventSelections();
  virtual ~MSettingsEventSelections();

  // ModificationFlags:
  bool IsEventSelectionModified() { return m_EventSelectionModified; }
  void ResetEventSelectionModified() { m_EventSelectionModified = false; }


  // Menu Eventselection:

  int GetEventSelectorTab() const { return m_EventSelectorTab; }
  void SetEventSelectorTab(int EventSelectorTab) { m_EventSelectorTab = EventSelectorTab; }

  int GetEventTypeCompton() const { return m_EventTypeCompton; }
  void SetEventTypeCompton(int EventTypeCompton) { m_EventTypeCompton = EventTypeCompton; m_EventSelectionModified = true; }

  int GetEventTypeDoubleCompton() const { return m_EventTypeDoubleCompton; }
  void SetEventTypeDoubleCompton(int EventTypeDoubleCompton) { m_EventTypeDoubleCompton = EventTypeDoubleCompton; m_EventSelectionModified = true; }

  int GetEventTypeComptonTracked() const { return m_EventTypeComptonTracked; }
  void SetEventTypeComptonTracked(int EventTypeComptonTracked) { m_EventTypeComptonTracked = EventTypeComptonTracked; m_EventSelectionModified = true; }

  int GetEventTypeComptonNotTracked() const { return m_EventTypeComptonNotTracked; }
  void SetEventTypeComptonNotTracked(int EventTypeComptonNotTracked) { m_EventTypeComptonNotTracked = EventTypeComptonNotTracked; m_EventSelectionModified = true; }

  int GetEventTypePair() const { return m_EventTypePair; }
  void SetEventTypePair(int EventTypePair) { m_EventTypePair = EventTypePair; m_EventSelectionModified = true; }

  int GetEventTypePhoto() const { return m_EventTypePhoto; }
  void SetEventTypePhoto(int EventTypePhoto) { m_EventTypePhoto = EventTypePhoto; m_EventSelectionModified = true; }

  int GetEventTypeUnidentifiable() const { return m_EventTypeUnidentifiable; }
  void SetEventTypeUnidentifiable(int EventTypeUnidentifiable) { m_EventTypeUnidentifiable = EventTypeUnidentifiable; m_EventSelectionModified = true; }

  int GetEventTypeDecay() const { return m_EventTypeDecay; }
  void SetEventTypeDecay(int EventTypeDecay) { m_EventTypeDecay = EventTypeDecay; m_EventSelectionModified = true; }

  bool GetFlaggedAsBad() const { return m_FlaggedAsBad; }
  void SetFlaggedAsBad(bool FlaggedAsBad) { m_FlaggedAsBad = FlaggedAsBad; m_EventSelectionModified = true; }

  void RemoveAllExcludedDetectors() { m_ExcludedDetectors.clear(); m_EventSelectionModified = true; }
  void AddExcludedDetector(const MString& ExcludedDetector) { m_ExcludedDetectors.push_back(ExcludedDetector); m_EventSelectionModified = true; }
  unsigned int GetNExcludedDetectors() const { return m_ExcludedDetectors.size(); }
  MString GetExcludedDetectorAt(unsigned int d) const { if (d < m_ExcludedDetectors.size()) return m_ExcludedDetectors[d]; return ""; }
  vector<MString> GetExcludedDetectors() const { return m_ExcludedDetectors; }


  int GetSequenceLengthRangeMin() const { return m_SequenceLengthRangeMin; }
  void SetSequenceLengthRangeMin(int SequenceLengthRangeMin) { m_SequenceLengthRangeMin = SequenceLengthRangeMin; m_EventSelectionModified = true; }

  int GetSequenceLengthRangeMax() const { return m_SequenceLengthRangeMax; }
  void SetSequenceLengthRangeMax(int SequenceLengthRangeMax) { m_SequenceLengthRangeMax = SequenceLengthRangeMax; m_EventSelectionModified = true; }

  int GetTrackLengthRangeMin() const { return m_TrackLengthRangeMin; }
  void SetTrackLengthRangeMin(int TrackLengthRangeMin) { m_TrackLengthRangeMin = TrackLengthRangeMin; m_EventSelectionModified = true; }

  int GetTrackLengthRangeMax() const { return m_TrackLengthRangeMax; }
  void SetTrackLengthRangeMax(int TrackLengthRangeMax) { m_TrackLengthRangeMax = TrackLengthRangeMax; m_EventSelectionModified = true; }

  double GetClusteringQualityFactorRangeMin() const { return m_ClusteringQualityFactorRangeMin; }
  void SetClusteringQualityFactorRangeMin(double ClusteringQualityFactorRangeMin) { m_ClusteringQualityFactorRangeMin = ClusteringQualityFactorRangeMin; m_EventSelectionModified = true; }

  double GetClusteringQualityFactorRangeMax() const { return m_ClusteringQualityFactorRangeMax; }
  void SetClusteringQualityFactorRangeMax(double ClusteringQualityFactorRangeMax) { m_ClusteringQualityFactorRangeMax = ClusteringQualityFactorRangeMax; m_EventSelectionModified = true; }

  double GetComptonQualityFactorRangeMin() const { return m_ComptonQualityFactorRangeMin; }
  void SetComptonQualityFactorRangeMin(double ComptonQualityFactorRangeMin) { m_ComptonQualityFactorRangeMin = ComptonQualityFactorRangeMin; m_EventSelectionModified = true; }

  double GetComptonQualityFactorRangeMax() const { return m_ComptonQualityFactorRangeMax; }
  void SetComptonQualityFactorRangeMax(double ComptonQualityFactorRangeMax) { m_ComptonQualityFactorRangeMax = ComptonQualityFactorRangeMax; m_EventSelectionModified = true; }

  double GetTrackQualityFactorRangeMin() const { return m_TrackQualityFactorRangeMin; }
  void SetTrackQualityFactorRangeMin(double TrackQualityFactorRangeMin) { m_TrackQualityFactorRangeMin = TrackQualityFactorRangeMin; m_EventSelectionModified = true; }

  double GetTrackQualityFactorRangeMax() const { return m_TrackQualityFactorRangeMax;}
  void SetTrackQualityFactorRangeMax(double TrackQualityFactorRangeMax) { m_TrackQualityFactorRangeMax = TrackQualityFactorRangeMax; m_EventSelectionModified = true; }

  long GetEventIdRangeMin() const { return m_EventIdRangeMin; }
  void SetEventIdRangeMin(long EventIdRangeMin) { m_EventIdRangeMin = EventIdRangeMin; m_EventSelectionModified = true; }

  long GetEventIdRangeMax() const { return m_EventIdRangeMax; }
  void SetEventIdRangeMax(long EventIdRangeMax) { m_EventIdRangeMax = EventIdRangeMax; m_EventSelectionModified = true; }

  double GetFirstEnergyRangeMin() const { return m_FirstEnergyRangeMin; }
  void SetFirstEnergyRangeMin(double FirstEnergyRangeMin) { m_FirstEnergyRangeMin = FirstEnergyRangeMin; m_EventSelectionModified = true; }

  double GetFirstEnergyRangeMax() const { return m_FirstEnergyRangeMax; }
  void SetFirstEnergyRangeMax(double FirstEnergyRangeMax) { m_FirstEnergyRangeMax = FirstEnergyRangeMax; m_EventSelectionModified = true; }

  double GetSecondEnergyRangeMin() const { return m_SecondEnergyRangeMin; }
  void SetSecondEnergyRangeMin(double SecondEnergyRangeMin) { m_SecondEnergyRangeMin = SecondEnergyRangeMin; m_EventSelectionModified = true; }

  double GetSecondEnergyRangeMax() const { return m_SecondEnergyRangeMax; }
  void SetSecondEnergyRangeMax(double SecondEnergyRangeMax) { m_SecondEnergyRangeMax = SecondEnergyRangeMax; m_EventSelectionModified = true; }

  double GetThirdEnergyRangeMin() const { return m_ThirdEnergyRangeMin; }
  void SetThirdEnergyRangeMin(double ThirdEnergyRangeMin) { m_ThirdEnergyRangeMin = ThirdEnergyRangeMin; m_EventSelectionModified = true; }

  double GetThirdEnergyRangeMax() const { return m_ThirdEnergyRangeMax; }
  void SetThirdEnergyRangeMax(double ThirdEnergyRangeMax) { m_ThirdEnergyRangeMax = ThirdEnergyRangeMax; m_EventSelectionModified = true; }

  double GetFourthEnergyRangeMin() const { return m_FourthEnergyRangeMin; }
  void SetFourthEnergyRangeMin(double FourthEnergyRangeMin) { m_FourthEnergyRangeMin = FourthEnergyRangeMin; m_EventSelectionModified = true; }

  double GetFourthEnergyRangeMax() const { return m_FourthEnergyRangeMax; }
  void SetFourthEnergyRangeMax(double FourthEnergyRangeMax) { m_FourthEnergyRangeMax = FourthEnergyRangeMax; m_EventSelectionModified = true; }

  double GetEnergyRangeGammaMin() const { return m_EnergyRangeGammaMin; }
  void SetEnergyRangeGammaMin(double EnergyRangeGammaMin) { m_EnergyRangeGammaMin = EnergyRangeGammaMin; m_EventSelectionModified = true; }

  double GetEnergyRangeGammaMax() const { return m_EnergyRangeGammaMax; }
  void SetEnergyRangeGammaMax(double EnergyRangeGammaMax) { m_EnergyRangeGammaMax = EnergyRangeGammaMax; m_EventSelectionModified = true; }

  double GetEnergyRangeElectronMin() const { return m_EnergyRangeElectronMin; }
  void SetEnergyRangeElectronMin(double EnergyRangeElectronMin) { m_EnergyRangeElectronMin = EnergyRangeElectronMin; m_EventSelectionModified = true; }

  double GetEnergyRangeElectronMax() const { return m_EnergyRangeElectronMax; }
  void SetEnergyRangeElectronMax(double EnergyRangeElectronMax) { m_EnergyRangeElectronMax = EnergyRangeElectronMax; m_EventSelectionModified = true; }

  double GetComptonAngleRangeMin() const { return m_ComptonAngleRangeMin; }
  void SetComptonAngleRangeMin(double ComptonAngleRangeMin) { m_ComptonAngleRangeMin = ComptonAngleRangeMin; m_EventSelectionModified = true; }

  double GetComptonAngleRangeMax() const { return m_ComptonAngleRangeMax; }
  void SetComptonAngleRangeMax(double ComptonAngleRangeMax) { m_ComptonAngleRangeMax = ComptonAngleRangeMax; m_EventSelectionModified = true; }

  double GetEHCAngle() const { return m_EHCAngle; }
  void SetEHCAngle(double EHCAngle) { m_EHCAngle = EHCAngle; m_EventSelectionModified = true; }

  MVector GetEHCEarthPosition() const { return m_EHCEarthPosition; }
  void SetEHCEarthPosition(MVector EHCEarthPosition) { m_EHCEarthPosition = EHCEarthPosition; m_EventSelectionModified = true; }

  double GetEHCProbability() const { return m_EHCProbability; }
  void SetEHCProbability(double EHCProbability) { m_EHCProbability = EHCProbability; m_EventSelectionModified = true; }

  MString GetEHCComptonProbabilityFileName() const { return m_EHCComptonProbabilityFileName; }
  void SetEHCComptonProbabilityFileName(MString EHCComptonProbabilityFileName) { m_EHCComptonProbabilityFileName = EHCComptonProbabilityFileName; m_EventSelectionModified = true; }

  MString GetEHCPairProbabilityFileName() const { return m_EHCPairProbabilityFileName; }
  void SetEHCPairProbabilityFileName(MString EHCPairProbabilityFileName) { m_EHCPairProbabilityFileName = EHCPairProbabilityFileName;  m_EventSelectionModified = true; }

  int GetEHCType() const { return m_EHCType; }
  void SetEHCType(int EHCType) { m_EHCType = EHCType; m_EventSelectionModified = true; }

  bool GetSourceUsePointSource() const { return m_SourceUsePointSource; }
  void SetSourceUsePointSource(bool SourceUsePointSource) { m_SourceUsePointSource = SourceUsePointSource; m_EventSelectionModified = true; }

  int GetSourceCoordinates() const { return m_SourceCoordinates; }
  void SetSourceCoordinates(int SourceCoordinates) { m_SourceCoordinates = SourceCoordinates; m_EventSelectionModified = true; }
  
  double GetSourcePhi() const { return m_SourcePhi; }
  void SetSourcePhi(double SourcePhi) { m_SourcePhi = SourcePhi; m_EventSelectionModified = true; }

  double GetSourceTheta() const { return m_SourceTheta; }
  void SetSourceTheta(double SourceTheta) { m_SourceTheta = SourceTheta; m_EventSelectionModified = true; }
  
  double GetSourceLongitude() const { return m_SourceLongitude; }
  void SetSourceLongitude(double SourceLongitude) { m_SourceLongitude = SourceLongitude; m_EventSelectionModified = true; }

  double GetSourceLatitude() const { return m_SourceLatitude; }
  void SetSourceLatitude(double SourceLatitude) { m_SourceLatitude = SourceLatitude; m_EventSelectionModified = true; }

  double GetSourceX() const { return m_SourceX; }
  void SetSourceX(double SourceX) { m_SourceX = SourceX; m_EventSelectionModified = true; }

  double GetSourceY() const { return m_SourceY; }
  void SetSourceY(double SourceY) { m_SourceY = SourceY; m_EventSelectionModified = true; }

  double GetSourceZ() const { return m_SourceZ; }
  void SetSourceZ(double SourceZ) { m_SourceZ = SourceZ; m_EventSelectionModified = true; }

  double GetSourceARMMin() const { return m_SourceARMMin; }
  void SetSourceARMMin(double SourceARMMin) { m_SourceARMMin = SourceARMMin; m_EventSelectionModified = true; }

  double GetSourceARMMax() const { return m_SourceARMMax; }
  void SetSourceARMMax(double SourceARMMax) { m_SourceARMMax = SourceARMMax; m_EventSelectionModified = true; }

  double GetSourceSPDMin() const { return m_SourceSPDMin; }
  void SetSourceSPDMin(double SourceSPDMin) { m_SourceSPDMin = SourceSPDMin; m_EventSelectionModified = true; }

  double GetSourceSPDMax() const { return m_SourceSPDMax; }
  void SetSourceSPDMax(double SourceSPDMax) { m_SourceSPDMax = SourceSPDMax; m_EventSelectionModified = true; }
  
  bool GetBeamUse() const { return m_BeamUse; }
  void SetBeamUse(bool BeamUse) { m_BeamUse = BeamUse; m_EventSelectionModified = true; }
  
  double GetBeamStartX() const {  return m_BeamStartX; }
  void SetBeamStartX(double BeamStartX) { m_BeamStartX = BeamStartX; m_EventSelectionModified = true; }

  double GetBeamStartY() const { return m_BeamStartY; }
  void SetBeamStartY(double BeamStartY) { m_BeamStartY = BeamStartY; m_EventSelectionModified = true; }

  double GetBeamStartZ() const { return m_BeamStartZ; }
  void SetBeamStartZ(double BeamStartZ) { m_BeamStartZ = BeamStartZ;  m_EventSelectionModified = true; }

  double GetBeamFocalSpotX() const { return m_BeamFocalSpotX; }
  void SetBeamFocalSpotX(double BeamFocalSpotX) { m_BeamFocalSpotX = BeamFocalSpotX; m_EventSelectionModified = true; }

  double GetBeamFocalSpotY() const { return m_BeamFocalSpotY; }
  void SetBeamFocalSpotY(double BeamFocalSpotY) { m_BeamFocalSpotY = BeamFocalSpotY; m_EventSelectionModified = true; }

  double GetBeamFocalSpotZ() const { return m_BeamFocalSpotZ; }
  void SetBeamFocalSpotZ(double BeamFocalSpotZ) { m_BeamFocalSpotZ = BeamFocalSpotZ; m_EventSelectionModified = true; }
  
  double GetBeamRadius() const { return m_BeamRadius; }
  void SetBeamRadius(double BeamRadius) { m_BeamRadius = BeamRadius; m_EventSelectionModified = true; }

  double GetBeamDepth() const { return m_BeamDepth; }
  void SetBeamDepth(double BeamDepth) { m_BeamDepth = BeamDepth; m_EventSelectionModified = true; }



  double GetThetaDeviationMax() const { return m_ThetaDeviationMax; }
  void SetThetaDeviationMax(double ThetaDeviationMax) { m_ThetaDeviationMax = ThetaDeviationMax; m_EventSelectionModified = true; }

  double GetDistanceRangeMin() const { return m_DistanceRangeMin; }
  void SetDistanceRangeMin(double DistanceRangeMin) { m_DistanceRangeMin = DistanceRangeMin; m_EventSelectionModified = true; }

  double GetDistanceRangeMax() const { return m_DistanceRangeMax; }
  void SetDistanceRangeMax(double DistanceRangeMax) { m_DistanceRangeMax = DistanceRangeMax; m_EventSelectionModified = true; }

  double GetFirstDistanceRangeMin() const {  return m_FirstDistanceRangeMin; }
  void SetFirstDistanceRangeMin(double FirstDistanceRangeMin) { m_FirstDistanceRangeMin = FirstDistanceRangeMin; m_EventSelectionModified = true; }

  double GetFirstDistanceRangeMax() { return m_FirstDistanceRangeMax; }
  void SetFirstDistanceRangeMax(double FirstDistanceRangeMax) { m_FirstDistanceRangeMax = FirstDistanceRangeMax; m_EventSelectionModified = true; }

  bool GetTimeUseFile() const { return m_TimeUseFile; }
  void SetTimeUseFile(bool TimeUseFile) { m_TimeUseFile = TimeUseFile; m_EventSelectionModified = true; }

  MTime GetTimeRangeMin() const { return m_TimeRangeMin; }
  void SetTimeRangeMin(MTime TimeRangeMin) { m_TimeRangeMin = TimeRangeMin; m_EventSelectionModified = true; }

  MTime GetTimeRangeMax() const { return m_TimeRangeMax; }
  void SetTimeRangeMax(MTime TimeRangeMax) { m_TimeRangeMax = TimeRangeMax; m_EventSelectionModified = true; }

  MString GetTimeFile() const { return m_TimeFile; }
  void SetTimeFile(MString TimeFile) { m_TimeFile = TimeFile; m_EventSelectionModified = true; }
  
  
  double GetTimeWalkRangeMin() const { return m_TimeWalkRangeMin; }
  void SetTimeWalkRangeMin(double TimeWalkRangeMin) { m_TimeWalkRangeMin = TimeWalkRangeMin; m_EventSelectionModified = true; }

  double GetTimeWalkRangeMax() const { return m_TimeWalkRangeMax; }
  void SetTimeWalkRangeMax(double TimeWalkRangeMax) { m_TimeWalkRangeMax = TimeWalkRangeMax; m_EventSelectionModified = true; }

  double GetCoincidenceWindowRangeMin() const { return m_CoincidenceWindowRangeMin; }
  void SetCoincidenceWindowRangeMin(double CoincidenceWindowRangeMin) { m_CoincidenceWindowRangeMin = CoincidenceWindowRangeMin; m_EventSelectionModified = true; }

  double GetCoincidenceWindowRangeMax() const { return m_CoincidenceWindowRangeMax; }
  void SetCoincidenceWindowRangeMax(double CoincidenceWindowRangeMax) { m_CoincidenceWindowRangeMax = CoincidenceWindowRangeMax; m_EventSelectionModified = true; }

  double GetOpeningAnglePairMin() const { return m_OpeningAnglePairMin; }
  void SetOpeningAnglePairMin(double OpeningAnglePairMin) { m_OpeningAnglePairMin = OpeningAnglePairMin; m_EventSelectionModified = true; }

  double GetOpeningAnglePairMax() const { return m_OpeningAnglePairMax; }
  void SetOpeningAnglePairMax(double OpeningAnglePairMax) { m_OpeningAnglePairMax = OpeningAnglePairMax; m_EventSelectionModified = true; }

  double GetInitialEnergyDepositPairMin() const { return m_InitialEnergyDepositPairMin; }
  void SetInitialEnergyDepositPairMin(double InitialEnergyDepositPairMin) { m_InitialEnergyDepositPairMin = InitialEnergyDepositPairMin; m_EventSelectionModified = true; }

  double GetInitialEnergyDepositPairMax() const { return m_InitialEnergyDepositPairMax; }
  void SetInitialEnergyDepositPairMax(double InitialEnergyDepositPairMax) { m_InitialEnergyDepositPairMax = InitialEnergyDepositPairMax; m_EventSelectionModified = true; }


  //! Set the special GUI mode (this is not saved to file!)
  void SetSpecialMode(const bool SpecialMode) { m_SpecialMode = SpecialMode; }
  //! Get the special GUI mode (this is not saved to file!)
  bool GetSpecialMode() const { return m_SpecialMode; }


  // protected members:
 protected:
  //! Read all data from an XML tree
  virtual bool ReadXml(MXmlNode* Node);
  //! Write all data to an XML tree
  virtual bool WriteXml(MXmlNode* Node);


  // private members:
 protected:

  // The modified flags:
  bool m_EventSelectionModified;


  long m_EventIdRangeMin;
  long m_EventIdRangeMax;

  bool m_TimeUseFile;
  MTime m_TimeRangeMin;
  MTime m_TimeRangeMax;
  MString m_TimeFile;
  
  int m_EventSelectorTab;

  int m_TrackLengthRangeMin;
  int m_TrackLengthRangeMax;

  int m_SequenceLengthRangeMin;
  int m_SequenceLengthRangeMax;

  double m_ClusteringQualityFactorRangeMin;
  double m_ClusteringQualityFactorRangeMax;

  double m_ComptonQualityFactorRangeMin;
  double m_ComptonQualityFactorRangeMax;

  double m_TrackQualityFactorRangeMin;
  double m_TrackQualityFactorRangeMax;

  double m_FirstEnergyRangeMin;
  double m_FirstEnergyRangeMax;

  double m_SecondEnergyRangeMin;
  double m_SecondEnergyRangeMax;

  double m_ThirdEnergyRangeMin;
  double m_ThirdEnergyRangeMax;

  double m_FourthEnergyRangeMin;
  double m_FourthEnergyRangeMax;

  double m_EnergyRangeGammaMin;
  double m_EnergyRangeGammaMax;

  double m_EnergyRangeElectronMin;
  double m_EnergyRangeElectronMax;

  double m_ComptonAngleRangeMin;
  double m_ComptonAngleRangeMax;

  double m_ThetaDeviationMax;

  double m_FirstDistanceRangeMin;
  double m_FirstDistanceRangeMax;

  double m_DistanceRangeMin;
  double m_DistanceRangeMax;

  double m_TimeWalkRangeMin;
  double m_TimeWalkRangeMax;

  double m_CoincidenceWindowRangeMin;
  double m_CoincidenceWindowRangeMax;

  double m_OpeningAnglePairMin;
  double m_OpeningAnglePairMax;

  double m_InitialEnergyDepositPairMin;
  double m_InitialEnergyDepositPairMax;

  int m_EventTypeCompton;
  int m_EventTypeDoubleCompton;
  int m_EventTypeComptonNotTracked;
  int m_EventTypeComptonTracked;
  int m_EventTypePair;
  int m_EventTypePhoto;
  int m_EventTypeUnidentifiable;
  int m_EventTypeDecay;

  int m_FlaggedAsBad;

  vector<MString> m_ExcludedDetectors;

  int m_EHCType;
  double m_EHCProbability;
  MString m_EHCComptonProbabilityFileName;
  MString m_EHCPairProbabilityFileName;
  MVector m_EHCEarthPosition;
  double m_EHCAngle;

  bool m_SourceUsePointSource;
  int m_SourceCoordinates;
  double m_SourcePhi;
  double m_SourceTheta;
  double m_SourceLongitude;
  double m_SourceLatitude;
  double m_SourceX;
  double m_SourceY; 
  double m_SourceZ;
  double m_SourceARMMin;
  double m_SourceARMMax;
  double m_SourceSPDMin;
  double m_SourceSPDMax;

  bool m_BeamUse;
  double m_BeamStartX;
  double m_BeamStartY; 
  double m_BeamStartZ;
  double m_BeamFocalSpotX;
  double m_BeamFocalSpotY; 
  double m_BeamFocalSpotZ;
  double m_BeamRadius;
  double m_BeamDepth;


  //! The special mode flag
  bool m_SpecialMode;


#ifdef ___CINT___
 public:
  ClassDef(MSettingsEventSelections, 0) // no description
#endif

};

#endif


////////////////////////////////////////////////////////////////////////////////
