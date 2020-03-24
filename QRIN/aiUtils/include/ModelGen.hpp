// Name:     ModelGen.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ModelGen_hpp
#define ASX_ModelGen_hpp

namespace aiUtils {
//Forword decalaration
class ModelGen;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Model.hpp"
#include "Object.hpp"
#include "Summarizable.hpp"

using namespace std;
using namespace aiUtils;

//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiUtils {

class ModelGen : public Model {

/**	Class Description  
 *
 *    This class is used for generation of models of various types.
 *
 *    Objects
 *       mdl : instance of Model that is generated; initialized to NULL
 *       mdl_flag : a boolean flag indicating whether the model should
 *       be generated. This is to allow memory light use of various
 *       estimators without necessarily generating an independent model
 *
 *    Ownership:
 *       All objects are owned
 *
 * */

private:
/**	Data Members */
	Model* _mdl;
   bool _mdl_flag;

protected: 

	/** Protected Constructors */
	ModelGen();
	ModelGen(const ModelGen* ptr);
	ModelGen(const ModelGen& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_ModelGen();
   virtual void init_mdl_flag();

	//Destructor
	virtual ~ModelGen(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_ModelGen(); 
	virtual void cleanMem_mdl();

	/** Public Data Access Functions */
	virtual Model* mdl();
   virtual bool mdl_flag();

	/** Public data Set functions */
	virtual void set_mdl(Model* _obj);
   virtual void set_mdl_flag(bool _obj);

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_ModelGen(string fname);
	virtual void fscan(string fname);
	void fscan_ModelGen(string fname);

	//Reset
	virtual void reset();
	void reset_ModelGen();
	virtual void reset_mdl();


	/** ------ Static Functions ----------------*/

	static ModelGen* instance();

	static ModelGen* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   virtual Model* extract_mdl();
   virtual void configure();
   virtual void algo_exec();


};

};

#endif

