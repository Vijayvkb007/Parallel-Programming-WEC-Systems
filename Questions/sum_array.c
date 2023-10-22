#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000

int main(){
    
    time_t start, end;
    double runtime;

    int * A;
    A = (int *)malloc(sizeof(int) * MAX);
    int i, sum = 0;
    #pragma omp parallel for
    for(i = 0 ; i < MAX ; i ++){
        A[i] = i ;
    }

    // start = time(NULL);
    start = clock();
    #pragma omp parallel for reduction(+ : sum)
        for(i = 0; i < MAX; i++){
            sum += A[i];
        }
    // end = time(NULL);
    end = clock();
    // runtime = difftime(end, start);

    runtime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("sum == %d calculated in %lf time", sum, runtime);

    free(A);
}