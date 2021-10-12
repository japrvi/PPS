#include "parser.h"

int parser(FILE *file)
{
	int i = 0;
	char *header[MaxFields + 1];
	char *content[MaxFields + 1];
	read_line(file,header);
	read_line(file, content);

	while (content != NULL)
	{
		while (header[i])
		{
			printf("%s: %s; ", header[i], content[i]);
			i++;
		}
		read_line(file, content);
	}
	return (1);
}

void	read_line(FILE *file, char **content)
{
	char *buf = (char *) malloc(2048);
	char *aux;
	int i = 0;

	if (fgets(buf, 2048, file) != NULL)
	{
		aux = strtok(buf, ",\0");
		while(aux)
		{
			content[i] = strcpy(content[i++], (const char *) aux);
			aux = strtok(NULL, ",\0");
		}
		content[i] == NULL;
	}
	free(buf);
}
