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
	
	if (format)
	{
		while (format[index])
		{
			switch (format[index])
			{
				case 'c':
					printf (
