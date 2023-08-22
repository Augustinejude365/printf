#include "main.h"

/************A function that prints characters**************/

/**
 * print_char - A function that prints a character.
 * @types: List of arguments.
 * @buffer: Buffer array to handle print.
 * @flags:  Calculates active flags.
 * @width: Width.
 * @precision: Precision specifier.
 * @size: Size specifier.
 * Written by Jude Augustine.
 * Return: Number of characters printed.
 */
int print_char(va_list types, char buffer[], int flags, int width,
int precision, int size)
{
	char ch = va_arg(types, int);

	return (handle_write_char(ch, buffer, flags, width, precision, size));
}
/*************A function that prints strings***************/
/**
 * print_string - A function that prints a string.
 * @types: List a of arguments.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags.
 * @width: Calculates the width.
 * @precision: Precision specifier.
 * @size: Size specifier.
 * Return: Number of characters printed.
 */
int print_string(va_list types, char buffer[], int flags, int width,
int precision, int size)
{
	int length = 0, k;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
	str = "(null)";
	if (precision >= 6)
	str = "      ";
	}
	while (str[length] != '\0')
	length++;
	if (precision >= 0 && precision < length)
	length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
		write(1, &str[0], length);
		for (k = width - length; k > 0; k--)
		write(1, " ", 1);
		return (width);
		}
		else
		{
		for (k = width - length; k > 0; k--)
		write(1, " ", 1);
		write(1, &str[0], length);
		return (width);
		}
	}
	return (write(1, str, length));
}
/*************A function that prints percentage sign************/
/**
 * print_percent - A function that prints a percentage sign.
 * @types: List of arguments.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags.
 * @width: Calculates width.
 * @precision: Precision specifier.
 * @size: Size specifier.
 * Return: Number of characters printed.
 */
int print_percent(va_list types, char buffer[], int flags, int width,
int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
/*************A function that prints integers**************/
/**
 * print_int - A function that prints integers.
 * @types: List of arguments.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags.
 * @width: Calculates the width.
 * @precision: Precision specifier.
 * @size: Size specifier.
 * Return: Number of characters printed.
 */
int print_int(va_list types, char buffer[], int flags, int width,
int precision, int size)
	{
	int k = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);
	if (n == 0)
	buffer[k--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;
	if (n < 0)
	{
	num = (unsigned long int)((-1) * n);
	is_negative = 1;
	}
	while (num > 0)
	{
	buffer[k--] = (num % 10) + '0';
	num /= 10;
	}
	k++;
	return (write_number(is_negative, k, buffer, flags, width,
precision, size));
}

/*********A function that prints a binary*************/
/**
 * print_binary - A function that prints a binary number.
 * @types: Lista of arguments.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags.
 * @width: Calculates width.
 * @precision: Precision specifier.
 * @size: Size specifier.
 * Return: Numbers of characters printed.
 */
int print_binary(va_list types, char buffer[], int flags,
int width, int precision, int size)
{
	unsigned int n, m, k, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (k = 1; k < 32; k++)
	{
	m /= 2;
	a[k] = (n / m) % 2;
	}
	for (k = 0, sum = 0, count = 0; k < 32; k++)
	{
	sum += a[k];
	if (sum || k == 31)
		{
		char z = '0' + a[k];

		write(1, &z, 1);
		count++;
		}
	}
	return (count);
}
