// Name:     GenericDoubleDbAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_GenericDoubleDbAccount_hpp
#define ASX_GenericDoubleDbAccount_hpp

namespace aiDbAccounts {
//Forword decalaration
class GenericDoubleDbAccount;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DoubleDbAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiDbAccounts;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiDbAccounts {

class GenericDoubleDbAccount : public DoubleDbAccount  {

/**
 * 	Class Description:
 * 		This account is used to create dynamic DoubleDbAccounts 
 * 
 * 	Assumptions:
 * 		None
 * 
 * 	Objects:
 * 		None
 * 
 * 	Ownership:
 * 		All objects owned
 * 
 */

private:
/**	Data Members */

protected: 

	/** Protected Constructors */
	GenericDoubleDbAccount();
	GenericDoubleDbAccount(const GenericDoubleDbAccount* ptr);
	GenericDoubleDbAccount(const GenericDoubleDbAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init(string id);
	void init_GenericDoubleDbAccount(string id);

	//Destructor
	virtual ~GenericDoubleDbAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_GenericDoubleDbAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_GenericDoubleDbAccount(string fname);
	virtual void fscan(string fname);
	void fscan_GenericDoubleDbAccount(string fname);

	//Reset
	virtual void reset();
	void reset_GenericDoubleDbAccount();


	/** ------ Static Functions ----------------*/

	static GenericDoubleDbAccount* instance(string id);

	static GenericDoubleDbAccount* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

