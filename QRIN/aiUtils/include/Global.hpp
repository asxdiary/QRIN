// Name:     Global.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_Global_hpp
#define ASX_Global_hpp

namespace aiUtils {
//Forword decalaration
class Global;
};

#include "Utils.hpp"
#include "Object.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiUtils;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiUtils {

class Global : public Object  {

/**
 * 	Class Description:
 * 		This class is used to store global variables, and to help
 * 		make the code portable 
 * 
 * 	Assumptions:
 * 		Implements Singleton design pattern
 * 
 * 	Objects:
 * 		int_var, double_var, string_var: template variables that 
 * 		can be used for replication purposes
 *
 * 		eps (double): used to check if a double is equal to 0
 * 		precision (int): number of significant digits to be printed for a double
 * 		delimiter (string): default delimiter for csv files
 * 		coin_home (string): location of the COIN directory
 * 		data_home (string): location of the data directory
 * 		compustatQ_home: location of compustatQ files
 *       smartestFY_home: location of smart FY estimates 
 *       savanetFY_home: location of savanet dataset (fiscal year estimates & actuals)
 *       savanetQA_home: location of savanet dataset (quarterly actuals)
 * 		mmdb_home: location of montly market database (mmdb) files that contain
 * 		adv3mdb_home: location of monthly ADV 3-months database (adv3mdb) files that contain
 * 		dmdb_home: location of daily market database (dmdb) files that contain
 * 		vixdb_home: location of daily vix 
 * 		mcapdb_home: location of daily market database (mcapdb) files that contain
 * 		mna_home: location of M&A database 
 * 		adrdb_home: location of ADRs
 * 		domdb_home: location of domdb information
 * 		vix_252d75pct_home: location of 252 days 75th percentile of VIX
 * 		vix_90davg_home: location of 90 days average VIX
 * 		r_home (string): location of the r code 
 * 		r_tmpdir (string): location of the directory where temportary r files are stored
 * 		eom_src (string): location of the eom dates
 * 		eom_format (string): format of the eom dates
 * 
 * 	Ownership:
 * 		All objects owned
 * 
 */

private:
/**	Data Members */
	int _int_var;
	int _precision;
	double _double_var;
	double _eps;
	string _string_var;
	string _coin_home;
	string _data_home;
	string _compustatQ_home;
	string _smartestFY_home;
	string _savanetFY_home;
	string _savanetQA_home;
	string _mmdb_home;
	string _adv3mdb_home;
	string _dmdb_home;
	string _vixdb_home;
	string _mcapdb_home;
	string _mna_home;
	string _adrdb_home;
	string _domdb_home;
	string _vix_252d75pct_home;
	string _vix_90davg_home;
	string _r_home;
	string _r_tmpdir;
	string _delimiter;
	string _eom_src;
	string _eom_format;

protected: 

	/** Protected Constructors */
	Global();
	Global(const Global* ptr);
	Global(const Global& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_Global();

	//Destructor
	virtual ~Global(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_Global(); 

	/** Public Data Access Functions */
	virtual int int_var();
	virtual int precision();
	virtual double double_var();
	virtual double eps();
	virtual string string_var();
	virtual string coin_home();
	virtual string data_home();
	virtual string compustatQ_home();
	virtual string smartestFY_home();
	virtual string savanetFY_home();
	virtual string savanetQA_home();
	virtual string mmdb_home();
	virtual string adv3mdb_home();
	virtual string dmdb_home();
	virtual string vixdb_home();
	virtual string mcapdb_home();
	virtual string mna_home();
	virtual string adrdb_home();
	virtual string domdb_home();
	virtual string vix_252d75pct_home();
	virtual string vix_90davg_home();
	virtual string r_home();
	virtual string r_tmpdir();
	virtual string delimiter();
	virtual string eom_src();
	virtual string eom_format();

	virtual string compustatQ_src();
	virtual string smartestFY_src();
	virtual string savanetFY_src();
	virtual string savanetQA_src();
	virtual string mmdb_src();
	virtual string adv3mdb_src();
	virtual string dmdb_src();
	virtual string vixdb_src();
	virtual string mcapdb_src();
	virtual string mna_src();
	virtual string adrdb_src();
	virtual string domdb_src();
	virtual string vix_252d75pct_src();
	virtual string vix_90davg_src();

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_Global(string fname);
	virtual void fscan(string fname);
	void fscan_Global(string fname);

	//Reset
	virtual void reset();
	void reset_Global();


	/** ------ Static Functions ----------------*/

	static Global* instance();

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

