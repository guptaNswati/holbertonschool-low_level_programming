#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct ElfHdr{
        unsigned char  e_ident[16];
        unsigned short e_type;
        unsigned int e_version;
        unsigned int e_entry;
} ElfHdr;

int elf_HeaderRead(const char *filename)
{
	ElfHdr header;
	FILE *file, *outpt;
	char outFile[1024];

	file = fopen(filename, "rb");
	if (file)
	{
		fread(&header, 1, sizeof(header), file);
		/* check if file is an elf file or not */
		if (header.e_ident[0] == 0x7f &&
		    header.e_ident[1] == 'E' &&
		    header.e_ident[2] == 'L' &&
		    header.e_ident[3] == 'F')
		{
			/* write contents to output file */
			outpt = fopen(outFile, "wb");
			if (outpt)
			{
				fwrite(&header, 1, sizeof(header), outpt);
				fclose(outpt);
				fclose(file);
				return (1);
			}
			return (-1);
		}
	}
	return (-1);
}

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
