#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_file(char *filename)
{
	long nread;
	uint line_num;
	size_t len = 0;
	char *linebuf = NULL;

	FILE *fd = fopen(filename, "r");
	if (!fd || !filename)
		open_err(filename);

	for (line_num = 1; (nread = getline(&linebuf, &len, fd) != -1);
	     line_num++)
	{
		parseline(linebuf, line_num);
	}

	free(linebuf);
}

void parseline(char *linebuf, uint line_num)
{
	const char *delim = "\n ";
	char *opcode;
	char *value;

	opcode = strtok(linebuf, delim);
	value = strtok(NULL, delim);

	run_instuction(opcode, value, line_num);
}
