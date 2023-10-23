# Parallel-Programming-WEC

This repo basically covers the assignment of System SIG ( Parallel Programming ) assignment questions.

I have used both gcc compiler from linux and mingw from windows to check some of the performance, among the parallel programms present here some ran perfectly and gave upto 3x performance but other didn't do well due to some reasons(allocation of threads consume time).

API used :

1. OpenMP
2. MPI

To compile the programs writen using these api use:

1. OpenMP
   gcc -fopenmp X.c
   ./a.out
2. MPI
   mpicc X.c
   mpirun -np 4 a.out
