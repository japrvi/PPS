#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//Prototipos
int	resolver(double a, double b, double c, double *px1, double *px2);

//Funciones

int	main(int argc, char **argv)
{
	double *px1 = (double *) malloc(sizeof(double *));	
	double *px2 = (double *) malloc(sizeof(double *));
	double a, b, c;

	 if (argc > 1)
	 {
		a = atof(argv[1]);
		b = atof(argv[2]);
		c = atof(argv[3]);
		resolver(a, b, c, px1, px2); 
		printf("%f\t%f\n", *px1, *px2);
		return (0);
	 } else
		 return (-1);
}

int	resolver(double a, double b, double c, double *px1, double *px2)
{
	double discriminante = pow(b, 2) - 4 * a * c;

	if (discriminante != NAN)
	{
		if (discriminante < 0)
		{
			*px1 = -(b / (2 * a));
			*px2 = sqrt(-discriminante) / (2 * a);
			printf("Compleja\n");
		} else 
		{
			if (discriminante == 0)
			{
				*px1 = -(b / (2 * a));
				*px2 = NAN;
			} else 
			{
			*px1 = (-b - sqrt(discriminante))/(2 * a);
			*px2 = (-b + sqrt(discriminante))/(2 * a);
			}
			printf("No-Compleja\n");
		}
	} else 
	{
		*px1 = *px2 = NAN;
	}
	return (0);
}
