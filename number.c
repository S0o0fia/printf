#include "main.h"

/**
 * convert - converter function
 *
 * return string
 */

char *convert(long int num, int base, int flags, params_t *params)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long number = num;
	(void)params;

	if(!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		number = -num;
		sign = '-';
	}

	array = flags & CONVERT_UNSIGNED ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do{
		*--ptr = array[number % base];
		number /= base;
	 } while (number != 0);

	if (sign)
		*--ptr = sign;

	return (ptr);
}


/**
 * print_unsigned = prints usigned ineger numbers
 *
 * return bytes printed
 */

int print_unsigned(va_list ap, params_t *params)
{
	unsigned long number;

	if (params->l_modifier)
		number = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		number = (unsigned short int)va_arg(ap, unsigned int);
	else
		number = (unsigned int)var_arg(ap, unsigned int);

	params->unsign = 1;

	return (print_number(convert(number, 10, CONVERT_UNSIGNED, params), params);
}


/**
 * print_address = print address
 *
 * return bytes printed
 */

int print_address(va_list ap, params_t *params)
{
	unsigned long int number = var_arg(ap, unsigned long int);
	char *string;

	if(!number)
		return (_puts("(nil)"));
	
	string = convert(number, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--string = 'x';
	*--string = '0';
	return (print_number(string, params));
}
