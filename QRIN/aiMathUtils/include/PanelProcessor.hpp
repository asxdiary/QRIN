// Name:     PanelProcessor.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_PanelProcessor_hpp
#define ASX_PanelProcessor_hpp

namespace aiMathUtils {
//Forword decalaration
class PanelProcessor;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Panel.hpp"
#include "ModelGen.hpp"
#include "Model.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMath;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiMathUtils {

class PanelProcessor : public ModelGen  {

/**	Class Description 
 *
 *    This class serves as the super class of Panel processors
 *
 *    Objects:
 *       insitu: a boolean flag indicating whether the original is to be
 *       replaced by the model Panel
 *       X: input Panel to be processed
 *
 *    Ownership:
 *       All objects except X; note that if insitu=true then ownership
 *       of X is assumed implicitly through mdl object */

private:
/**	Data Members */
	bool _insitu;
	Panel* _X;

protected: 

	/** Protected Constructors */
	PanelProcessor();
	PanelProcessor(const PanelProcessor* ptr);
	PanelProcessor(const PanelProcessor& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init(bool insitu);
	void init_PanelProcessor(bool insitu);
	virtual void init_insitu(bool obj);

	//Destructor
	virtual ~PanelProcessor(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_PanelProcessor(); 
	virtual void cleanMem_X();

	/** Public Data Access Functions */
	virtual bool insitu();
	virtual Panel* X();
   virtual Panel* mdl();

	/** Public data Set functions */
	virtual void set_insitu(bool _obj);
	virtual void set_X(Panel* _obj);

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_PanelProcessor(string fname);
	virtual void fscan(string fname);
	void fscan_PanelProcessor(string fname);

	//Reset
	virtual void reset();
	void reset_PanelProcessor();
	virtual void reset_X();


	/** ------ Static Functions ----------------*/

	static PanelProcessor* instance(bool insitu);

	static PanelProcessor* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   virtual Panel* extract_mdl();
   virtual void configure(Panel* X);
   virtual void algo_exec();

};

};

#endif

