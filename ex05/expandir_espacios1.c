#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int nspaces;
	int aux;
	int i;

	if (argc > 2)
	{
		i = 1;
		nspaces = atoi(argv[1]);
		aux = nspaces;
		while (argc > 2)
		{
			printf("%s", argv[++i]);
			while (nspaces)
			{
				printf(" ");
				nspaces--;
			}
			nspaces = aux;
			argc--;
		}
	}
	else
		return (1);
}
