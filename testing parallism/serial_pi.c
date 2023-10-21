/*
This program intend to find the integration of fucntion 
f(x) = 4/(1 + x^2) 
this is achieved by dividing the interval into infinetisimal strips which are added individualy

or in simple words summation -> integration conversion.

integration of this function is equal to pi.
*/

#include <stdio.h>
#include <omp.h>

static long num_steps = 100000000; double dx;

int main(){

    double pi = 0.0; 
    dx = 1.0/ (double) num_steps; // the smallest strip dx
    double x, sum = 0.0; 
    
    double starttime = omp_get_wtime();

    for(int i = 0; i < num_steps; i++){
        x = (i + 0.5) * dx;
        sum += 4.0 / ( 1.0 + x*x );
    }

    pi += sum * dx;
    double runtime = omp_get_wtime() - starttime;

    printf("value of integration : %1.4f and the time take to compute : %2.6f", pi , runtime);
}