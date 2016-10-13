#include <stdio.h>

/**
 * main - Prints all numbers of base 10, without using type char
 * Return: 0
 **/

int main(void)
{
        int num;

        for(num = 0; num <= 9; num++)
        {
                putchar(num);
        }

        putchar('\n');

        return (0);
}
