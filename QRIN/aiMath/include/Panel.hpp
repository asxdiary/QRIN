// Name:     Panel.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_Panel_hpp
#define ASX_Panel_hpp

namespace aiMath {
//Forword decalaration
class Panel;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Model.hpp"
#include "Matrix.hpp"

using namespace std;
using namespace aiUtils;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiMath {

class Panel : public Model  {

/**	Class Description  
 *
 *    This class is used to represent panel datasets that can be unabalanced 
 *    in both row and column spaces
 *
 *    Objects
 *       T = Number of panels
 *       X = Panel data
 *       mS (nS) = set of all possible row (column) indices in X
 *       mSm = an array of maps; mSm[t] contains a mapping of rows
 *       of X[t] to elements of mS
 *       nSm = column counterpart to mSm
 *       rimap = mapping of row names to elements of mS; note that
 *       mS need not contain contiguous entries
 *       cimap = column counterpart to rimap 
 *
 *       */

private:
/**	Data Members */
	int _T;
	Matrix** _X;
	set<int>* _mS;
	set<int>* _nS;
	unordered_map<int,int>** _mSm;
	unordered_map<int,int>** _nSm;
	unordered_map<int,string>* _rmap;
	unordered_map<int,string>* _cmap;
	unordered_map<string,int>* _rimap;
	unordered_map<string,int>* _cimap;

protected: 

	/** Protected Constructors */
	Panel();
	Panel(const Panel* ptr);
	Panel(const Panel& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init(const int T, Matrix** X, 
                     set<int>* mS, 
                     set<int>* nS, 
                     unordered_map<int,int>** mSm, 
                     unordered_map<int,int>** nSm, 
                     unordered_map<int,string>* rmap, unordered_map<string,int>* rimap, 
                     unordered_map<int,string>* cmap, unordered_map<string,int>* cimap);

	void init_Panel(const int T, Matrix** X, 
                     set<int>* mS, 
                     set<int>* nS, 
                     unordered_map<int,int>** mSm, 
                     unordered_map<int,int>** nSm, 
                     unordered_map<int,string>* rmap, unordered_map<string,int>* rimap, 
                     unordered_map<int,string>* cmap, unordered_map<string,int>* cimap);


	virtual void init_T(const int obj);
	virtual void init_X(Matrix** X);
	virtual void init_mS(set<int>* obj);
	virtual void init_nS(set<int>* obj);
	virtual void init_mSm(unordered_map<int,int>** obj);
	virtual void init_nSm(unordered_map<int,int>** obj);
	virtual void init_rmap_rimap(unordered_map<int,string>* omap, unordered_map<string,int>* imap);
	virtual void init_cmap_cimap(unordered_map<int,string>* omap, unordered_map<string,int>* imap);

	//Destructor
	virtual ~Panel(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_Panel(); 
	virtual void cleanMem_X();
	virtual void cleanMem_mS();
	virtual void cleanMem_nS();
	virtual void cleanMem_mSm();
	virtual void cleanMem_nSm();
	virtual void cleanMem_rmap();
	virtual void cleanMem_cmap();
	virtual void cleanMem_rimap();
	virtual void cleanMem_cimap();

	/** Public Data Access Functions */
	virtual int T();
	virtual Matrix** X();
	virtual set<int>* mS();
	virtual set<int>* nS();
	virtual unordered_map<int,int>** mSm();
	virtual unordered_map<int,int>** nSm();
	virtual unordered_map<int,string>* rmap();
	virtual unordered_map<int,string>* cmap();
	virtual unordered_map<string,int>* rimap();
	virtual unordered_map<string,int>* cimap();

	/** Public data Set functions */
	virtual void set_rmap_rimap(unordered_map<int,string>* omap, unordered_map<string,int>* imap);
	virtual void set_cmap_cimap(unordered_map<int,string>* omap, unordered_map<string,int>* imap);

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_Panel(string fname);
	virtual void fscan(string fname);
	void fscan_Panel(string fname);

	//Reset
	virtual void reset();
	void reset_Panel();


	/** ------ Static Functions ----------------*/

	//For error message handling
	static void cerr_msg(string msg, string func);
	static void cwarn_msg(string msg, string func);

	static Panel* instance(const int T, Matrix** X, 
                     set<int>* mS, 
                     set<int>* nS, 
                     unordered_map<int,int>** mSm, 
                     unordered_map<int,int>** nSm, 
                     unordered_map<int,string>* rmap=NULL, unordered_map<string,int>* rimap=NULL, 
                     unordered_map<int,string>* cmap=NULL, unordered_map<string,int>* cimap=NULL);

	static Panel* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   virtual int chk();
   virtual Panel* copy();

   virtual Panel* sub(set<int>* rS, set<int>* cS,
                      set<int>* xrS=NULL, set<int>* xcS=NULL);

   virtual Matrix* collapse(bool row_flag, 
                            set<int>* cS, set<int>* xcS,
                            int** cap);

};

};

#endif

