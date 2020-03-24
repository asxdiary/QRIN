# Look at and if necessary edit the following files:
# - ../Makefiles/Makefile.location
# - Makefile.aiForecastUtils

###############################################################################

export CoinDir := $(shell cd ..; pwd)
export MakefileDir := $(CoinDir)/Makefiles
include ${MakefileDir}/Makefile.coin
include ${MakefileDir}/Makefile.location

###############################################################################

.DELETE_ON_ERROR:

.PHONY: default install clean library unitTest libdepend libaiForecastUtils doc

default: install
libaiForecastUtils:  library

libdepend:

install library: libdepend
	${MAKE} -f Makefile.aiForecastUtils $@

doc:
	doxygen $(MakefileDir)/doxygen.conf

unitTest: install
	(cd Test && ${MAKE} unitTest)

clean: 
	@rm -rf Junk
	@rm -rf $(UNAME)*
	@rm -rf dep
	@rm -rf Test/Junk
	@rm -rf Test/$(UNAME)*
	@rm -rf Test/dep
	@rm -f unitTest
