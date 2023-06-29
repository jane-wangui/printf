#include "main.h"
#include <stdarg.h>

int _printf(const char *format, ...)
	{
	va_list my_list;
	int index = 0;
	int len_counter = 0;

	if (format == NULL)
		return -1;

	va_start(my_list, format);
	while (format[index] != '\0')
	{
	if (format[index] == '%')
	{
		index++;
		if(format[index] == 'c')
		{
			char my_char = va_arg(my_list, int);
			write(1, &my_char, 1);
			len_counter++;
		}
	}
	else
	{
	write(1,&format[index],1);
	len_counter++;
	}
	index++;
	}
	va_end(my_list);
	char x = '\n';
	write(1,&x, 1);
	return (len_counter);
	}
