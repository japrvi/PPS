#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	FILE *file;
	char *aux;

	if (argc == 2)
	{
		file = fopen(argv[1],"r");
		if(file != NULL)
		{
			aux = (char *) malloc(80);
			while (fgets(aux, 80, file) != NULL)
			{
				if (*aux != '\n')
					printf("%s\n", aux);
			}
		}
	}
	else
	{
		printf("ERROR\n");
		return(-1);
	}
	return(0);
}
