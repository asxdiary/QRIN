// Name:     CsvModelGen.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_CsvModelGen_hpp
#define ASX_CsvModelGen_hpp

namespace aiUtils {
//Forword decalaration
class CsvModelGen;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "SMatrix.hpp"
#include "ModelGen.hpp"
#include "Model.hpp"
#include "UtilDate.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMath;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiUtils {

class CsvModelGen : public ModelGen  {

/**
 * 	Class Description:
 * 		This class is used to provide the basic functionality to read
 * 		a model from a delimited file; the data is read row by row
 * 		and a hook function is provided for processing the rows
 * 
 * 	Assumptions:
 * 	   None
 * 
 * 	Objects: (P=Parent; NO=Not Ownwed; O=Owned)
 * 		O src: string representing the location of Db files
 * 		O err_flag: an integer variable indicating what to do if
 * 		a header is missing; this can be over-ridden by passing
 * 		a non-negative parameter to _get_val; by default it is set to 0
 * 		NO algo_exec_d: this is an internal parameter which is used to store
 * 		the current date that is being processed during algo_exec
 * 
 * 	Ownership:
 * 		Indicated above
 * 
 */

private:
/**	Data Members */
	string _src;
	int _err_flag;
   UtilDate* _algo_exec_d;

protected: 

	/** Protected Constructors */
	CsvModelGen();
	CsvModelGen(const CsvModelGen* ptr);
	CsvModelGen(const CsvModelGen& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

   virtual string _get_val(unordered_map<string,int>* header, string* row, string key, 
                           int& xval, int err_flag=-1);

public:

	//Initializer
	virtual void init();
	void init_CsvModelGen();
   virtual void init_err_flag();

	//Destructor
	virtual ~CsvModelGen(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_CsvModelGen(); 
   virtual void cleanMem_algo_exec_d();

	/** Public Data Access Functions */
	virtual string src();
	virtual int err_flag();
   virtual UtilDate* algo_exec_d();

	/** Public data Set functions */
	virtual void set_src(string _obj);
	virtual void set_err_flag(int _obj);

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_CsvModelGen(string fname);
	virtual void fscan(string fname);
	void fscan_CsvModelGen(string fname);

	//Reset
	virtual void reset();
	void reset_CsvModelGen();
   virtual void reset_univ();

	/** ------ Static Functions ----------------*/

	static CsvModelGen* instance();

	static CsvModelGen* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   virtual void configure(string src, Model* mdl);
   virtual Model* gen_mdl();

   virtual void algo_exec(list<UtilDate*>* dL);
   virtual void algo_exec(UtilDate* d);
   virtual void algo_exec(SMatrix* smat);
   virtual void algo_exec_guts(unordered_map<string,int>* header, string* row);

};

};

#endif

