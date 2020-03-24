// Name:     DatedTables.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DatedTables_hpp
#define ASX_DatedTables_hpp

namespace aiUtils {
//Forword decalaration
class DatedTables;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "UtilDate.hpp"
#include "SMatrix.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMath;


//Parameters/////////////////////////////
#define DatedTables_lookback_default 45
/////////////////////////////////////////

namespace aiUtils {

class DatedTables : public Object  {

/**
 * 	Class Description:
 * 		This class is used to maintain dated tables, and serves as a 
 * 		light weight database utility
 * 
 * 	Assumptions:
 * 		None
 * 
 * 	Objects:
 * 		src: regex location of the database files
 * 		lookback: maximum amount of lookback in load function
 * 		data: db data
 * 
 * 	Ownership:
 * 		All objects owned
 * 
 */

private:
/**	Data Members */
	string _src;
	int _lookback;
	unordered_map<UtilDate*,SMatrix*>* _data;

protected: 

	/** Protected Constructors */
	DatedTables();
	DatedTables(const DatedTables* ptr);
	DatedTables(const DatedTables& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init(string src, unordered_map<UtilDate*,SMatrix*>* data);
	void init_DatedTables(string src, unordered_map<UtilDate*,SMatrix*>* data);
	virtual void init_src(string src);
	virtual void init_lookback(int lookback);
	virtual void init_data(unordered_map<UtilDate*,SMatrix*>* data);

	//Destructor
	virtual ~DatedTables(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_DatedTables(); 
	virtual void cleanMem_data();

	/** Public Data Access Functions */
	virtual string src();
	virtual int lookback();
	virtual unordered_map<UtilDate*,SMatrix*>* data();
   virtual SMatrix* data(UtilDate* d);

	/** Public data Set functions */
	virtual void set_src(string _obj);
	virtual void set_lookback(int _obj);
	virtual void set_data(unordered_map<UtilDate*,SMatrix*>* _obj);
   virtual void set_data(UtilDate* d, SMatrix* smat);

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);
	void mywarn_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_DatedTables(string fname);
	virtual void fscan(string fname);
	void fscan_DatedTables(string fname);

	//Reset
	virtual void reset();
	void reset_DatedTables();


	/** ------ Static Functions ----------------*/

	static DatedTables* instance(string src, unordered_map<UtilDate*,SMatrix*>* data=NULL);

	static DatedTables* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   /** err_flag controls the behaviour when the file does not exist
    * 0: throw an error
    * 1: throw a warning
    * 2: ignore and move on */
   virtual void load(UtilDate* d, int err_flag=0);

};

};

#endif

