#include <stdlib.h>
#include <stdio.h>

/**
 * main- print the number of arguments passed to the program
 *
 * @argc: stands for argument count
 *
 * @argv:is a one-dimentional array of strings
 *
 * Return: Always 0 (Success)
 *
 */
int main(int argc, char *argv[])
{
	int a;

	for (a = 0; a < argc; a++)
	{
		printf("%s\n", argv[a]);
	}
	return (0);
}
