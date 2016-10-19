#include "holberton.h"

/**
* jack_bauer - prints every minute of the day of Jack Bauer,
* starting from 00:00 to 23:59
* Return: nothing
**/

void jack_bauer(void)
{
	int start_time, end_time;

	start_time = 0;

	while (start_time < 24)
	{
		end_time = 0;

		while (end_time < 60)
		{
			_putchar(start_time / 10 + '0');
			_putchar(start_time % 10 + '0');
			_putchar(':');
			_putchar(end_time / 10 + '0');
			_putchar(end_time % 10 + '0');
			_putchar('\n');

			end_time++;
		}
		start_time++;
	}
}
