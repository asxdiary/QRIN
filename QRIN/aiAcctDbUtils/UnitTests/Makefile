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
	(cd ../../aiDb && ${MAKE} install)
	(cd ../../aiDbUtils && ${MAKE} install)
	(cd ../../aiAcctDb && ${MAKE} install)
	(cd ../../aiAcctFields && ${MAKE} install)
	(cd ../../aiAcctVars && ${MAKE} install)
	(cd ../../aiFin && ${MAKE} install)
	(cd ../../aiAcctDbUtils && ${MAKE} install)

clean :
	rm -rf Junk
	rm -rf dep
	rm -rf $(UNAME)*
