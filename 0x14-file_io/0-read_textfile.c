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
	ssize_t count;
	int opn, i;
	char bufr[1024], *bufPointr;

	if (filename == NULL)
		return (0);
	opn = open(filename, O_RDWR);

	bufPointr = bufr;
	count = read(opn, bufPointr, letters);
	if (count == 0)
		return (0);

	for (i = 0; i < count; i++)
	{
		_putchar(bufr[i]);
	}

	close(opn);
	return (i);
}
