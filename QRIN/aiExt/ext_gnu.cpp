#include <stdio.h>
#include <gsl/gsl_sf_bessel.h>
#include <gsl/gsl_cdf.h>
#include "ext_gnu.hpp"

int
gnu_main (void)
{
   //double x = 5.0;
   //double y = gsl_sf_bessel_J0 (x);
   double z = gsl_cdf_fdist_P(3.0, 12, 1500);
   printf("z = %2.8f\n",z);
   return 0;
}

