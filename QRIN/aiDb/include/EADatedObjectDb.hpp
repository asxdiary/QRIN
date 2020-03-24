// Name:     EADatedObjectDb.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_EADatedObjectDb_hpp
#define ASX_EADatedObjectDb_hpp

namespace aiDb {
//Forword decalaration
class EADatedObjectDb;
};

#include <vector>
#include <map>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "ADatedObjectDb.hpp"
#include "Model.hpp"
#include "Summarizable.hpp"
#include "DoubleDbAccount.hpp"
#include "Matrix.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiMath;

//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiDb {

class EADatedObjectDb : public Model, public Summarizable  {

/**
 * 	Class Description:
 * 		This class is used to represent dated ADatedObjectDb objects
 * 		indexed by ending dates
 * 
 * 	Assumptions:
 * 		There is a unique start date for each end date, and vice versa
 * 
 * 	Objects: (P=Parent; NO=Not Ownwed; O=Owned)
 * 		NO dbobj: object whose information is being stored
 * 		O aodbm: Date->ADatedObjectDb
 * 		O dh2end_dSm: map[int->set<int>]
 * 	   dh2end_dSm stores a mapping from dh to the set of end dates;
 * 	   dh2end_dSm is an inverse mapping that can be used to answer
 * 	   certain queries efficiently
 *
 * 		O dh2start_dSm: map[int->set<int>]
 * 		counterpart to dh2end_dSm
 *
 * 	   O start2end_dm: map[start_d -> end_d]
 * 	   O end2start_dm: map[end_d -> start_d]
 * 	   Note that the existence of these maps implies that there 
 * 	   will be a unique start date for each end date, and vice versa
 * 	   (cf. assumptions above)
 * 
 * 	Ownership:
 * 		Indicated above
 * 
 */

private:
/**	Data Members */
	Object* _dbobj;
	unordered_map<UtilDate*,ADatedObjectDb*>* _aodbm;
   map<int,set<int>*>* _dh2end_dSm;
   map<int,set<int>*>* _dh2start_dSm;
	unordered_map<int,int>* _start2end_dm;
	unordered_map<int,int>* _end2start_dm;

protected: 

	/** Protected Constructors */
	EADatedObjectDb();
	EADatedObjectDb(const EADatedObjectDb* ptr);
	EADatedObjectDb(const EADatedObjectDb& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init(Object* dbobj);
	void init_EADatedObjectDb(Object* dbobj);
	virtual void init_dbobj(Object* dbobj);
	virtual void init_aodbm();
	virtual void init_dh2end_dSm();
	virtual void init_dh2start_dSm();
	virtual void init_start2end_dm();
	virtual void init_end2start_dm();

	//Destructor
	virtual ~EADatedObjectDb(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_EADatedObjectDb(); 
	virtual void cleanMem_dbobj();
	virtual void cleanMem_aodbm();
   virtual void cleanMem_dh2end_dSm();
   virtual void cleanMem_dh2start_dSm();
   virtual void cleanMem_start2end_dm();
   virtual void cleanMem_end2start_dm();

   /** Public Data Access Functions */
   virtual Object* dbobj();
   virtual unordered_map<UtilDate*,ADatedObjectDb*>* aodbm();
   virtual map<int,set<int>*>* dh2end_dSm();
   virtual map<int,set<int>*>* dh2start_dSm();
   virtual unordered_map<int,int>* start2end_dm();
   virtual unordered_map<int,int>* end2start_dm();

   /** Public data Set functions */

   //Access classname dynamically 
   virtual string className() const;

   //For error message handling
   void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_EADatedObjectDb(string fname);
	virtual void fscan(string fname);
	void fscan_EADatedObjectDb(string fname);

	//Reset
	virtual void reset();
	void reset_EADatedObjectDb();


	/** ------ Static Functions ----------------*/

	static EADatedObjectDb* instance(Object* dbobj);

	static EADatedObjectDb* instance_fscan(string fname);

	virtual EADatedObjectDb* instantiate(Object* dbobj);

	/** ----------  Non-standard functions start here -----------*/

   virtual void add_odb(ObjectDb* odb);

   virtual ADatedObjectDb* create_aodb(UtilDate* end_d);

   virtual ADatedObjectDb* aodb(Object* dbobj, UtilDate* end_d, 
                                int& xval);

   virtual ObjectDb* odb(Object* dbobj, UtilDate* end_d, UtilDate* dh, 
                          int& xval);

   /** This function finds the ObjectDb* that satisfies the following assuming
    * end_flag=true:
    * Conditions: 
    * 1. odb has availability date in [dh_floor, dh]  
    * 2. odb has end_date in [dstar_floor, dstar] 
    *
    * odbs are scanned in reverse chronological order to satisfy (1) above;
    * ties on (2) are broked by choosing the end_date closest to dstar 
    *
    * the floor dates can be NULL in which case they are ignored */
   virtual ObjectDb* odb_closest_le(Object* dbobj, 
                                    UtilDate* dh, UtilDate* dh_floor,
                                    UtilDate* dstar, UtilDate* dstar_floor,
                                    bool end_flag, int& xval);

   virtual double ddba(Object* dbobj, UtilDate* end_d, UtilDate* dh,
                        DoubleDbAccount* dba, int& xval);

   virtual string sdba(Object* dbobj, UtilDate* end_d, UtilDate* dh,
                       StringDbAccount* dba, int& xval);

   virtual void summary(list<unordered_map<string,string>*>*& L, set<string>* headerS=NULL);

   virtual ObjectDb* agg(Object* dbobj, vector<UtilDate*>* end_dv, UtilDate* dh, int& xval);

   virtual vector<ObjectDb*>* odbv(Object* dbobj, vector<UtilDate*>* end_dv, UtilDate* dh, 
                                   int& xval);

   virtual void compute(Object* dbobj, vector<UtilDate*>* end_dv, UtilDate* dh, 
                        DbAccount* dba, int& xval);

   virtual void chk_dbobj(Object* dbobj, int& xval);

   virtual ObjectDb* obsolete_interpolate(Object* dbobj, UtilDate* end_d, 
                                 UtilDate* dh, UtilDate* start_d, int& xval);

   virtual ObjectDb* interpolate(Object* dbobj, UtilDate* end_d, 
                                 UtilDate* dh, UtilDate* start_d, int& xval);

   /** This function summarizes the accounts in dbaa in the form of a matrix
    * The rows are named as <object.id>.<start_date>.<end_date>.<availability_date>
    * The columns are named as per dbaa */
   virtual Matrix* ddba_summary(Object* dbobj,
                                int m, DoubleDbAccount** dbaa, 
                                Matrix*& xvalM,
                                bool strict_filter=false, Matrix* Delta=NULL);

};

};

#endif

