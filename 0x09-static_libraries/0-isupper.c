#include "main.h"

/**
 * _isupper - uppercase letters are checked by the function
 * @c: characters to check
 *
 * Return: 0 or 1
 */

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
