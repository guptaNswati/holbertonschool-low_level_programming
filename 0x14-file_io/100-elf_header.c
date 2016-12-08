#include "holberton.h"
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <elf.h>

/**
* print_type - prints elf header type information
* @value: unsigned int for specifying the details
* Return: nothing
**/
void print_typ(unsigned int value)
{
	printf("Type:          ");
	if (value == 0)
	{
		printf("NONE (No file type)\n");
		return;
	}
	if (value == 1)
	{
                printf("REL (Relocatable file)\n");
                return;
        }
	if (value == 2)
	{
                printf("EXEC (Executable file)\n");
                return;
        }
	if (value == 3)
	{
                printf("DYN (Shared object file)\n");
                return;
        }
	if (value == 4)
	{
                printf("CORE (Core file)\n");
                return;
        }
	if (value == 65280)
	{
                printf("LOPROC (Processor-specific)\n");
                return;
        }
	if (value == 65535)
	{
                printf("HIPROC (Processor-specific)\n");
                return;
        }
}
/**
 * print_os - prints elf header OS/ABI information
 * @value: unsigned int for specifying the details
 * Return: nothing
 **/
void print_os(unsigned int value)
{
	printf("OS/ABI:          ");
	if (value == 0)
	{
		printf("System V\n");
		return;
	}
	if (value == 1)
	{
                printf("HP-UX\n");
                return;
        }
	if (value == 2)
	{
                printf("NetBSD\n");
                return;
        }
	if (value == 3)
	{
                printf("Linux\n");
                return;
        }
	if (value == 6)
	{
                printf("Solaris\n");
                return;
        }
	if (value == 7)
	{
                printf("AIX\n");
                return;
        }
	if (value == 8)
	{
                printf("IRIX\n");
                return;
        }
	if (value == 9)
        {
                printf("FreeBSD\n");
                return;
        }
	if (value == 12)
        {
                printf("OpenBSD\n");
                return;
        }
	if (value == 13)
        {
                printf("OpenVMS\n");
                return;
        }
	if (value == 14)
        {
                printf("NonStop Kernel\n");
                return;
        }
	if (value == 15)
        {
                printf("AROS\n");
                return;
        }
	if (value == 16)
        {
                printf("Fenix OS\n");
                return;
        }
	if (value == 17)
        {
                printf("Cloud ABI\n");
                return;
        }
	if (value == 83)
        {
                printf("Sortix\n");
                return;
        }
	printf("<unknown: %u>\n", value);
}
/**
* print_clas - prints elf header class information
* @value: unsigned int for specifying the details
* Return: nothing
**/
void print_clas(unsigned int value)
{
	printf("Class:          ");
	if (value == 0)
	{
		printf("Invalid\n");
                return;
        }
        if (value == 1)
        {
                printf("ELF32\n");
                return;
        }
	if (value == 2)
	{
		printf("ELF64\n");
		return;
	}
}
/**
* print_dta - prints elf header data information
* @value: unsigned int for specifying the details
* Return: nothing
**/
void print_dta(unsigned int value)
{
	printf("Data:          ");
	if (value == 0)
	{
                printf("Invalid data encoding\n");
                return;
        }
	if (value == 1)
	{
		printf("2's complement, little endian\n");
		return;
	}
	if (value == 2)
	{
                printf("2's complement, big endian\n");
                return;
        }
}
/**
* print_vrsn - prints elf header version information
* @value: unsigned int for specifying the details
* Return: nothing
**/
void print_vrsn(unsigned int value)
{
	printf("Version:          ");
	if (value == 0)
	{
		printf("%u(Invalid)\n", value);
		return;
	}
	if (value == 1)
	{
                printf("%u(Current)\n", value);
                return;
        }
}

/**
* elf_HeaderRead - helper function to open, read and write the elf
* @filename: elf file to be read
* Return: 0 on success, -1 on failure
**/
int elf_HeaderRead(const char *filename)
{
	ElfHdr *header;
	FILE *file;
	size_t i, h_size;
	ssize_t result;

	file = fopen(filename, "rb");
	if (file == NULL)
		return (-1);

	h_size = sizeof(ElfHdr) * 1024;
	header = malloc(h_size);
	if (header == NULL)
		return (-1);
	result = fread(header, 1, h_size, file);
	if (result == -1)
		return (-1);
	/* check if file is an elf file or not */
	if (header->e_ident[0] == 0x7f &&
	    header->e_ident[1] == 'E' &&
	    header->e_ident[2] == 'L' &&
	    header->e_ident[3] == 'F')
	{
		/* write contents to output file */
		printf("ELF Header:\n");
		printf("Magic:     %x %x %x %x", header->e_ident[0],
		       header->e_ident[1], header->e_ident[2],
		       header->e_ident[3]);
		for (i = 4; i < 16; i++)
			printf("0%x ", header->e_ident[i]);
		printf("\n");
		print_clas((unsigned int)header->e_ident[EI_CLASS]);
		print_dta((unsigned int)header->e_ident[EI_DATA]);
		print_vrsn(header->e_version);
		print_os((unsigned int)header->e_ident[EI_OSABI]);
		printf("ABI Version:     %u\n", header->e_ident[EI_ABIVERSION]);
		print_typ(header->e_type);
		printf("Entry point address:          0x%x\n", header->e_entry);
		fclose(file);
		free(header);
		return (0);
	}
	return (-1);
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
