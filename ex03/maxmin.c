#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		float max;
		float min;
		float aux;
		FILE *file = fopen(argv[1], "r");

		if (file != NULL)
		{
			fscanf(file, "%f", &aux);
			if (aux == EOF)
				printf("%10.2f\t%10.2f", 0., 0.);
			else
				max = min = aux;
			while (fscanf(file, "%f", &aux) != EOF)
			{
				if (aux > max)
					max = aux;
				else if (aux < min)
					min = aux;
			}
			printf("%10.2f\t%10.2f\n", max, min);
		}
		else
			return (EXIT_FAILURE);
		fclose(file);
	}
	else
		return (EXIT_FAILURE);
	return (0);
}
