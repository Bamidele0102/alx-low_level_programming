/**
 * main - Copy the content of one file to another.
 * @argc: The number of command-line arguments.
 * @argv: An array containing the command-line arguments.
 *
 * Return: 0 on success, non-zero on failure.
 */
int main(int argc, char *argv[])
{
	/* Check for the correct number of command-line arguments */
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (97);
	}

	/* Get source and destination file paths */
	const char *file_from = argv[1];
	const char *file_to = argv[2];

	/* Open the source and destination files */
	int fd_from = open_source_file(file_from);
	int fd_to = create_or_open_destination_file(file_to);

	/* Copy data from source to destination */
	copy_data(fd_from, fd_to);

	/* Close the source and destination files */
	close_file(fd_from);
	close_file(fd_to);

	return (0);
}
