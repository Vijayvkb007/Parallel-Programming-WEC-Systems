#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#define MAX 70

int main(){
    
    double runtime, starttime;

    int * A;
    A = (int *)malloc(sizeof(int) * MAX);
    int i; 
    long int sum = 0;

    #pragma omp parallel for
    for(i = 0 ; i < MAX ; i ++){
        A[i] = i ;
    }

    starttime = omp_get_wtime();
    int j,k,l;
    int num;
    omp_set_num_threads(4);
    #pragma omp parallel private(i,j,k,l) 
    {
    num = omp_get_num_threads(); 
    #pragma omp for reduction(+ : sum) schedule(auto)
    for(i = 0; i < MAX; i++){
        for(j = 0 ; j< MAX; j++)
            for(k = 0 ; k< MAX; k++)
                for(l = 0 ; l < MAX; l ++)
                    sum += (long)A[i];
        }}

    runtime = omp_get_wtime();
    printf("sum == %ld calculated in %lf time with threads == %d", sum, runtime-starttime,num);

    free(A);
}