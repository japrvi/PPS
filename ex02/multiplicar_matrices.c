#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>


static void	*matrix_creator(float *m, char **argv, int size);
static float	*matrix_multiplication(float *m1, float *m2, int rows, int cols);

int main(int argc, char **argv)
{

	int i = 0;
	int m = atoi(argv[i++]);
	int n = atoi(argv[i++]);
	int p = atoi(argv[i++]);
	int mn = m * n;
	int np = n * p;

	float *m1 = (float *) malloc(mn);
	float *m2 = (float *) malloc(np);
	matrix_creator(m1, argv + 3, mn);
	matrix_creator(m2, argv + mn + 3, np);
	float *res = matrix_multiplication(m1, m2, m, p);
	free(m1); free(m2);
	return (res);
}

static void	*matrix_creator(float *m, char **argv, int size)
{
	while (--size)
	{
		m[size] = atof(argv[size]);
	}
}

static float	*matrix_multiplication(float *m1, float *m2, int rows, int cols)
{
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int m = 0;
	float *res = (float *) malloc(rows * cols);
	float aux = 0;

	while (i < rows)
	{
		while(j < cols)
		{
			aux += m1[i + j] * m2[i + cols * j];
			j++;
		}
		j = 0;
		res[m] = aux;
		m++;
		i++;
	}
	return (res);
}
