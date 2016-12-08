#ifndef FILE_IO
#define FILE_IO

#include <stdlib.h>

/**
* struct ElfHdr - struct for defining header items
* @e_ident: ELF Identification for machine-independent data to decode and
* interpret the file’s contents
* @e_type: identifies the object file type
* @e_version: identifies the object file version
* @e_entry: for the virtual address to which the system first transfers control
**/
typedef struct ElfHdr{
        unsigned char  e_ident[16];
        unsigned short e_type;
        unsigned int e_version;
        unsigned int e_entry;
} ElfHdr;

int _putchar(char c);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void copy_file(const char *file1, char *file2);
int elf_HeaderRead(const char *filename);
#endif
