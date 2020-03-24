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
#include "CsvModelGen.hpp"
#include "Db.hpp"
#include "ObjectUniverse.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMath;
using namespace aiDb;
using namespace aiDbUtils;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiDbUtils {

class DbGen : public CsvModelGen  {

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
 * 		NO univ: object universe that will be populated as the database is being
 * 		loaded
 * 		O int _lookahead: number of months of lookahead bias to be added to the
 * 		database; this is designed to allow experiments that necessarily add look
 * 		ahead bias
 * 
 * 	Ownership:
 * 		Indicated above
 * 
 */

private:
/**	Data Members */
	ObjectUniverse* _univ;
	int _lookahead;

protected: 

	/** Protected Constructors */
	DbGen();
	DbGen(const DbGen* ptr);
	DbGen(const DbGen& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init(ObjectUniverse* univ);
	void init_DbGen(ObjectUniverse* univ);
	virtual void init_univ(ObjectUniverse* univ);
   virtual void init_lookahead();

	//Destructor
	virtual ~DbGen(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_DbGen(); 
	virtual void cleanMem_univ();

	/** Public Data Access Functions */
	virtual ObjectUniverse* univ();
	virtual int lookahead();

	/** Public data Set functions */
	virtual void set_lookahead(int _obj);

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


	/** ------ Static Functions ----------------*/

	static DbGen* instance(ObjectUniverse* univ);

	static DbGen* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   virtual Db* mdl();
   virtual Db* extract_mdl();
   virtual Model* gen_mdl();
   virtual void configure(string src, Db* db=NULL);

   virtual void algo_exec_guts(unordered_map<string,int>* header, string* row);

   virtual UtilDate* lookahead(UtilDate* d);

};

};

#endif

