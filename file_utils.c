#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_file(char *filename)
{
	ssize_t nread;
	uint line_num;
	size_t len = 0;
	char *linebuf = NULL;
	FILE *fd;

	fd = fopen(filename, "r");
	if (!fd || !filename)
		open_err(filename);

	nread = getline(&linebuf, &len, fd);
	for (line_num = 1; nread != -1; line_num++)
	{
		linebuf[nread - 1] = '\0';
		parseline(linebuf, line_num);
		nread = getline(&linebuf, &len, fd);
	}

	free(linebuf);
}

void parseline(char *linebuf, uint line_num)
{
	const char *delim = " ";
	char *opcode;
	char *value;

	opcode = strtok(linebuf, delim);
	value = strtok(NULL, delim);

	/* value = removeTrailingNewline(value);*/

	printf("opcode: %s, value: %s\n", opcode, value);
	run_instuction(opcode, value, line_num);
}
