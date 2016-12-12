#include "holberton.h"

/**
* create_file - creates a file with read&writre permission and writes to it
* @filename: name of file to be created
* @text_content: is a NULL terminated string to write to the file
* Return: 1 on success, -1 on failure
**/
int create_file(const char *filename, char *text_content)
{
	ssize_t count;
	int crt, i;

	if (filename == NULL)
		return (-1);
/* create using open in 1 step */
	crt = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (crt == -1)
		return (-1);

	if (text_content)
	{
		/* calculate length of text_content */
		while (text_content[i] != '\0')
			i++;

		count = write(crt, text_content, i);
		if (count == -1 || count != i)
			return (-1);
	}
	close(crt);
 	return (1);
}
