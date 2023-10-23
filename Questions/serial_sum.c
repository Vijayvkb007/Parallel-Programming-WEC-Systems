#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000000

int main(){
    
    double endtime, startime;
    double timeused;
    int * A;
    A = (int *)malloc(sizeof(int) * MAX);
    int i, sum = 0;
    // #pragma omp parallel for
    for(i = 0 ; i < MAX ; i ++){
        A[i] = i ;
    }

    startime = omp_get_wtime();
    // #pragma omp parallel for reduction(+ : sum)
        for(i = 0; i < MAX; i++){
            sum += A[i];
        }
    endtime = omp_get_wtime();

    // timeused = ((double)endtime-startime/ CLOCKS_PER_SEC);
    timeused = endtime - startime;
    printf("sum == %d calculated in %lf time", sum, timeused);

    free(A);
}