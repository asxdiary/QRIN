# The location of the customized Makefiles
export CoinDir = $(shell cd ../..; pwd)
export MakefileDir := $(CoinDir)/Makefiles
include ${MakefileDir}/Makefile.coin
include ${MakefileDir}/Makefile.location

###############################################################################

.DELETE_ON_ERROR:

.PHONY: default ws clean doc libdepend

default: ws

ws: libdepend
	${MAKE} -f Makefile.ws ws

libdepend:
	(cd ../../aiExt && ${MAKE} install)
	(cd ../../aiUtils && ${MAKE} install)
	(cd ../../aiMath && ${MAKE} install)
	(cd ../../aiAcctDbUtils && ${MAKE} install)

clean :
	rm -rf Junk
	rm -rf dep
	rm -rf $(UNAME)*
