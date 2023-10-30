#include "main.h"
/**
 * append_text_to_file - Appends text content to an existing file.
 * @filename: The name of the file to append to.
 * @text_content: Text content to append to the file(a null-terminated string).
 *
 * Return: On success, returns 1. On failure, returns -1.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd, text_len, write_result;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
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
