#include "holberton.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
* read_textfile - reads a text file and print it to the POSIX standard output
* @filename: file to be read
* @letters: number of letters it should read and print
* Return: actual number of letters it could read and print or if fails 0
**/
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t count, count_out;
	int opn, cls;
	char *bufr;

	if (filename == NULL)
		return (0);

	bufr = malloc(sizeof(char) * letters);
	if (bufr == NULL)
		return (0);

	opn = open(filename, O_RDONLY);
	if (opn == -1)
	{
		freee(bufr);
		return (0);
	}

	/* for the number of bytes read */
	count = read(opn, bufr, letters);
	/* zero indicates end of file and -1 is returned when an error occurs */
	if (count == -1)
	{
		free(bufr);
		return (0);
	}

	count_out = write(1, bufr, count);
	if (count_out == -1)
	{
		free(bufr);
		return (0);
	}

	cls = close(opn);
	if (cls == -1)
	{
		free(bufr);
		return (0);
	}
	free(bufr);
	return (count_out);
}
