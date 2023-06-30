#include "main.h"
#include <stdio.h>
#include <unistd.h>

/**
 * _printf - Custom printf function  mimickinf printf
 * @format: prints the given srgument, c, s, %
 * Return: returns length of the formatted characters
 */

int _printf(const char *format, ...)
{
	int index = 0;
	int len_counter = 0;
	va_list my_list;

	if (format == NULL)
		return (-1);

	va_start(my_list, format);
	while (format[index] != '\0')
	{
	if (format[index] == '%')
	{
		index++;
		switch (format[index])
		{
		case 'c':
		{
			char my_char = va_arg(my_list, int);

			write(1, &my_char, 1);
			len_counter++;
			break;
		}
		case 's':
		{
			char *my_string = va_arg(my_list, char *);
			if (!my_string)
				my_string = "(nil)";
			write(1, &my_string, 1);
			break;
		}
		}
		}
	else
	{
		write(1, &format[index], 1);
		len_counter++;
	}
		index++;
	}
	va_end(my_list);
	char x = '\n';

	return (len_counter);
}
