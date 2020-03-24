// Name:     Db.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_Db_hpp
#define ASX_Db_hpp

namespace aiDb {
//Forword decalaration
class Db;
};

#include <unordered_map>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Model.hpp"
#include "Summarizable.hpp"
#include "EADatedObjectDb.hpp"
#include "UtilDate.hpp"
#include "DoubleDbAccount.hpp"
#include "Matrix.hpp"
#include "ObjectUniverse.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiMath;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiDb {

class Db : public Model, public Summarizable  {

/**
 * 	Class Description:
 * 		This class is used to represent arbitrary databases using
 * 		EADatedObjectDb as the underlying unit
 * 
 * 	Assumptions:
 * 		None
 * 
 * 	Objects: (P=Parent; NO=Not Ownwed; O=Owned)
 * 		O eaodbm: Object->EADatedObjectDb;
 * 
 * 	Ownership:
 * 		Indicated above
 * 
 */

private:
/**	Data Members */
	unordered_map<Object*,EADatedObjectDb*>* _eaodbm;

protected: 

	/** Protected Constructors */
	Db();
	Db(const Db* ptr);
	Db(const Db& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_Db();
	virtual void init_eaodbm();

	//Destructor
	virtual ~Db(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_Db(); 
	virtual void cleanMem_eaodbm();

	/** Public Data Access Functions */
	virtual unordered_map<Object*,EADatedObjectDb*>* eaodbm();

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_Db(string fname);
	virtual void fscan(string fname);
	void fscan_Db(string fname);

	//Reset
	virtual void reset();
	void reset_Db();


	/** ------ Static Functions ----------------*/

	static Db* instance();

	static Db* instance_fscan(string fname);

	virtual Db* instantiate();

	/** ----------  Non-standard functions start here -----------*/

   virtual void add_odb(ObjectDb* odb);

   virtual EADatedObjectDb* eaodb(Object* dbobj, int& xval);

   virtual ObjectDb* odb(Object* dbobj, UtilDate* end_d, UtilDate* dh, 
                          int& xval);

   virtual ObjectDb* odb_closest_le(Object* dbobj, 
                                    UtilDate* dh, UtilDate* dh_floor,
                                    UtilDate* dstar, UtilDate* dstar_floor,
                                    bool end_flag, int& xval);

   virtual double ddba(Object* dbobj, UtilDate* end_d, UtilDate* dh,
                        DoubleDbAccount* dba, int& xval);

   virtual string sdba(Object* dbobj, UtilDate* end_d, UtilDate* dh,
                       StringDbAccount* dba, int& xval);

   /** This function returns a matrix of double attributes wherein the
    * rows are indexed by oba and columns are indexed by dbaa
    *
    * If strict_filter=true then rows for which any of the attribute is
    * missing are dropped */
   virtual Matrix* ddba_closest_le(int n, Object** oba,
                                   UtilDate* dh, UtilDate* dh_floor,
                                   UtilDate* dstar, UtilDate* dstar_floor,
                                   bool end_flag, 
                                   int m, DoubleDbAccount** dbaa, 
                                   Matrix*& xvalM,
                                   bool strict_filter=false, Matrix* Delta=NULL);

   virtual Matrix* ddba_closest_le(list<Object*>* objL,
                                   UtilDate* dh, UtilDate* dh_floor,
                                   UtilDate* dstar, UtilDate* dstar_floor,
                                   bool end_flag, 
                                   list<DoubleDbAccount*>* dbaL,
                                   Matrix*& xvalM,
                                   bool strict_filter=false, Matrix* Delta=NULL);

   virtual Matrix* ddba_closest_le(ObjectUniverse* univ,
                                   UtilDate* dh, UtilDate* dh_floor,
                                   UtilDate* dstar, UtilDate* dstar_floor,
                                   bool end_flag, 
                                   list<DoubleDbAccount*>* dbaL,
                                   Matrix*& xvalM,
                                   bool strict_filter=false, Matrix* Delta=NULL);



   /** cf. EADatedObjectDb::ddba_summary */
   virtual Matrix* ddba_summary(int n, Object** oba,
                                int m, DoubleDbAccount** dbaa, 
                                Matrix*& xvalM,
                                Matrix*& xsm,
                                bool strict_filter=false, Matrix* Delta=NULL);

   virtual Matrix* ddba_summary(list<Object*>* objL, 
                                list<DoubleDbAccount*>* dbaL,
                                Matrix*& xvalM,
                                Matrix*& xsm,
                                bool strict_filter=false, Matrix* Delta=NULL);

   virtual Matrix* ddba_summary(ObjectUniverse* univ, 
                                list<DoubleDbAccount*>* dbaL,
                                Matrix*& xvalM,
                                Matrix*& xsm,
                                bool strict_filter=false, Matrix* Delta=NULL);



   virtual void summary(list<unordered_map<string,string>*>*& L, set<string>* headerS=NULL);

   virtual EADatedObjectDb* create_eaodb(Object* dbobj);

   virtual Db* agg(vector<UtilDate*>* end_dv, UtilDate* dh, int& xval, Db* db=NULL);

   /** Function:
    *    1. Create a new database db (if db!=NULL)
    *    2. For each object obj in db1:
    *       2a. odb1 = db1->odb(obj, end_d, dh)
    *       2b. odb2 = db2->odb(obj, end_d, dh)
    *       2c. if(odb1!=NULL) odb = odb1;
    *           else if(odb2!=NULL) odb = odb2;
    *       2d. if(odb!=NULL) db->add_odb(odb->clone())
    *    */
   virtual Db* merge(Db* db2, UtilDate* end_d, UtilDate* dh, int& xval, Db* db=NULL);
   virtual Db* merge(Db* db2, list<UtilDate*>* end_dL, UtilDate* dh, int& xval, 
                     Db* db=NULL);

   virtual void compute(vector<UtilDate*>* end_dv, UtilDate* dh, 
                        DbAccount* dba, int& xval);

   virtual Db* interpolate(UtilDate* end_d, UtilDate* dh, UtilDate* start_d, int& xval,
                                 Db* db=NULL);

   virtual ObjectUniverse* objuniv(ObjectUniverse* univ);

};

};

#endif

