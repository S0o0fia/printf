#include "main.h"

/**
 * get_precision - get the precision fromt the string 
 *
 * return New Pointer
 */
char *get_precision(char *p, params_t *paramsm va_list ap)
{
	int digit = 0;

	if(*p != '.')
		return (p);

	p++;

	if(*p == '*')
	{
		digit = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			digit = digit *10 + (*p++ - '0');
	}

	params->precision = digit;
	
	return (p);
}
