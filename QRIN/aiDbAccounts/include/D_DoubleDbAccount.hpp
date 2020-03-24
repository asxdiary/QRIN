// Name:     D_DoubleDbAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_DoubleDbAccount_hpp
#define ASX_D_DoubleDbAccount_hpp

namespace aiDbAccounts {
//Forword decalaration
class D_DoubleDbAccount;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DoubleDbAccount.hpp"
#include "ObjectDb.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiDbAccounts {

class D_DoubleDbAccount : public DoubleDbAccount  {

/**
 * 	Class Description:
 * 		This class contains difference accounts derived from an underlying
 * 		base account
 * 
 * 	Assumptions:
 * 		It is assumed that the base account has already been computed
 * 
 * 	Objects:
 * 		bdba: base account
 * 
 * 	Ownership:
 * 		All objects except bdba owned
 * 
 */

private:
/**	Data Members */
	DoubleDbAccount* _bdba;

protected: 

	/** Protected Constructors */
	D_DoubleDbAccount();
	D_DoubleDbAccount(const D_DoubleDbAccount* ptr);
	D_DoubleDbAccount(const D_DoubleDbAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init(DoubleDbAccount* bdba);
	void init_D_DoubleDbAccount(DoubleDbAccount* bdba);
	virtual void init_bdba(DoubleDbAccount* bdba);

	//Destructor
	virtual ~D_DoubleDbAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_D_DoubleDbAccount(); 
	virtual void cleanMem_bdba();

	/** Public Data Access Functions */
	virtual DoubleDbAccount* bdba();

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_D_DoubleDbAccount(string fname);
	virtual void fscan(string fname);
	void fscan_D_DoubleDbAccount(string fname);

	//Reset
	virtual void reset();
	void reset_D_DoubleDbAccount();


	/** ------ Static Functions ----------------*/

	static D_DoubleDbAccount* instance(DoubleDbAccount* bdba);

	static D_DoubleDbAccount* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   virtual double agg_guts(vector<ObjectDb*>* odbv, UtilDate* dh, int& xval);

   virtual void compute(vector<ObjectDb*>* odbv, int& xval);

};

};

#endif

