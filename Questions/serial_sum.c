#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000

int main(){
    
    clock_t endtime, startime;
    double timeused;
    int * A;
    A = (int *)malloc(sizeof(int) * MAX);
    int i, sum = 0;
    // #pragma omp parallel for
    for(i = 0 ; i < MAX ; i ++){
        A[i] = i ;
    }

    startime = clock();
    // #pragma omp parallel for reduction(+ : sum)
        for(i = 0; i < MAX; i++){
            sum += A[i];
        }
    endtime = clock();

    timeused = (double)(endtime-startime)/ CLOCKS_PER_SEC;
    printf("sum == %d calculated in %lf time", sum, timeused);

    free(A);
}