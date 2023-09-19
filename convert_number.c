#include "main.h"

/**
 * ptint_hex - print as hex deciaml
 *
 * return bytes printed
 */

int print_hex(va_list ap, params_t *params)
{
	unsigned long number;
	int c = 0;
	char *str;

	if (params->l_modifier)
		number = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		number = (unsigned short int)va_arg(ap, unsigned int);
	else 
		number = (unsigned int)va_arg(ap, unsigned int);

	str = convert(number, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);

	if (params->hashtag_flag && number)
	{
		*--str = 'x';
		*--str = '0';
	}

	params->unsign = 1;

	return (c += print_number(str, params));
}


/** 
 * print_HEX as hex with upper case 
 *
 * return bytes printed 
 */

int print_HEX(va_list ap, params_t *params)
{
	unsigned long number;
	int c = 0;
	char *str;

	if (params->l_modifier)
		number = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		number = (unsigned short int)va_arg(ap, unsigned int);
	else 
		number = (unsigned int)va_arg(ap, unsigned int);

	str = convert(number, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && number)
	{
		*--str = 'x';
	 	*--str = '0';
	}

	params->unsign = 1;
	return (c += print_number(str, params));
}



/**
 * print_octal - print octal number (unsigned)
 *
 * return bytes printed
 */

int print_octal(va_list, params_t *params)
{
	unsigned long number;
	char *str;
	int c = 0;

	if (params->l_modifier)
		number = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		number = (unsigned short int)va_arg(ap, unsigned int);
	else 
		number = (unsigned int)va_arg(ap, unsigned int);

	str = convert(number, 8, CONVERT_UNSIGNED, params);

	if (params->hashtag_flag && number)
		*--str = '0';
	params->unsign = 1;

	return (c += print_number(str, params));
}
