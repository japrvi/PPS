#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char *buff;
	char *aux;
	int bf = 0;
	int au = 0;

	if (argc > 1)
	{
		buff = argv[1];
		aux = (char *) malloc(80);
		while (buff[bf])
		{
			if (buff[bf] == '\\')
			{
				if (buff[bf + 1] == 'n')
				{
					aux[au] = '\n';
					au++;
					bf = bf + 2;
				}	
				else if (buff[bf + 1] == 't')
				{
					aux[au] = '\t';
					au++;
					bf =bf + 2;
				}
			}
			else 
				aux[au++] = buff[bf++];
		}
		aux[au] = 0;
		printf("%s", aux);
	}
	else 
		return (-1);
	return (0);
}
