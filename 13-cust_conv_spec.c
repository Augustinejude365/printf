#include "main.h"

/**
 * is_printable - A function that evaluates if a character is
 * printable.
 * @c: Character to be evaluated.
 * Written by Jude Augustine.
 * Return: 1 if c is printable, returns 0 otherwise.
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append ASCII code in hexadecimal to buffer.
 * @buffer: Array of characters.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * JA codes.
 * Return: Always 3 (Upon success).
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - A function that verifies if a char is a digit or not.
 * @c: Character to be verified.
 * JA codes.
 * Return: 1 if c is a digit, otherwise return 0.
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - A function that casts a number to the
 * specified size.
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 * JA codes.
 * Return: Casted value of number.
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - A function that casts a number to the specified size.
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 * JA codes.
 * Return: Casted value of number.
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
