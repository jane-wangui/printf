#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/*
 * print_any_format: prints anyy format
 * @format: prints the given srgument, c, s, %
 */

int _printf(const char *format, ...)
{
	int index = 0;
	char *str, *sep = "";

	va_list list;

	va_start(list, format);
	
	while (*format != '\0'){

	if (*format == '%'){

		formatt++;

		switch (format[index])
		{
			case 'c':{
					
				int charactarer = va-arg(args, int);
				index =+ printf("%c", character
					       );break;
				 }
			case 's':
			{
				char *str = va_arg(args, char *);
				index += printf("%s", str);
				break;

			}
		else {
			printf(*format[index]);
			index++;
		}

		va-end(args);
		
		return (index);

		}
