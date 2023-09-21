#include "monty.h"

stack_t *stack_h = NULL;

int main(int argc, char *argv[])
{
	char *filename;

	/*handle cmdline args */
	if (argc != 2)
		usage_err();

	/* read the file in the args */
	filename = argv[1];
	read_file(filename);

	return (EXIT_SUCCESS);
}
