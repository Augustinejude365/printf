#include "main.h"

int handle_write_char(char c, char buffer[], int flags, int width,
int precision, int size);
int write_unsgnd(int is_negative, int index, char buffer[], int flag,int width, int precision, int size);

/***************A function that writes handle***********/
/**
 * handle_write_char -A function that prints a string.
 * @c: Character type.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags.
 * @width: Calculated the width.
 * @precision: Precision specifier.
 * @size: Size specifier.
 * Written by Jude Augustine.
 * Return: Number of characters printed.
 */
int handle_write_char(char c, char buffer[], int flags, int width,
int precision, int size)
{
	int k = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	buffer[k++] = c;
	buffer[k] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (k = 0; k < width - 1; k++)
			buffer[BUFF_SIZE - k - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) + write(1,
&buffer[BUFF_SIZE - k - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - k - 1],
width - 1) + write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/*********** A function that writes number**********************/
/**
 * write_number - A function that Prints a string.
 * @is_negative: List of arguments.
 * @index: character type.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags.
 * @width: Calculates width.
 * @precision: Precision specifier.
 * @size: Size specifier.
 * JA codes.
 * Return: Number of characters printed.
 */
int write_number(int is_negative, int index, char buffer[], int flags
, int width, int precision, int size)
{
	int length = BUFF_SIZE - index - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(index, buffer, flags, width, precision,
length, padd, extra_ch));
}

/**
 * write_num - A function that writes number using a bufffer.
 * @index: Index at which the number starts on the buffer.
 * @buffer: Buffer.
 * @flags: Flags.
 * @width: Width.
 * @prec: Precision specifier.
 * @length: Length of the Number.
 * @padd: Padding character.
 * @extra_c: Extra character.
 * JA codes.
 * Return: Number of printed characters.
 */
int write_num(int index, char buffer[], int flags, int width,
int prec, int length, char padd, char extra_c)
{
	int k, padd_start = 1;

	if (prec == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0' && width == 0)
		return (0);
	if (prec == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		buffer[index] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--index] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (k = 1; k < width - length + 1; k++)
		buffer[k] = padd;
		buffer[k] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
			buffer[--index] = extra_c;
	return (write(1, &buffer[index], length) + write(1, &buffer[1], k - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
			buffer[--index] = extra_c;
	return (write(1, &buffer[1], k - 1) + write(1, &buffer[index], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
			buffer[--padd_start] = extra_c;
	return (write(1, &buffer[padd_start], k - padd_start) +
write(1, &buffer[index], length - (1 - padd_start)));
		}
	}
	if (extra_c)
	buffer[--index] = extra_c;
	return (write(1, &buffer[index], length));
}

/**
 * write_unsgnd - A function that writes an unsigned number.
 * @is_negative: Number indicating if the num is negative.
 * @index: Index at which the number starts in the buffer.
 * @buffer: Array of characters.
 * @flags: Flags specifiers.
 * @width: Width specifier.
 * @precision: Precision specifier.
 * @size: Size specifier.
 * JA codes.
 * Return: Number of written characters.
 */
int write_unsgnd(int is_negative, int index, char buffer[],
int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - index - 1, k = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		return (0);
	if (precision > 0 && precision < length)
		padd = ' ';
	while (precision > length)
	{
		buffer[--index] = '0';
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (width > length)
	{
		for (k = 0; k < width - length; k++)
			buffer[k] = padd;
		buffer[k] = '\0';
		if (flags & F_MINUS)
			{
			return (write(1, &buffer[index], length) +
write(1, &buffer[0], k));
			}
		else
		{
			return (write(1, &buffer[0], k) +
write(1, &buffer[index], length));
		}
	}
	return (write(1, &buffer[index],
length));
}

/**
 * write_pointer - A function that writes a memory address.
 * @buffer: Arrays of characters.
 * @index: Index at which the number starts in the buffer.
 * @length: Length of number.
 * @width: Width specifier.
 * @flags: Flags specifier.
 * @padd: Character representing the padding.
 * @extra_c: Character representing extra character.
 * @padd_start: Index at which padding will start.
 * JA codes.
 * Return: Number of written characters.
 */
int write_pointer(char buffer[], int index, int length, int width,
int flags, char padd, char extra_c, int padd_start)
{
	int k;

	if (width > length)
	{
		for (k = 3; k < width - length + 3; k++)
			buffer[k] = padd;
		buffer[k] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (extra_c)
				buffer[--index] = extra_c;
			return (write(1, &buffer[index], length) +
write(1, &buffer[3], k - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (extra_c)
				buffer[--index] = extra_c;
			return (write(1, &buffer[3], k - 3) +
write(1, &buffer[index], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], k - padd_start)
	+ write(1, &buffer[index], length - (1 - padd_start) - 2));
		}
	}
	buffer[--index] = 'x';
	buffer[--index] = '0';
	if (extra_c)
		buffer[--index] = extra_c;
	return (write(1, &buffer[index], BUFF_SIZE - index - 1));
}
