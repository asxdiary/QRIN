// Name:     G_EPSAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_G_EPSAccount_hpp
#define ASX_G_EPSAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class G_EPSAccount;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "G_DoubleDbAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiAcctVars;
using namespace aiDb;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiAcctVars {

class G_EPSAccount : public G_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: EPS1/EPS0 - 1
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
	G_EPSAccount();
	G_EPSAccount(const G_EPSAccount* ptr);
	G_EPSAccount(const G_EPSAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init(bool geom_flag);
	void init_G_EPSAccount();

	//Destructor
	virtual ~G_EPSAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_G_EPSAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_G_EPSAccount(string fname);
	virtual void fscan(string fname);
	void fscan_G_EPSAccount(string fname);

	//Reset
	virtual void reset();
	void reset_G_EPSAccount();


	/** ------ Static Functions ----------------*/

	static G_EPSAccount* instance(bool geom_flag=true);

	static G_EPSAccount* instance_fscan(string fname);

   static G_EPSAccount* __ptr_G_EPSAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

