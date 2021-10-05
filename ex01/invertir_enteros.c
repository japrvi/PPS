#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

const int MAX = 1000;

static unsigned int ft_strlen_number(char **s, int argc);
static int is_numeric(char *s);

static unsigned int ft_strlen_number(char **s, int argc)
{
	unsigned int i = 1;
	char encontrado = 1;
	while (encontrado && i < argc)
	{
		if (!is_numeric(s[i]))
			encontrado = 0;
		else
			i++;
	}
	return (i);
}

static int is_numeric(char *s)
{
	unsigned int i = 0;
	char encontrado = 1;

	if ((s[i] == '+' || s[i] == '-') && (s[i + 1] <= '9' && s[i + 1] >= '0'))
		i++;
	while (encontrado && s[i])
	{
		if (s[i] < '0' || s[i] > '9')
		{
			encontrado = 0;
			i = 0;
		}
		else
			i++;
	}
	return (i);
}

int main (int argc, char **argv)
{
	int num[MAX];
	int tope;
	unsigned int i;

	if (argc > 1)
	{
		i = 0;
		tope = ft_strlen_number(argv, argc);
		if (tope > MAX)
			tope = MAX;
		tope--;
		while (tope >= 1)
		{
			num[i] = atoi(argv[tope]);
			printf("%d\n", num[i]);
			tope--;
			i++;	
		}
	}
}
