/*
gcc -fopenmp -o 2 2.c
./2
*/
#include<omp.h>
#include<stdio.h>
int main()
{
	int m, n, p, q, c, d, k, sum = 0,threads;
	int first[100][100], second[100][100], multiply[100][100];
	printf("Enter the number of rows and columns of first matrix\n");
	scanf("%d%d", &m, &n);
	for (c = 0; c < m; c++)
		for (d = 0; d < n; d++)
			first[c][d] = c*n + d + 1;
	printf("Enter the number of rows and columns of second matrix\n");
	scanf("%d%d", &p, &q);
	if (n != p)
		printf("Matrices with entered orders can't be multiplied with each other.\n");
	else
	{
		for (c = 0; c < p; c++)
			for (d = 0; d < q; d++)
				second[c][d] = c*n + d + 1;
		printf("Enter the number of threads\n");
		scanf("%d", &threads);
		omp_set_num_threads(threads);

		double x = omp_get_wtime();

#pragma omp parallel for private(d,k,sum)
		for (c = 0; c < m; c++)
		{
			for (d = 0; d < q; d++)
			{
				for (k = 0; k < p; k++)
				{
					sum = sum + first[c][k] * second[k][d];
				}
				multiply[c][d] = sum;
				sum = 0;
			}
		}
		double y = omp_get_wtime();
		printf(" Product of entered matrices : -\nHuge matrix. Removed for saving space\n");
		/*for (c = 0; c < m; c++)
		{
				for (d = 0; d < q; d++)
					printf(" %d\t" , multiply[c][d]);
			printf("\n");
		}
*/

		printf("%lf\n", y - x);
	}


	return 0;
}