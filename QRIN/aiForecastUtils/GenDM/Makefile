# The location of the customized Makefiles
export CoinDir = $(shell cd ../..; pwd)
export MakefileDir := $(CoinDir)/Makefiles
include ${MakefileDir}/Makefile.coin
include ${MakefileDir}/Makefile.location

###############################################################################

.DELETE_ON_ERROR:

.PHONY: default GenDM clean doc libdepend

default: GenDM

GenDM: libdepend
	${MAKE} -f Makefile.GenDM GenDM

libdepend:
	(cd ../../aiExt && ${MAKE} install)
	(cd ../../aiUtils && ${MAKE} install)
	(cd ../../aiMath && ${MAKE} install)
	(cd ../../aiForecastUtils && ${MAKE} install)

clean :
	rm -rf Junk
	rm -rf dep
	rm -rf $(UNAME)*
