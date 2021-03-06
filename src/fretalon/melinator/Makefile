#----------------------------------------------------------------
#
#  Makefile for MEGAlib / melinator
#
#  Author: Andreas Zoglauer
#
#----------------------------------------------------------------



#----------------------------------------------------------------
# Definitions:
#

PRG = \
$(BN)/melinator

MOBJS = \
$(LB)/MMelinatorMain.o

GOBJS = \
$(LB)/MGUIMainMelinator.o \
$(LB)/MGUIEReadOutElement.o \
$(LB)/MGUIEReadOutElementView.o \
$(LB)/MGUIEReadOutUnitsCanvas.o \
$(LB)/MGUILoadCalibration.o \
$(LB)/MInterfaceMelinator.o \

LOBJS = \
$(LB)/MSettingsMelinator.o \
$(LB)/MMelinator.o \

SGOBJ = $(LB)/libMelinatorGui.$(DLL)
SLOBJ = $(LB)/libMelinator.$(DLL)

#----------------------------------------------------------------
# Commands:
#

all: $(PRG)

lib: $(SLOBJ) 

link:
	@$(LINK) $(shell pwd)/inc/*.h $(IN)
	@rm -f $(IN)/LinkDef.h

clean:
	@rm -f src/*~
	@rm -f src/\#*
	@rm -f inc/*~
	@rm -f inc/\#*
	@rm -f *~
	@rm -f \#*
	@rm -f $(PRG)
	@rm -f $(MOBJS) $(GOBJS) $(LOBJS) $(SGOBJ) $(SLOBJ)


#----------------------------------------------------------------
# Dependencies:
#

$(MOBJS): $(LB)/%.o: src/%.cxx inc/%.h
	@echo "Compiling $(subst src/,,$<) ..."
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(SLOBJ): $(LOBJS)
	@echo "Linking $(subst $(LB)/,,$@) ..."
	@$(LD) $(LDFLAGS) $(SOFLAGS) $(LOBJS) $(GLIBS) $(LIBS) -o $(SLOBJ)

$(SGOBJ): $(GOBJS) $(LOBJS)
	@echo "Linking $(subst $(LB)/,,$@) ..."
	@$(LD) $(LDFLAGS) $(SOFLAGS) $(GOBJS) $(GLIBS) $(LIBS) -o $(SGOBJ)

$(LOBJS): $(LB)/%.o: src/%.cxx inc/%.h
	@echo "Compiling $(subst src/,,$<) ..."
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(GOBJS): $(LB)/%.o: src/%.cxx inc/%.h
	@echo "Compiling $(subst src/,,$<) ..."
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(PRG): $(SGOBJ) $(SLOBJ) $(MOBJS)
	@echo "Linking $(subst $(BN)/,,$@) ..."
	$(LD) $(LDFLAGS) $(MOBJS) $(FRETALONLIBS) $(GLIBS) $(LIBS) -o $(PRG)

#
#----------------------------------------------------------------



