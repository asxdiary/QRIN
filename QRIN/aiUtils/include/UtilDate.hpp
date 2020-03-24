// Name:     UtilDate.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_UtilDate_hpp
#define ASX_UtilDate_hpp

namespace aiUtils {
//Forword decalaration
class UtilDate;
};

#include <vector>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Model.hpp"

using namespace std;
using namespace aiUtils;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiUtils {

class UtilDate : public Model  {

/**
 * 	Class Description:
 * 		This class is used to represent dates using (yyyy,mm,dd) format;
 * 
 * 	Assumptions:
 * 	   Date related checks are limited to:
 * 	      0 <= yyyy
 * 	      1 <= mm <= 12
 * 	      1 <= dd <= 31
 * 	   Additional checks such as detecting 31st February as an invalid
 * 	   date are not implemented
 * 
 * 	Objects:
 * 		yyyy, mm, dd: integers defining the date
 * 
 * 	Ownership:
 * 		All objects owned
 * 
 */

private:
/**	Data Members */
	int _yyyy;
	int _mm;
	int _dd;

protected: 

	/** Protected Constructors */
	UtilDate();
	UtilDate(const UtilDate* ptr);
	UtilDate(const UtilDate& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init(int yyyy, int mm, int dd);
	void init_UtilDate(int yyyy, int mm, int dd);
	virtual void init_yyyy(int obj);
	virtual void init_mm(int obj);
	virtual void init_dd(int obj);

	//Destructor
	virtual ~UtilDate(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_UtilDate(); 

	/** Public Data Access Functions */
	virtual int yyyy();
	virtual int mm();
	virtual int dd();

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_UtilDate(string fname);
	virtual void fscan(string fname);
	void fscan_UtilDate(string fname);

	//Reset
	virtual void reset();
	void reset_UtilDate();


	/** ------ Static Functions ----------------*/

	static UtilDate* instance(int yyyy, int mm, int dd);
	static UtilDate* instance_fscan(string fname);
   static UtilDate* instance(string dstr);
   static UtilDate* instance(int icode);

   static string _genid(int yyyy, int mm, int dd);
   static string _genid(int mm);

   static UtilDate* format(string dstr, string f);
   static bool isEmpty(string dstr);

   static UtilDate* prev_d(UtilDate* d, int num=1);
   static UtilDate* next_d(UtilDate* d, int num=1);

   static UtilDate* prev_m(UtilDate* d, int num=1);
   static UtilDate* next_m(UtilDate* d, int num=1);

   static UtilDate* eom(UtilDate* d);
   static UtilDate* eom(int yyyy, int mm);
   static UtilDate* prev_eom(UtilDate* d, int num=1);
   static UtilDate* next_eom(UtilDate* d, int num=1);
   /** This function returns all eom dates between d1 (included) and d2 (excluded) */
   static list<UtilDate*>* eomL(UtilDate* d1, UtilDate* d2, list<UtilDate*>* dL=NULL);
   /** This function returns all end of quarter dates between d1 (included) and d2 (excluded) */
   static list<UtilDate*>* eoqL(UtilDate* d1, UtilDate* d2, list<UtilDate*>* dL=NULL);
   static vector<UtilDate*>* eomV(UtilDate* d1, UtilDate* d2, vector<UtilDate*>* dV=NULL);

   /** This function creates a chronologically sorted vector of dates
    * corresponding to end of four quarters ending with the eom of date d*/
   static vector<UtilDate*>* eoq(UtilDate* d, vector<UtilDate*>* dV=NULL);

   /** This function returns the approximate number of days between d1 and d2;
    * a positive number is returned if d2 falls after d1 */
   static int ndays(UtilDate* d1, UtilDate* d2);
   static int nmonths(UtilDate* d1, UtilDate* d2);

   static list<UtilDate*>* sort_algo_insertion(list<UtilDate*>* L, bool rev_flag=false);
   static list<UtilDate*>* sort_algo_insertion(set<UtilDate*>* L, bool rev_flag=false);

   static UtilDate* max(vector<UtilDate*>* dv);
   static UtilDate* min(vector<UtilDate*>* dv);

	/** ----------  Non-standard functions start here -----------*/

   virtual string format(string fname); 
   virtual bool isBefore(UtilDate* d, bool eqflag=false);
   virtual bool isAfter(UtilDate* d, bool eqflag=false);
   virtual bool isBetween(UtilDate* d1, UtilDate* d2, bool eqflag1=false, bool eqflag2=false);

   /** yyyy*10000 + mm * 100 + dd */
   virtual int icode();

   virtual UtilDate* prev_d(int num = 1);
   virtual UtilDate* next_d(int num = 1);
   virtual UtilDate* prev_m(int num = 1);
   virtual UtilDate* next_m(int num = 1);
   virtual UtilDate* prev_eom(int num = 1);
   virtual UtilDate* next_eom(int num = 1);
   virtual UtilDate* eom();

};

};

#endif

