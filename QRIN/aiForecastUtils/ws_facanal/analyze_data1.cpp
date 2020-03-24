#include "Utils.hpp"
#include "DatedMatrix.hpp"

using namespace aiMath;
using namespace aiUtils;

int analyze_data1_main(int argc, char* argv[]) {
   Matrix* X = NULL;
   DatedMatrix* dm = NULL;
   string fname, ofname;

   {
      int t;
      t = 2;
      if(argc<4) err_msg("Usage: cmd analyze_data1 input_fname output_fname");
      fname = argv[t++];
      ofname = argv[t++];
   }

   X = Matrix::instance_fread_table(fname);

   {
      unordered_map<UtilDate*,unordered_map<string,double>*> valm;
      unordered_map<UtilDate*,unordered_map<string,double>*>::iterator it;
      string* rmap = X->rmap();
      double** XX = X->X();
      UtilDate* d = NULL;
      int m = X->m();
      string aid, dstr;

      for(int i=0;i<m;i++) {
         dstr = rmap[i].substr(0,9);
         aid = rmap[i].substr(10,11);
         d = UtilDate::instance(dstr);
         if(valm.find(d)==valm.end()) valm[d] = new unordered_map<string,double>();
         (*(valm[d]))[aid] = XX[i][0];
      }

      dm = DatedMatrix::instance();
      for(it=valm.begin();it!=valm.end();it++) {
         dm->add(it->first, Matrix::instance_col(it->second));
      }
      dm->set_id("mcap");
   }

   {
      Matrix* u = dm->unianal();
      u->fprint_table(ofname);
      delete u;
   }

   //clean memory
   delete X;
   delete dm;

   return 0;
}

