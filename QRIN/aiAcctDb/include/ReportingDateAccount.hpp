// Name:     ReportingDateAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ReportingDateAccount_hpp
#define ASX_ReportingDateAccount_hpp

namespace aiAcctDbs {
//Forword decalaration
class ReportingDateAccount;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DateAccount.hpp"
#include "ObjectDb.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiAcctDbs;
using namespace aiAcctDbs;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiAcctDbs {

class ReportingDateAccount : public DateAccount  {

/**
 * 	Class Description:
 * 		Reporting Date Account
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
	ReportingDateAccount();
	ReportingDateAccount(const ReportingDateAccount* ptr);
	ReportingDateAccount(const ReportingDateAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_ReportingDateAccount();

	//Destructor
	virtual ~ReportingDateAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_ReportingDateAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_ReportingDateAccount(string fname);
	virtual void fscan(string fname);
	void fscan_ReportingDateAccount(string fname);

	//Reset
	virtual void reset();
	void reset_ReportingDateAccount();


	/** ------ Static Functions ----------------*/

	static ReportingDateAccount* instance();

	static ReportingDateAccount* instance_fscan(string fname);

   static ReportingDateAccount* __ptr_ReportingDateAccount;

	/** ----------  Non-standard functions start here -----------*/

   virtual void agg(ObjectDb* odb, vector<ObjectDb*>* odbv, UtilDate* dh, int& xval);
   virtual double agg_guts(vector<ObjectDb*>* odbv, UtilDate* dh, int& xval);

};

};

#endif

