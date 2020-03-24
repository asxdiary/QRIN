// Name:     ObjectUniverse.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ObjectUniverse_hpp
#define ASX_ObjectUniverse_hpp

namespace aiUtils {
//Forword decalaration
class ObjectUniverse;
};

#include <unordered_map>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Model.hpp"

using namespace std;
using namespace aiUtils;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiUtils {

class ObjectUniverse : public Model {

/**
 * 	Class Description:
 * 		This class is used to store universe of objects allowing the
 * 		possibility of creating new objects when needed
 * 
 * 	Assumptions:
 * 		None
 * 
 * 	Objects: (P=Parent; NO=Not Ownwed; O=Owned)
 * 		O objm: map[string->Object*]
 * 		O genL: list of objects that were created by the incumbent instance
 * 		O gen_flag: a boolean flag indicating whether the universe can 
 * 		create objects
 * 		O objL: a list of all objects to ensure the right ordering of
 * 		objects is preserved
 * 
 * 	Ownership:
 * 		Indicated above
 * 
 */

private:
/**	Data Members */
	unordered_map<string,Object*>* _objm;
   list<Object*>* _objL;
   list<Object*>* _genL;
   bool _gen_flag;

   /** Make genL private */
	virtual list<Object*>* genL();

protected: 

	/** Protected Constructors */
	ObjectUniverse();
	ObjectUniverse(const ObjectUniverse* ptr);
	ObjectUniverse(const ObjectUniverse& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_ObjectUniverse();
	virtual void init_objm();
	virtual void init_objL();
	virtual void init_genL();
   virtual void init_gen_flag();

	//Destructor
	virtual ~ObjectUniverse(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_ObjectUniverse(); 
	virtual void cleanMem_objm();
	virtual void cleanMem_objL();
	virtual void cleanMem_genL();

	/** Public Data Access Functions */
	virtual unordered_map<string,Object*>* objm();
   virtual bool gen_flag();

	/** Public data Set functions */
   virtual void set_gen_flag(bool obj);

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_ObjectUniverse(string fname);
	virtual void fscan(string fname);
	void fscan_ObjectUniverse(string fname);

	//Reset
	virtual void reset();
	void reset_ObjectUniverse();


	/** ------ Static Functions ----------------*/

	static ObjectUniverse* instance();

	static ObjectUniverse* instance_fscan(string fname);

   virtual ObjectUniverse* instantiate();

	/** ----------  Non-standard functions start here -----------*/

   virtual Object* obj(string id, bool create_flag=false);
   virtual void add_obj(Object* obj);
   virtual Object* gen_obj(string id);
   virtual Object* gen_obj_guts(string id);

   /** Returns a subset of the current universe as determined by the object
    * ids in cmap; if ignore_flag is false then mismatches are thrown as
    * errors */
   virtual ObjectUniverse* sub(int n, string* cmap, bool ignore_flag=false);
   virtual ObjectUniverse* sub(set<string>* S, bool ignore_flag=false);

   virtual Object** objA(int& num);
   virtual list<Object*>* objL(list<Object*>* L=NULL);
   virtual list<Object*>* objL(set<string>* S, list<Object*>* L = NULL);
   virtual list<Object*>* objL(int m, string* cmap, list<Object*>* L=NULL);

   virtual set<string>* oidS(set<string>* S=NULL);

};

};

#endif

