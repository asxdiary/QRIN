// Name:     DbGen.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DbGen_hpp
#define ASX_DbGen_hpp

namespace aiDbUtils {
//Forword decalaration
class DbGen;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Db.hpp"
#include "ObjectUniverse.hpp"
#include "SMatrix.hpp"
#include "list"
#include "unordered_map"
#include "ModelGen.hpp"
#include "Model.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiMath;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiDbUtils {

class DbGen : public ModelGen  {

/**
 * 	Class Description:
 * 		This class is used to load Db instances
 * 
 * 	Assumptions:
 * 		The data is assumed to be supplied in the long format 
 * 		i.e. one row for each ObjectDb
 * 		With the exception of following fields, all other
 * 		fields are assumed to be valid DbAccounts that are
 * 		retrieved using the singleton pattern:
 * 		- ObjectDb.dbobj
 * 		- Object.start_d
 * 		- Object.dh
 * 		- Object.end_d
 * 
 * 	Objects: (P=Parent; NO=Not Ownwed; O=Owned)
 * 		P mdl: an instance of Db
 * 		O src: string representing the location of Db files
 * 		NO univ: object universe that will be populated as the database is being
 * 		loaded
 * 		O err_flag: an integer variable indicating what to do if
 * 		a header is missing; this can be over-ridden by passing
 * 		a non-negative parameter to _get_val; by default it is set to 0
 * 
 * 	Ownership:
 * 		Indicated above
 * 
 */

private:
/**	Data Members */
	string _src;
	ObjectUniverse* _univ;
	int _err_flag;

protected: 

	/** Protected Constructors */
	DbGen();
	DbGen(const DbGen* ptr);
	DbGen(const DbGen& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

   virtual string _get_val(unordered_map<string,int>* header, string* row, string key, 
                           int& xval, int err_flag=-1);

public:

	//Initializer
	virtual void init(ObjectUniverse* univ);
	void init_DbGen(ObjectUniverse* univ);
	virtual void init_univ(ObjectUniverse* obj);
   virtual void init_err_flag();

	//Destructor
	virtual ~DbGen(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_DbGen(); 
	virtual void cleanMem_univ();

	/** Public Data Access Functions */
	virtual string src();
	virtual int err_flag();
	virtual ObjectUniverse* univ();
   virtual Db* mdl();

	/** Public data Set functions */
	virtual void set_src(string _obj);
	virtual void set_err_flag(int _obj);

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_DbGen(string fname);
	virtual void fscan(string fname);
	void fscan_DbGen(string fname);

	//Reset
	virtual void reset();
	void reset_DbGen();
   virtual void reset_univ();

	/** ------ Static Functions ----------------*/

	static DbGen* instance(ObjectUniverse* univ);

	static DbGen* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   virtual Db* extract_mdl();
   virtual void configure(string src, Db* db=NULL);

   virtual void algo_exec(list<UtilDate*>* dL);
   virtual void algo_exec(UtilDate* d);
   virtual void algo_exec(SMatrix* smat);
   virtual void algo_exec(unordered_map<string,int>* header, string* row);

   virtual Db* gen_db();

};

};

#endif

