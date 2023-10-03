#include <stdio.h>
#include "main.h"

/**
 * main - prints the name of the program
 *
 * @argc: stands for arguments count
 *
 * @argv: is a one-dimensional array of strings
 *
 * Return: Always 0 (Success)
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", *argv);

	return (0);
}
