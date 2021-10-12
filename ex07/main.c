#include "parser.h"

int main(int argc, char **argv)
{
	FILE *file;

	if (argc > 1)
	{
		file = fopen(argv[1], "r");
		return (parser(file));
	}
	else
		return (-1);
}
