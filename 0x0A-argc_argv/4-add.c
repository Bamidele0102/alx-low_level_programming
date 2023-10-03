#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
	int sum, y, z;

	sum = 0;
	if (argc != 1)
	{
		for (y = 1; y < argc; y++)
		{
			for (z = 0; z < (int)strlen(argv[y]); z++)
			{
				if (!isdigit(argv[y][z]))
				{
					printf("Error\n");
					return (1);
				}
			}
			sum += atoi(argv[y]);
		}
	}
	printf("%d\n", sum);
	return (0);
}
