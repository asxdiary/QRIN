// Name:     GICSAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_GICSAccount_hpp
#define ASX_GICSAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class GICSAccount;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DoubleDbAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;


//Parameters/////////////////////////////
#define GICS_Sector_ENE 10
#define GICS_Sector_MAT 15
#define GICS_Sector_IND 20
#define GICS_Sector_CDI 25
#define GICS_Sector_CST 30
#define GICS_Sector_HLC 35
#define GICS_Sector_FIN 40
#define GICS_Sector_ITC 45
#define GICS_Sector_TEL 50
#define GICS_Sector_UTI 55
#define GICS_Sector_REIT 60

#define GICS_SUBIND_BIOTECH 35201010
#define GICS_SUBIND_PHARMA 35202010
#define GICS_SUBIND_OGEP 10102020
/////////////////////////////////////////

namespace aiAcctFields {

class GICSAccount : public DoubleDbAccount  {

/**
 * 	Class Description:
 * 		This class is used to store GICS information as a double attribute;
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
	GICSAccount();
	GICSAccount(const GICSAccount* ptr);
	GICSAccount(const GICSAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_GICSAccount();

	//Destructor
	virtual ~GICSAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_GICSAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_GICSAccount(string fname);
	virtual void fscan(string fname);
	void fscan_GICSAccount(string fname);

	//Reset
	virtual void reset();
	void reset_GICSAccount();


	/** ------ Static Functions ----------------*/

	static GICSAccount* instance();

	static GICSAccount* instance_fscan(string fname);

   static GICSAccount* __ptr_GICSAccount;

   /** This function returns the first two digits as GICS sector */
   static int gsec(double gcode);

   /** Enumerate the GICS sector */
	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

