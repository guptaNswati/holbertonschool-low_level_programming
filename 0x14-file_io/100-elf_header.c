#include "holberton.h"
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>

/**
* elf_HeaderRead - helper function to open, read and write the elf
* @filename: elf file to be read
* Return: 0 on success, -1 on failure
**/
int elf_HeaderRead(const char *filename)
{
	ElfHdr *header;
	FILE *file;
	size_t result, i, h_size;

	file = fopen(filename, "rb");
	if (file == NULL)
		return (-1);

	h_size = sizeof(ElfHdr) * 1024;
	header = malloc(h_size);
	if (header == NULL)
		return (-1);
	result = fread(header, 1, h_size, file);

	/* check if file is an elf file or not */
	if (header->e_ident[0] == 0x7f &&
	    header->e_ident[1] == 'E' &&
	    header->e_ident[2] == 'L' &&
	    header->e_ident[3] == 'F')
	{
		/* write contents to output file */
		printf("%s\n", header->e_ident);
/*		for (i = 0; i < 16; i++)
		{
			printf("%c\n", header->e_ident[i]);
			} */
		printf("%u\n", header->e_type);
		printf("%ud\n", header->e_version);
		printf("%ud\n", header->e_entry);
	}
	fclose(file);
	free(header);
	return (0);
}

/**
* main - displays the information contained in the ELF header
* refer http://www.skyfree.org/linux/references/ELF_Format.pdf
* @argc: number of args
* @argv: pointer to arg
* Return: 0 on success or exit with 98 on failure
**/
int main(int argc, char **argv)
{
	int res;

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s <ELF_FILE>\n", argv[0]);
		exit(98);
	}
	res = elf_HeaderRead(argv[1]);
	if (res == -1)
	{
		fprintf(stderr, "Unable to read elf\n");
		exit(98);
	}
	return (0);
}
