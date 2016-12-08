#include "holberton.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
* append_text_to_file - appends a text at the end of a file
* @filename: name of file to add text to
* @text_content: is a NULL terminated string to add to the file
* Return: 1 on success, -1 on failure
**/
int append_text_to_file(const char *filename, char *text_content)
{
	ssize_t count;
	int apnd, i, cls;

	if (filename == NULL)
		return (-1);

	apnd = open(filename, O_WRONLY | O_APPEND);
	if (apnd == -1)
		return (-1);

	if (text_content == NULL)
	{
		close(apnd);
		return (1);
	}
	/* calculate length of text_content */
	while (text_content[i] != '\0')
		i++;

	count = write(apnd, text_content, i);
	if (count == -1 || count != i)
		return (-1);

	cls = close(apnd);
	if (cls == -1)
		return (-1);
	return (1);
}
