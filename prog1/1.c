/*
gcc -fopenmp -o 1 1.c
./1
*/
#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#define SEED 35791246
void main()
{
	long n = 0, i, count = 0, threads;
	double z, pi, x, y;
	printf("Enter the number of iterations used to estimate pi :");
	scanf("%ld", &n);
	printf("Enter the number of threads to be used: ");
	scanf("%ld", &threads);
	srand(SEED);

	omp_set_num_threads(threads);

	double start = omp_get_wtime();

	#pragma omp parallel
	for (i = 0; i < n; i++)
	{
		x = (double)rand() / RAND_MAX;
		y = (double)rand() / RAND_MAX;
		z = x * x + y * y;
		if (z <= 1) count++;
	}
	pi = (double)count / n * 4;
	printf("# of trials = %ld\n# of threads = %ld\nestimate of pi is %g\ntime taken = %g\n", n, threads, pi,omp_get_wtime()-start);
}