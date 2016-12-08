#include "holberton.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

/**
* copy_file - copies the content of a file to another file
* @file1: file to copy from
* @file2: file to copy to
* Return: nothing, or exit on failure
**/
void copy_file(const char *file1, char *file2)
{
	ssize_t count, count_out;
	int f1, f2, fcls1, fcls2;
	char bufr[1204];

	f1 = open(file1, O_RDONLY);
	if (f1 == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", file1);
		exit(98);
	}
	f2 = open(file2, O_WRONLY | O_CREAT, 00664);
	if (f2 == -1)
		dprintf(2, "Error: Can't write to %s\n", file2), exit(99);

	count = 1;
	while (count > 0)
	{
		count = read(f1, bufr, 1204);
		if (count == -1)
		{
			dprintf(2, "Error: Can't read from file %s\n", file1);
			exit(98);
		}
		count_out = write(f2, bufr, count);
		if (count_out == -1)
		{
			dprintf(2, "Error: Can't write to %s\n", file2);
			exit(99);
		}
	}
	fcls1 = close(f1);
	if (fcls1 == -1)
		dprintf(2, "Error: Can't close fd %d\n", fcls1), exit(100);
	fcls2 = close(f2);
	if (fcls2 == -1)
		dprintf(2, "Error: Can't close fd %d\n", fcls2), exit(100);
}

/**
* main - copies the content of a file to another file
* @argc: number of arguements
* @argv: pointer to arguement
* Return: 0 on success, or exit with error message
**/
int main(int argc, char **argv)
{
	if (argc != 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n");
		exit(97);
	}
	copy_file(argv[1], argv[2]);
	return (0);
}
