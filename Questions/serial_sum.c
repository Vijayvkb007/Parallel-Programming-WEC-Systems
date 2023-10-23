#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#define MAX 70

int main(){
    
    double endtime, startime;
    double timeused;
    int * A;
    A = (int *)malloc(sizeof(int) * MAX);
    int i;
    long int sum = 0;
    for(i = 0 ; i < MAX ; i ++){
        A[i] = i ;
    }

    startime = omp_get_wtime();

    int j,k,l;
        for(i = 0; i < MAX; i++){
            for(j = 0 ; j< MAX; j++)
                for(k = 0 ; k< MAX; k++)
                    for(l = 0 ; l < MAX; l ++)
                        sum += (long)A[i];
        }
    endtime = omp_get_wtime();

    timeused = endtime - startime;
    printf("sum == %ld calculated in %lf time", sum, timeused);

    free(A);
}