#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char *buffer;
	int nspaces;
	int aux;
	int i;

        if (argc >= 2)
        {
		aux = nspaces = atoi(argv[1]);
		buffer = argv[2];
		i = 0;
		while(buffer[i])
		{
			if (buffer[i] != ' ')
				putchar(buffer[i]);
			if (buffer[i] == ' ')
			{
				while(aux--)
					putchar(' ');
				aux = nspaces;
			}
			i++;
		}
        }
        else
                return (1);
	return (0);
}

