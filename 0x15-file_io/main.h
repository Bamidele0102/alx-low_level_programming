#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <elf.h>


int _putchar(char c);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int copy_file(const char *file_from, const char *file_to);
int display_elf_header(const char *elf_filename);int open_source_file(const char *file_from);
int create_or_open_destination_file(const char *file_to);
void copy_data(int fd_from, int fd_to);
void close_file(int fd);

int main(int argc, char *argv[])
{
    if (argc != 3)
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);

    if (copy_file(argv[1], argv[2]) == 0)
        return (0);
    else
        return (1);
}

#endif

