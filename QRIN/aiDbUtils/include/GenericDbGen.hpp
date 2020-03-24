// Name:     GenericDbGen.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_GenericDbGen_hpp
#define ASX_GenericDbGen_hpp

namespace aiDbUtils {
//Forword decalaration
class GenericDbGen;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DbGen.hpp"
#include "Db.hpp"
#include "ObjectUniverse.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbUtils;
using namespace aiDb;
using namespace aiDbUtils;
using namespace aiDb;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiDbUtils {

class GenericDbGen : public DbGen  {

/**
 * 	Class Description:
 * 		This class is used to load databases with generic double accounts
 * 
 * 	Assumptions:
 * 		None
 * 
 * 	Objects: (P=Parent; NO=Not Ownwed; O=Owned)
 * 		oid: header for the primary object id
 * 		ddba_idS: set of headers for which a GenericDoubleDbAccount is created
 * 
 * 	Ownership:
 * 		Indicated above
 * 
 */

private:
/**	Data Members */
	string _oid;
	set<string>* _ddba_idS;

protected: 

	/** Protected Constructors */
	GenericDbGen();
	GenericDbGen(const GenericDbGen* ptr);
	GenericDbGen(const GenericDbGen& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init(ObjectUniverse* univ, string oid);
	void init_GenericDbGen(string oid);
	virtual void init_oid(string oid);
	virtual void init_ddba_idS();

	//Destructor
	virtual ~GenericDbGen(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_GenericDbGen(); 
	virtual void cleanMem_ddba_idS();

	/** Public Data Access Functions */
   virtual ObjectUniverse* univ();
   virtual Db* mdl();
	virtual string oid();
	virtual set<string>* ddba_idS();

	/** Public data Set functions */
	virtual void add_ddba_idS(string obj);

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_GenericDbGen(string fname);
	virtual void fscan(string fname);
	void fscan_GenericDbGen(string fname);

	//Reset
	virtual void reset();
	void reset_GenericDbGen();


	/** ------ Static Functions ----------------*/

	static GenericDbGen* instance(ObjectUniverse* univ, string oid="ObjectDb.dbobj");

	static GenericDbGen* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   virtual void algo_exec_guts(unordered_map<string,int>* header, string* row);

};

};

#endif

