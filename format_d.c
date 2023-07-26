/*
 * print_int: Prints an integer using specifier d
 * @int -  Int to print
 * Return - the integer length
 */
int print_int(va_list args)
{
	int counter = 1,
	int unsigned_int = 0;
	unsigned int temp_int = 0;

	temp_int = va_arg(args, int);
	unsigned_int = temp_int;

	if (unsigned_int < 0)
		
		unsigned_int = unsigned_int * -1;
		temp_int = unsigned_int;
		counter++;
	}
	while (temp_int > 9)
	{
		temp_int = temp_int / 10;
		counter++;
	}
	print_int(unsigned_int);
	return (counter);
}
