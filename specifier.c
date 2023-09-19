#include "main.h"

/**
 * get-specifier - finds the format func
 *
 * Return : the number of bytes printed
 */

int (*get_specifier(char *s))(vs_list ap, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", ptint_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	}

	int num = 0;

	while (specifiers[num].specifier)
	{
		if(*s == specifiers[num].specifier[0]_
		{
		 	return (specifiers[num].f);
		}
	}

	return (NULL);

}



/**
 * get_print_func - find the format func 
 *
 * return the numbers of bytes printed
 */

int get_print_func(char *s, va_list ap, params_t *params)
{
 	int (*func)(va_list, params_t *) = get_specifier(s);

	if(func)
	   return (func(ap, params));

	return (0);
}

/**
 * get-flag - find the flag func 
 *
 *
 * return if flag wass valid
 */


int get_flag(char *s, params_t *params)
{
	int num = 0;

	switch(*s)
	{
		case '+':
		    num = params->plus_flag = 1;
		    break;
		case ' ':
		   num = params->space_flag = 1;
		   break;
                case '#':
		   num = params->hashtag_flag = 1;
		   break;
		case '-':
		   num = params->minus_flag = 1;
		   break;
		case '0':
		   num = params->zero_flag = 1;
		   break;
	}

	return (num);

}


/**
 * get_modifier - finds the modifier func 
 *
 * return if the modifier is valid 
 */

int get_modifier(char *s, params_t *params)
{
	int num = 0;

	switch(s)
	{
	   case 'h':
        	      num = params->h_modifier = 1;
	     	      break;
	   case 'l':
	              num = params->l_modifier = 1;
	    	      break;
	}

	return (num);
}

/**
 * get_width - get the width from the string 
 *
 * retrun new Pointer 
 */

char *get_width(char *s, params_t *params, va_list ap)
{
	int digit = 0;

	if(*s == '*')
	{
		          digit = va_arg(ap, int);
         		  s++;
	}
	else
	{
	   	while (_isdigit(*s))
	      		 digit = digit * 10 + (*s++ - '0');
	}

	params->width = digit;

	return (s);

}
