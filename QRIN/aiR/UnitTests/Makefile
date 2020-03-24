# The location of the customized Makefiles
export CoinDir = $(shell cd ../..; pwd)
export MakefileDir := $(CoinDir)/Makefiles
include ${MakefileDir}/Makefile.coin
include ${MakefileDir}/Makefile.location

###############################################################################

.DELETE_ON_ERROR:

.PHONY: default UnitTests clean doc libdepend

default: UnitTests

UnitTests: libdepend
	${MAKE} -f Makefile.UnitTests UnitTests

libdepend:
	(cd ../../aiExt && ${MAKE} install)
	(cd ../../aiUtils && ${MAKE} install)
	(cd ../../aiMath && ${MAKE} install)
	(cd ../../aiMathUtils && ${MAKE} install)
	(cd ../../aiStat && ${MAKE} install)
	(cd ../../aiStatUtils && ${MAKE} install)
	(cd ../../aiR && ${MAKE} install)

clean :
	rm -rf Junk
	rm -rf dep
	rm -rf $(UNAME)*
