// Name:     R_DoubleDbAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_R_DoubleDbAccount_hpp
#define ASX_R_DoubleDbAccount_hpp

namespace aiDbAccounts {
//Forword decalaration
class R_DoubleDbAccount;
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

class R_DoubleDbAccount : public DoubleDbAccount  {

/**
 * 	Class Description:
 * 		This account can be used to model ratios such as Gross Margin, Net Margin,
 * 		etc. It allows for the possibility of averaging the denominator, and
 * 		also of complenting the ratio (for instance, converting COGS/Revenue
 * 		into Gross Margin)
 * 
 * 	Assumptions:
 * 		None
 * 
 * 	Objects:
 * 		numer_dba : accounts associated with numerator
 * 		denom_dba: accounts associated with denominator
 *       denom_avg_flag: a boolean flag indicating if the denominator
 *       should be averaged
 *       reverse_flag: a boolean flag indicating if the 1-ratio should
 *       be used instead
 * 
 * 	Ownership:
 * 		All objects except the following are owned:
 * 		numer_dba, denom_dba
 * 
 */

private:
/**	Data Members */
	DoubleDbAccount* _numer_dba;
	DoubleDbAccount* _denom_dba;
	bool _denom_avg_flag;
	bool _reverse_flag;

protected: 

	/** Protected Constructors */
	R_DoubleDbAccount();
	R_DoubleDbAccount(const R_DoubleDbAccount* ptr);
	R_DoubleDbAccount(const R_DoubleDbAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init(DoubleDbAccount* numer_dba, DoubleDbAccount* denom_dba, bool denom_avg_flag, bool reverse_flag);
	void init_R_DoubleDbAccount(DoubleDbAccount* numer_dba, DoubleDbAccount* denom_dba, bool denom_avg_flag, bool reverse_flag);
	virtual void init_numer_dba(DoubleDbAccount* obj);
	virtual void init_denom_dba(DoubleDbAccount* obj);
	virtual void init_denom_avg_flag(bool obj);
	virtual void init_reverse_flag(bool obj);

	//Destructor
	virtual ~R_DoubleDbAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_R_DoubleDbAccount(); 
	virtual void cleanMem_numer_dba();
	virtual void cleanMem_denom_dba();

	/** Public Data Access Functions */
	virtual DoubleDbAccount* numer_dba();
	virtual DoubleDbAccount* denom_dba();
	virtual bool denom_avg_flag();
	virtual bool reverse_flag();

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_R_DoubleDbAccount(string fname);
	virtual void fscan(string fname);
	void fscan_R_DoubleDbAccount(string fname);

	//Reset
	virtual void reset();
	void reset_R_DoubleDbAccount();


	/** ------ Static Functions ----------------*/

	static R_DoubleDbAccount* instance(DoubleDbAccount* numer_dba, DoubleDbAccount* denom_dba, bool denom_avg_flag, bool reverse_flag);

	static R_DoubleDbAccount* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   virtual void compute(vector<ObjectDb*>* odbv, int& xval);

};

};

#endif

