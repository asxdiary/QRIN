// Name:     ADatedObjectDb.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ADatedObjectDb_hpp
#define ASX_ADatedObjectDb_hpp

namespace aiDb {
//Forword decalaration
class ADatedObjectDb;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "UtilDate.hpp"
#include "Model.hpp"
#include "Dated.hpp"
#include "Summarizable.hpp"
#include "ObjectDb.hpp"

using namespace std;
using namespace aiDbAccounts;
using namespace aiUtils;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiDb {

class ADatedObjectDb : public Model , public Dated, public Summarizable  {

/**
 * 	Class Description:
 * 		This is a dated collection of ObjectDb based on availability 
 * 		dates (hence "A"DatedObjectDb)
 * 
 * 	Assumptions:
 * 		All ObjectDb's stored here have the same ending date as 
 * 		indicated by end_d
 * 
 * 	Objects: (P=Parent; NO=Not Ownwed; O=Owned)
 * 		NO dbobj: object whose information is being stored
 * 		NO end_d (d): common ending dates of ObjectDb
 * 		O odbm: Date->ObjectDb; a map from availbility dates (dh) to 
 * 		corresponding ObjectDb
 * 		O dhS: set of integers representing the keys of odbm
 * 		derived from the icode function in UtilDate; this is used
 * 		for quick recovery of data
 * 
 * 	Ownership:
 * 		Indicated above
 * 
 */

private:
/**	Data Members */
	Object* _dbobj;
	UtilDate* _end_d;
	unordered_map<UtilDate*,ObjectDb*>* _odbm;
	set<int>* _dhS;

protected: 

	/** Protected Constructors */
	ADatedObjectDb();
	ADatedObjectDb(const ADatedObjectDb* ptr);
	ADatedObjectDb(const ADatedObjectDb& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init(Object* dbobj, UtilDate* end_d);
	void init_ADatedObjectDb(Object* dbobj, UtilDate* end_d);
	virtual void init_dbobj(Object* obj);
	virtual void init_end_d(UtilDate* obj);
	virtual void init_odbm();
	virtual void init_dhS();

	//Destructor
	virtual ~ADatedObjectDb(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_ADatedObjectDb(); 
	virtual void cleanMem_dbobj();
	virtual void cleanMem_end_d();
	virtual void cleanMem_odbm();
	virtual void cleanMem_dhS();

	/** Public Data Access Functions */
	virtual Object* dbobj();
	virtual UtilDate* end_d();
	virtual unordered_map<UtilDate*,ObjectDb*>* odbm();
	virtual set<int>* dhS();

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_ADatedObjectDb(string fname);
	virtual void fscan(string fname);
	void fscan_ADatedObjectDb(string fname);

	//Reset
	virtual void reset();
	void reset_ADatedObjectDb();


	/** ------ Static Functions ----------------*/

	static ADatedObjectDb* instance(Object* dbobj, UtilDate* end_d);

	static ADatedObjectDb* instance_fscan(string fname);

	virtual ADatedObjectDb* instantiate(Object* dbobj, UtilDate* end_d);

	/** ----------  Non-standard functions start here -----------*/

   virtual void add_odb(ObjectDb* odb);

   virtual ObjectDb* odb(Object* dbobj, UtilDate* end_d, UtilDate* dh, 
                          int& xval);

   virtual double ddba(Object* dbobj, UtilDate* end_d, UtilDate* dh,
                        DoubleDbAccount* dba, int& xval);

   virtual string sdba(Object* dbobj, UtilDate* end_d, UtilDate* dh,
                       StringDbAccount* dba, int& xval);

   /** This function finds the closest date that is on or before dh */
   virtual UtilDate* dh(UtilDate* dh);

   virtual void summary(list<unordered_map<string,string>*>*& L, set<string>* headerS=NULL);

};

};

#endif

