#include "monty.h"

char *removeTrailingNewline(char *str)
{
	int length = strlen(str);

	str = str;
	if (length > 0 && str[length - 1] == '\n')
	{
		str[length - 1] = '\0';
	}
	return str;
}
