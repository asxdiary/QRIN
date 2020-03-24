// Name:     G_DoubleDbAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_G_DoubleDbAccount_hpp
#define ASX_G_DoubleDbAccount_hpp

namespace aiDbAccounts {
//Forword decalaration
class G_DoubleDbAccount;
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

class G_DoubleDbAccount : public DoubleDbAccount  {

/**
 * 	Class Description:
 * 		This class contains growth accounts derived from an underlying
 * 		base account
 * 
 * 	Assumptions:
 * 		It is assumed that the base account has already been computed
 *       We use geometric (artithmetic) growth estimates if geom_flag is true (false)
 *       If the denominator is zero or negative then xval is set to 1 (i.e. failure)
 *       If the numerator is negative then xval is set to 1
 * 
 * 	Objects:
 * 		bdba: base account
 * 		geom_flag: boolean flag indicating whether goemtric growth rates should be
 * 		used
 * 
 * 	Ownership:
 * 		All objects except bdba owned
 * 
 */

private:
/**	Data Members */
	DoubleDbAccount* _bdba;
	bool _geom_flag;

protected: 

	/** Protected Constructors */
	G_DoubleDbAccount();
	G_DoubleDbAccount(const G_DoubleDbAccount* ptr);
	G_DoubleDbAccount(const G_DoubleDbAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init(DoubleDbAccount* bdba, bool geom_flag);
	void init_G_DoubleDbAccount(DoubleDbAccount* bdba);
	virtual void init_bdba(DoubleDbAccount* bdba);
   virtual void init_geom_flag(bool geom_flag);

	//Destructor
	virtual ~G_DoubleDbAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_G_DoubleDbAccount(); 
	virtual void cleanMem_bdba();

	/** Public Data Access Functions */
	virtual DoubleDbAccount* bdba();
	virtual bool geom_flag();

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_G_DoubleDbAccount(string fname);
	virtual void fscan(string fname);
	void fscan_G_DoubleDbAccount(string fname);

	//Reset
	virtual void reset();
	void reset_G_DoubleDbAccount();


	/** ------ Static Functions ----------------*/

	static G_DoubleDbAccount* instance(DoubleDbAccount* bdba, bool geom_flag);

	static G_DoubleDbAccount* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   virtual double agg_guts(vector<ObjectDb*>* odbv, UtilDate* dh, int& xval);

   virtual void compute(vector<ObjectDb*>* odbv, int& xval);

};

};

#endif

