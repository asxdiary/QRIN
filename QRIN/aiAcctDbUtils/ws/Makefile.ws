# Select optimization (-O or -g). -O will be automatically bumped up to the 
# highest level of optimization the compiler supports. If want something in
# between then specify the exact level you want, e.g., -O1 or -O2

#OptLevel := -O
OptLevel := -g

##############################################################################
# You should not need to edit below this line.
##############################################################################
# The location of the customized Makefiles
# also inherited from the parent Makefile
export CoinDir = $(shell cd ../..; pwd)
export MakefileDir := $(CoinDir)/Makefiles
include ${MakefileDir}/Makefile.coin
include ${MakefileDir}/Makefile.location

IncDir := 
IncDir += ${CoinIncDir}
IncDir += ${MosekIncDir}
IncDir += ${lapackIncDir}
IncDir += ./include

LibDir := 
LibDir += ${CoinLibDir}
LibDir += ${MosekLibDir}
LibDir += ${lapackLibDir}

LibName := 
LibName += ${aiAcctDbUtilsLibName}
LibName += ${aiFinLibName}
LibName += ${aiAcctDbLibName}
LibName += ${aiAcctFieldsLibName}
LibName += ${aiDbAccountsLibName}
LibName += ${aiDbLibName}
LibName += ${aiDbUtilsLibName}
LibName += ${aiUtilsLibName}
LibName += ${aiMathLibName}
LibName += ${aiExtLibName}
LibName += ${MosekLibName}
LibName += ${lapackLibName}

Define :=
Define += ${CoinDefine}
Define += ${MosekDefine}
Define += ${lapackDefine}

##############################################################################

CXXFLAGS += $(OPTFLAG)

EXSRC :=
EXSRC += ws.cpp
EXSRC += TestCompustatQGen.cpp
EXSRC += TestSavanetFYGen.cpp

###############################################################################

space:= $(empty) $(empty)
OptVersion := $(subst $(space),_,$(OptLevel))

TARGETDIR := $(UNAME)$(OptVersion)
DEPDIR := dep

VPATH := . : include : Junk : ${TARGETDIR} : ${DEPDIR}

#########################################################################

CXXFLAGS += $(addprefix -I,$(IncDir))
CXXFLAGS += $(addprefix -D,$(Define))

LIBDIRS := ${LibDir}
LIBS    := ${LibName}

LDFLAGS := $(addprefix -L,$(LIBDIRS))
LDFLAGS += $(call ifprefix,$(SHLINKPREFIX),$(LIBDIRS))
LDFLAGS += $(patsubst lib%,-l%,$(basename $(LIBS)))

###############################################################################

EXOBJ := $(addprefix $(TARGETDIR)/, $(EXSRC:.cpp=.o))
EXDEP := $(addprefix $(DEPDIR)/, $(EXSRC:.cpp=.d))

###############################################################################
# This one must be right before the rules

include ${MakefileDir}/Makefile.rules

###############################################################################

.DELETE_ON_ERROR:

.PHONY: ws 

ws: $(TARGETDIR)/ws

$(TARGETDIR)/ws: $(EXOBJ)
	@echo ""
	@echo Creating example ws
	@mkdir -p $(TARGETDIR)
	@rm -f $@
	$(CXX) $(CXXFLAGS) -o $@ $(EXOBJ) $(LDFLAGS) $(SYSLD) -lm

###############################################################################

%::
	@mkdir -p Junk
	touch Junk/$(notdir $@)

###############################################################################

-include $(EXDEP)
