#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* Flags */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* Sizes */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op.
 * Written by Jude Augustine.
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Struct op.
 * JA codes
 * @fmt: The format.
 * @fm_t: The functions associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i, va_list list,
char buffer[], int flags, int width, int precision, int size);

/****************** Functions  ******************/

/*A function to print chars and strings */
int print_char(va_list types, char buffer[], int flags, int width,
int precision, int size);
int print_string(va_list types, char buffer[], int flags,
int width, int precision, int size);
int print_percent(va_list types, char buffer[], int flags,
int width, int precision, int size);

/*A functions to print numbers*/
int print_int(va_list types, char buffer[], int flags, int width,
int precision, int size);
int print_binary(va_list types, char buffer[], int size,
int precision, int flags, int width);
int print_unsigned(va_list types, char buffer[], int size,
int precision, int flags, int width);
int print_octal(va_list types, char buffer[], int size,
int precision, int flags, int width);
int print_hexadecimal(va_list types, char buffer[], int size,
int precision, int flags, int width);
int print_hexa_upper(va_list types, char buffer[], int size,
int precision, int flags, int width);
int print_hexa(va_list types, char map_to[], char buffer[],
int flags, char flag_ch,  int size, int precision, int width);

/*A function that prints non printable characters */
int print_non_printable(va_list types, char buffer[], int size,
int precision, int flags, int width);

/*A funcion to print memory address */
int print_pointer(va_list types, char buffer[], int size,
int precision, int flags, int width);
/*A funciotn to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/*A function to print string in reverse order*/
int print_reverse(va_list types, char buffer[], int size,
int precision, int flags, int width);

/*A function to print a string in rot 13*/
int print_rot13string(va_list types, char buffer[], int size,
int precision, int flags, int width);
/* A functions to handler width */
int handle_write_char(char c, char buffer[], int size,
int precision, int flags, int width);
int write_number(int is_positive, int index, char buffer[],
int size, int precision, int flags, int width);
int write_num(int index, char bff[], int flags, int width,
int precision, int length, char padd, char extra_c);
int write_pointer(char buffer[], int index, int length, int width,
int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int index, char buffer[], int size,
int precision, int flags, int width);

/****************** Utils ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* A main.h file for the printf.c project of ALX*/
