// Includes all relevant components of mlpack.
#include <mlpack/core.hpp>
// Convenience.
using namespace mlpack;
int test_mlpack_main()
{
   int val = 0;

   //cov.cpp
   {
      // First, load the data.
      arma::mat data;
      // Use data::Load() which transposes the matrix.
      data::Load("input/test_mlpack_cov_data.csv", data, true);
      // Now compute the covariance.  We assume that the data is already centered.
      // Remember, because the matrix is column-major, the covariance operation is
      // transposed.
      arma::mat cov = data * trans(data) / data.n_cols;
      // Save the output.
      data::Save("output/test_mlpack_cov_data.csv", cov, true);
   }

   return val;
}
