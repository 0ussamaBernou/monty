#include "monty.h"

int main(int argc, char *argv[])
{
	char *filename;
	/*handle cmdline args */
	if (argc != 2)
		usage_err();

	/* read the file in the args */
	filename = argv[1];
	read_file(filename);

	/* tokenize each line */
	/* parse the tokens */
}
