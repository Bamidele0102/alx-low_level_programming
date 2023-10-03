#include <stdlib.h>
#include <stdio.h>

/**
 * main print the number of arguments passed to the program
 *
 * @argc stands for argument count
 *
 * @argv is a one-dimentional array of strings
 *
 * Return: Always 0 (Success)
 *
 */
int main(int argc, char *argv[])
{
	(void)argv;
	printf("%d\n", argc - 1);
	return (0);
}
