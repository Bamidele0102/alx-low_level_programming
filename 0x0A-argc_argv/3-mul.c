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
	int y, z;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	y = atoi(argv[1]);
	z = atoi(argv[2]);
	printf("%d\n", y * z);
	return (0);
}
