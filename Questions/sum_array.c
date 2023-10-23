#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

int main(){
    
    clock_t t;
    double runtime;

    int * A;
    A = (int *)malloc(sizeof(int) * MAX);
    int i, sum = 0;

    #pragma omp parallel for
    for(i = 0 ; i < MAX ; i ++){
        A[i] = i ;
    }

    // start = time(NULL);
    t = clock();
    // start = omp_get_wtime();
    #pragma omp parallel for reduction(+ : sum)
        for(i = 0; i < MAX; i++){
            sum += A[i];
        }
    // end = time(NULL);
    t = clock() - t;
    // end = omp_get_wtime();
    // runtime = difftime(end, start);
    // runtime = end - start;
    runtime = ((double)t / CLOCKS_PER_SEC);
    printf("sum == %d calculated in %lf time", sum, runtime);

    free(A);
}