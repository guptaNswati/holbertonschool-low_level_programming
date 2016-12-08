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
	int crt, i, cls;

	if (filename == NULL)
		return (-1);
/* create using open in 1 step */
	crt = open(filename, O_WRONLY | O_CREAT, 00600);
	if (crt == -1)
		return (-1);

	/* calculate length of text_content */
	while (text_content[i] != '\0')
		i++;

	count = write(crt, text_content, i);
	if (count == -1)
		return (-1);

	cls = close(crt);
	if (cls == -1)
		return (-1);
	return (1);
}
