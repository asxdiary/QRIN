// Name:     ObjectDb.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ObjectDb_hpp
#define ASX_ObjectDb_hpp

namespace aiDb {
//Forword decalaration
class ObjectDb;
};

#include <unordered_map>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "UtilDate.hpp"
#include "Model.hpp"
#include "Dated.hpp"
#include "Summarizable.hpp"
#include "DbAccount.hpp"
#include "DoubleDbAccount.hpp"
#include "StringDbAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiDb {

class ObjectDb : public Model , public Dated, public Summarizable  {

/**
 * 	Class Description:
 * 		This class is used to store a mapping from DbAccounts to corresponding
 * 		values (string, double, etc)
 * 
 * 	Assumptions:
 * 		There is no provision right to differentiate between missing values
 * 		and unavailable values; for instance, if R&D account is unavailable
 * 		we cannot ascertain if the firm did not report R&D expense or the
 * 		information is not available at all
 * 
 * 	Objects: (P=Parent; NO=Not Ownwed; O=Owned)
 * 		NO dbobj : object whose information is being stored
 * 		<decommissioned> NO end_d (d) : ending date
 * 		<decommissioned> NO dh_d     : availability date
 * 		<decommissioned> NO start_d  : starting date
 * 		ddbam: DoubleDbAccount->double (double attributes)
 * 		sdbam: StringDbAccount->string (string attributes)
 * 
 * 	Ownership:
 * 		Indicated above
 * 
 */

private:
/**	Data Members */
	Object* _dbobj;
	unordered_map<DoubleDbAccount*,double>* _ddbam;
	unordered_map<StringDbAccount*,string>* _sdbam;

protected: 

	/** Protected Constructors */
	ObjectDb();
	ObjectDb(const ObjectDb* ptr);
	ObjectDb(const ObjectDb& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init(Object* dbobj, UtilDate* end_d, UtilDate* dh, UtilDate* start_d);
	void init_ObjectDb(Object* dbobj, UtilDate* end_d, UtilDate* dh, UtilDate* start_d);
	virtual void init_dbobj(Object* obj);
	virtual void init_ddbam();
	virtual void init_sdbam();

	//Destructor
	virtual ~ObjectDb(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_ObjectDb(); 
	virtual void cleanMem_dbobj();
	virtual void cleanMem_ddbam();
	virtual void cleanMem_sdbam();

	/** Public Data Access Functions */
	virtual Object* dbobj();
	virtual UtilDate* end_d();
	virtual UtilDate* dh();
	virtual UtilDate* start_d();
	virtual unordered_map<DoubleDbAccount*,double>* ddbam();
	virtual unordered_map<StringDbAccount*,string>* sdbam();

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_ObjectDb(string fname);
	virtual void fscan(string fname);
	void fscan_ObjectDb(string fname);

	//Reset
	virtual void reset();
	void reset_ObjectDb();


	/** ------ Static Functions ----------------*/

	static ObjectDb* instance(Object* dbobj, UtilDate* end_d, UtilDate* dh, UtilDate* start_d);

	static ObjectDb* instance_fscan(string fname);

   static void isContiguous(vector<ObjectDb*>* odbv, int& xval);

	virtual ObjectDb* instantiate(Object* dbobj, UtilDate* end_d, UtilDate* dh, UtilDate* start_d);

	/** ----------  Non-standard functions start here -----------*/

   /** Checks
    * - dbobj matches (if non-NULL)
    * - end_d matches (if non-NULL)
    * - dh is on or before _dh
    *
    * If all goes well, the account value is returned in x and xval is set to 0.
    * Otherwise xval is set to non-zero value and x is left unaltered */
   virtual double ddba(Object* dbobj, UtilDate* end_d, UtilDate* dh,
                        DoubleDbAccount* dba, int& xval);
   virtual string sdba(Object* dbobj, UtilDate* end_d, UtilDate* dh,
                       StringDbAccount* dba, int& xval);

   /** If xval==0 then x is added to ddbam */
   virtual void add_ddba(DoubleDbAccount* dba, double x, int xval=0);
   virtual void add_sdba(StringDbAccount* dba, string x, int xval=0);

   virtual void summary(list<unordered_map<string,string>*>*& L, set<string>* headerS=NULL);

   /** Return the set of all DbAccounts */
   virtual set<DbAccount*>* dbaS(set<DbAccount*>* S=NULL);

   virtual void chk_dbobj(Object* dbobj, int& xval);
   virtual void chk_end_d(UtilDate* end_d, int& xval);
   virtual void chk_dh(UtilDate* dh, int& xval);

   /** Create a copy of the current object */
   virtual ObjectDb* clone();

};

};

#endif

