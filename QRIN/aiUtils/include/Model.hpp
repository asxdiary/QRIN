// Name:     Model.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_Model_hpp
#define ASX_Model_hpp

namespace aiUtils {
//Forword decalaration
class Model;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Object.hpp"
#include "Object_templates.hpp"

using namespace std;
using namespace aiUtils;

//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiUtils {

class Model : public Object  {

/**	Class Description  
 *
 * This class represents the super class of all Models 
 *
 * */

private:
/**	Data Members */

protected: 

	/** Protected Constructors */
	Model();
	Model(const Model* ptr);
	Model(const Model& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_Model();

	//Destructor
	virtual ~Model(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_Model(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_Model(string fname);
	virtual void fscan(string fname);
	void fscan_Model(string fname);

	//Reset
	virtual void reset();
	void reset_Model();


	/** ------ Static Functions ----------------*/

	static Model* instance();

	static Model* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   virtual int chk();

};

};

#endif

