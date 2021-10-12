#ifndef PARSER_H
# define PARSER_h
# define MaxLinea 2048
# define MaxFields 15
# include <string.h>
# include <stdlib.h>
# include <stdio.h>

int	parser(FILE *file);
void	read_line(FILE *file, char **content);

#endif
