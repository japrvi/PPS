#include <stdlib.h>
#include <stdio.h>


static double **matrix_creator(int rows, int cols, char **argv);
static double **matrix_multiplication(double **m1, double **m2, int rows1, int cols1, int cols2);
static double **matrix_create(int rows, int cols);

int main(int argc, char **argv)
{
	if (argc > 4)
	{
		int m = atoi(argv[1]);
		int n = atoi(argv[2]);
		int p = atoi(argv[3]);
		int mn = m * n;
		//printf("dimensiones %d %d %d %d\n", m, n, p, mn);
		double **m1 = matrix_creator(m, n, argv + 4);
		double **m2 = matrix_creator(n, p, argv + 4 + mn);
		double **res = matrix_multiplication(m1, m2, m, n, p);
		/*for (int i = 0; i < m ; i++) {
        		for (int j = 0; j < p; j++) {
            			printf("%f ", res[i][j]);
        		}
        		printf("\n");
    		}*/
	}
	else
		return (-1);
	return (0);
}

static double **matrix_creator(int rows, int cols, char **argv)
{
	double **matriz = (double **) malloc(sizeof(double *) * rows);
	unsigned int count = 0;

	for (int i = 0; i < rows; i++)
	{
		matriz[i] = (double *) malloc (cols * sizeof(double));
		for(int j = 0; j < cols; j++)
		{
			matriz[i][j] = atof(argv[count]);
			count++;
		}
	}
	return (matriz);
}

static double **matrix_create(int rows, int cols)
{
	double **matriz = (double **) malloc(sizeof(double *) * rows);
	unsigned int count = 0;

	for (int i = 0; i < rows; i++)
	{
		matriz[i] = (double *) malloc (cols * sizeof(double));
	}
	return (matriz);
}

static double **matrix_multiplication(double **m1, double **m2, int rows1, int cols1, int cols2)
{
	double **res;
	double aux;

	res = matrix_create(rows1, cols2);
	for (int i = 0; i < cols2; i++)
	{
		for (int j = 0; j < rows1; j++)
		{
			aux = 0;
			for (int k = 0; k < cols1; k++)
			{
				aux += m1[j][k] * m2[k][i];
			}
			res[j][i] = aux;
		}
	}
	return (res);
}
