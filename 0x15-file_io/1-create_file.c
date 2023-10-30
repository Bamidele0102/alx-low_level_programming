#include "main.h"
/**
 * create_file - Creates a file and writes text content to it.
 * @filename: The name of the file to create.
 * @text_content: Text content to write to the file (a null-terminated string).
 *
 * Return: On success, returns 1. On failure, returns -1.
 */


int create_file(const char *filename, char *text_content)
{
	int fd, text_len, write_result;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (text_content == NULL)
	{
		close(fd);
		return (1);
	}

	text_len = 0;
	while (text_content[text_len])
		text_len++;

	write_result = write(fd, text_content, text_len);
	close(fd);

	if (write_result == -1 || write_result != text_len)
		return (-1);

	return (1);
}
