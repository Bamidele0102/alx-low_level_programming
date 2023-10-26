#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: Pointer to a string of 0 and 1 chars.
 *
 * Return: The converted number, or 0 if invalid input.
 */
unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int result = 0;

	if (b == NULL)
		return (0);

	for (i = 0; b[i] != '\0'; i++)
	{
		char current_char = b[i];

		if (current_char != '0' && current_char != '1')
			return (0);

		result = (result << 1) | (current_char - '0');
	}

	return (result);
}
