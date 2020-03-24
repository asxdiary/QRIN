// Name:     MergersAcquisitionUniverse.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_MergersAcquisitionUniverse_hpp
#define ASX_MergersAcquisitionUniverse_hpp

namespace aiFin {
//Forword decalaration
class MergersAcquisitionUniverse;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Company.hpp"
#include "UtilDateRange.hpp"
#include "UtilDateRangeS.hpp"
#include "UtilDate.hpp"
#include "Model.hpp"
#include "Summarizable.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiFin;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiFin {

class MergersAcquisitionUniverse : public Model, public Summarizable  {

/**
 * 	Class Description:
 * 		This class is used to store M&A information;
 * 		this is a rudimentary implementation that can be expanded
 * 		into a full fledged module in future
 * 
 * 	Assumptions:
 * 		None
 * 
 * 	Objects:
 * 		drm: map [Company -> UtilDateRangeS]
 * 		This object contains the mapping of companies to collection
 * 		of date ranges when the company was under M&A consideration.
 * 		The class does not implement any blackout period assumption per se;
 * 		those assumptions (if any) are presumed to be defined exogenously
 * 
 * 	Ownership:
 * 		All objects owned
 * 
 */

private:
/**	Data Members */
	unordered_map<Company*,UtilDateRangeS*>* _drm;

protected: 

	/** Protected Constructors */
	MergersAcquisitionUniverse();
	MergersAcquisitionUniverse(const MergersAcquisitionUniverse* ptr);
	MergersAcquisitionUniverse(const MergersAcquisitionUniverse& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_MergersAcquisitionUniverse();
	virtual void init_drm();

	//Destructor
	virtual ~MergersAcquisitionUniverse(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_MergersAcquisitionUniverse(); 
	virtual void cleanMem_drm();

	/** Public Data Access Functions */
	virtual unordered_map<Company*,UtilDateRangeS*>* drm();

	/** Public data Set functions */
   virtual void add(Company* cmp, UtilDateRange* dr);
   virtual void add(Company* cmp, UtilDate* sd, UtilDate* ed);

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_MergersAcquisitionUniverse(string fname);
	virtual void fscan(string fname);
	void fscan_MergersAcquisitionUniverse(string fname);

	//Reset
	virtual void reset();
	void reset_MergersAcquisitionUniverse();


	/** ------ Static Functions ----------------*/

	static MergersAcquisitionUniverse* instance();

	static MergersAcquisitionUniverse* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   virtual bool overlap(Company* cmp, UtilDate* ptr);
   virtual bool overlap(Company* cmp, UtilDateRange* ptr);

   virtual void summary(list<unordered_map<string,string>*>*& L, set<string>* headerS=NULL);

};

};

#endif

