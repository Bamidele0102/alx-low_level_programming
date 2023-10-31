#include "main.h"
#define BUFSIZE 1024

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 *
 * Return: 0 on success, other values on failure.
 */
int main(int argc, char *argv[])
{
	const char *file_from, *file_to;
	int fd_from, fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		return (97);
	}

	file_from = argv[1];
	file_to = argv[2];

	fd_from = open_source_file(file_from);
	if (fd_from < 0)
		return (fd_from);

	fd_to = create_or_open_destination_file(file_to);
	if (fd_to < 0)
	{
		close_file(fd_from);
		return (fd_to);
	}

	copy_data(fd_from, fd_to);

	close_file(fd_from);
	close_file(fd_to);

	return (0);
}

/**
 * open_source_file - Open the source file for reading.
 * @file_from: The path to the source file.
 *
 * Return: The file descriptor on success, -1 on failure.
 */
int open_source_file(const char *file_from)
{
	int fd_from = open(file_from, O_RDONLY);

	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		return (98);
	}
	return (fd_from);
}

/**
 * create_or_open_destination_file - Create the destination file for writing.
 * @file_to: The path to the destination file.
 *
 * Return: The file descriptor on success, -1 on failure.
 */
int create_or_open_destination_file(const char *file_to)
{
	int fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);

	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		return (99);
	}
	return (fd_to);
}

/**
 * copy_data - Copy data from source file to destination file.
 * @fd_from: The file descriptor of the source file.
 * @fd_to: The file descriptor of the destination file.
 */
void copy_data(int fd_from, int fd_to)
{
	ssize_t bytes_read;
	char buffer[BUFSIZE];

	while ((bytes_read = read(fd_from, buffer, BUFSIZE)) > 0)
	{
		ssize_t bytes_written = write(fd_to, buffer, bytes_read);

		if (bytes_written == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to destination file\n");
			exit(99);
		}
	}

	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from source file\n");
		exit(98);
	}
}

/**
 * close_file - Close a file.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
	int close_result = close(fd);

	if (close_result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
