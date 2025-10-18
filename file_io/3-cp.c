#include "main.h"
#include <stdio.h>

void close_file(int fd);
void error_file(int error_code, char *filename, int fd);

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, bytes_read, bytes_written;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_file(98, argv[1], -1);

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
		error_file(99, argv[2], fd_from);

	while ((bytes_read = read(fd_from, buffer, 1024)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			error_file(99, argv[2], fd_from);
		}
	}

	if (bytes_read == -1)
		error_file(98, argv[1], fd_from);

	close_file(fd_from);
	close_file(fd_to);

	return (0);
}

/**
 * close_file - closes a file descriptor
 * @fd: file descriptor to close
 */
void close_file(int fd)
{
	int result;

	result = close(fd);
	if (result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * error_file - handles file errors
 * @error_code: error code to exit with
 * @filename: name of the file
 * @fd: file descriptor to close if needed
 */
void error_file(int error_code, char *filename, int fd)
{
	if (error_code == 98)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
	else if (error_code == 99)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);

	if (fd != -1)
		close_file(fd);

	exit(error_code);
}
