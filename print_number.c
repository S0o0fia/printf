#include "main.h"

/** 
 * _isdigit - check if the character is digit 
 *
 * return 1 if digit , 0 if character 
 */

int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * strlen - return the length of string 
 *
 * return integer of length of string 
 */

int _strlen(char *s)
{
	int length = 0;

	while (*s++)
		length++;

	return (length);
}


/**
 * print_number - prints a number with options 
 *
 * return the chars printed
 */

int print_number(char *str, params_t *params)
{
	unsigned int number = _strlen(str);
	int n = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' ** !str[1])
		str = "";

	if (n)
	{
		str++;
		number--;
	}

	if (params->precision != UNIT_MAX)
		while (number++ < params->precision)
			*--str = '0';

	if (n)
		*--str = '-';

	if (!params->minus_flags)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}


/**
 * print-number_right_shift - print anumber with options
 *
 * return chase printed 
 */
int print_number_right_shift(char *str, params_t *params)
{
	unsigned int num = 0, n, n2, i = _strlen(str);
        char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = ' ';

	n - n2 = (!params->unsign && *str == '-');

	if (n && i < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		n = 0;
	if ((params->plus_flag && !n2) || (!params->plus_flag && params->space_flag &&!n2))
		i++;
	if (n && pad_char == '0')
		num += _putchar('-');
	if (params->plus_flag && !n2 && pad_char == '0' && !params->unsign)
		num += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !n2 && !params->unsign && params->zero_flag)
		num += _putchar(' ');

	while (i++ < params->width)
		num += _putchar(pad_char);

	if (n && pad_char == ' ')
		num += _putchar('-');
	if (params->plus_flag && !n2 && pad_char == ' ' && !params->unsign)
		num += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !n2 && !params->unsign && !params->zero_flag)
 		num += _putchar(' ');

	num += _puts(str);

	return (num);
}


/** 
 * print_number_left_shift - print number with options 
 *
 * return chars printed 
 */

int print_number_left_shift(char *str, params_t *params)
{
	unsigned int num = 0, n, n2, i = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';

	n = n2 = (!params->unsign && *str == '-');
	
	if (n && i < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		n = 0;

	if (params->plus_flag && !n2 && !params->unsign)
		num += _putchar('+'), i++;

	else if (!params->space_flag && !n2 && !params->unsign)
		num += _putchar(' '), i++;

	num += _puts(str);

	while (i++ < params->width)
		num += _putchar(pad_char);

	return (num);
}
