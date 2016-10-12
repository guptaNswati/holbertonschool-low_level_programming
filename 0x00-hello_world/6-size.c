#include <stdio.h>

/*
 * Prints the size of various data types based on compling and running computer
 */
int main(void)
{
	printf("Size of a char: %ld byte(s)\n",sizeof(char));
	printf("Size of an int: %ld byte(s)\n",sizeof(int));
	printf("Size of a long int: %ld byte(s)\n",sizeof(long int));
	printf("Size of a long long int: %ld byte(s)\n",sizeof(long long int));
	printf("Size of a float: %ld byte(s)\n",sizeof(float));
	return(0);
}
