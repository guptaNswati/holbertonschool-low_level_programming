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
	ssize_t count, i;
	int opn;
	char bufr[5000], *bufPointr;

	opn = open(filename, O_RDWR);
	if (opn < 0)
		return (0);

	bufPointr = bufr;
	/* for the number of bytes read */
	count = read(opn, bufPointr, letters);

	/* zero indicates end of file and -1 is returned when an error occurs */
	if (count < 0)
		return (0);

	for (i = 0; i < count; i++)
		_putchar(bufr[i]);

	close(opn);
	return (i);
}
