// Name:     Object.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_Object_hpp
#define ASX_Object_hpp

namespace aiUtils {
//Forword decalaration
class Object;
class Summarizable;
};

#include <string>
#include "Utils.hpp"

using namespace aiUtils;
using namespace std;

//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiUtils {

class Object {

/**	This class serves as the super class of all classes in AI infrastructure 
 *       
 *       id: name of the object
 *
 *       debug_mode: a boolean flag that puts the object in debugging mode
 *       debug_pfx, debug_id: string attributes that can be used to supply
 *       location of files where the debugging information is dumped 
 *
 *       debug_objm: map: string -> Object**
 *       a map from object name to the pointer of the object which needs 
 *       to be configured */

private:
/**	Data Members */
	string _id;
   bool _debug_mode;
   string _debug_pfx;
   string _debug_id;
	unordered_map<string,Object**>* _debug_objm;

protected: 

	/** Protected Constructors */
	Object();
	Object(const Object* ptr);
	Object(const Object& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

	/** Protected data Set functions */

public:

	//Initializer
	virtual void init();
	void init_Object();
	virtual void init_id();
   virtual void init_debug_mode();
   virtual void init_debug_pfx();
   virtual void init_debug_id();
	virtual void init_debug_objm();

	//Destructor
	virtual ~Object(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_Object(); 
	virtual void cleanMem_debug_objm();

	/** Public Data Access Functions */
	virtual string id();
   virtual bool debug_mode();
   virtual string debug_pfx();
   virtual string debug_id();
	virtual unordered_map<string,Object**>* debug_objm();

	/** Public data Set functions */
	virtual void set_id(const string _obj);
   virtual void set_debug_mode(bool _obj);
   virtual void set_debug_pfx(string _obj);
   virtual void set_debug_id(string _obj);
   virtual void set_debug_info(bool debug_mode, string debug_pfx);
	virtual void add_debug_objm(string str, Object** ptr);

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string str);
	virtual void fscan(string str);
   virtual void fprint_table(string pfx);

	//Reset
	virtual void reset();
	void reset_Object();


	/** ------ Static Functions ----------------*/

	static Object* instance();

   virtual Object* instantiate();

	/** ------ Debugging Functions ----------------*/

   virtual void debug(string oname, Object* obj);
   
   virtual void debug3(string oname, Summarizable* obj);

   template<typename T> void debug2(string oname, T const& val);
   template<typename T> void debug2(string oname, const T* val, const int n);
   template<typename T> void debug2(string oname, T** val, const int m, const int n);
   template<typename T> void debug2(string oname, list<T>* val);
   template<typename T> void debug2(string oname, set<T>* val);
   template<typename T1, typename T2> void debug2(string oname, unordered_map<T1,T2>* val);
   template<typename T1, typename T2> void debug2(string oname, unordered_map<T1,T2>** val, const int num);
   template<typename T1, typename T2> void debug2(string oname, unordered_map<T1,set<T2>*>* val);



};

};

#endif

