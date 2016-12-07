#include "holberton.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
* create_file - creates a file with read&writre permission and writes to it
* @filename: name of file to be created
* @text_content: is a NULL terminated string to write to the file
* Return: 1 on success, -1 on failure
**/
int create_file(const char *filename, char *text_content)
{
	ssize_t count;
	int crt, opn, i;

	if (filename == NULL)
		return (-1);
/* first lets create in two steps */
	crt = creat(filename, S_IRUSR | S_IWUSR);
	if (crt == -1)
		return (-1);
	opn = open(filename, O_WRONLY);
	if(opn == - 1)
		return (-1);
	if (text_content == NULL)
		return (1);

	/* calculate length of text_content */
	while (text_content[i] != '\0')
		i++;

	count = write(crt, text_content, i);
	if (count == -1)
		return (-1);
	close(opn);
	close(crt);
	return (1);
}
