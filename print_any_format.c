#include "main.h"
#include <unistd.h>


/**
 * _printf - Custom printf function mimicking printf
 * @format: prints the given arguments, c, s, %
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
	while (format[index])
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
		while (*my_string)
		{
			write(1, my_string, 1);
			my_string++;
			len_counter++;
	
		}
			break;
		}
		case '%':
			write(1, &format[index], 1);
			len_counter++;
			break;
		case 'd':
		case 'i':
		{
			int num = va_arg(my_list, int);
			char buffer[32];
			int digit_count = 0;
			int is_negative =0;
			int i;

		if (num == 0)
		{
			write(1, "0", 1);
			len_counter++;
			break;
		}

		if (num < 0)
		{
			is_negative = 1;
			num = -num;
		}
		while (num != 0)
		{
			buffer[digit_count++] = '0' + (num % 10);
			num /= 10;
		}
		if (is_negative)
		{
			buffer[digit_count++] = '-';
		}

		for (i = digit_count -1; i >= 0; i--)
		{
			write(1, &buffer[i], 1);
			len_counter++;
		}
			break;
		}
		default:
			write(1, "%", 1);
			write(1, &format[index], 1);
			len_counter += 2;
		}	break;
		}
		else
		{
			write(1, &format[index], 1);
                        len_counter++;
		}
		index++;
	}
	va_end(my_list);
	return (len_counter);
}
