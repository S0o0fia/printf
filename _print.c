#include "main.h"

/**
 * printf - prints anything
 *
 * return the numbers of bytes that func printed
 */

int _printf(const char *format, ...)
{
	int sum = 0;
	va_list ap;
	char *param, *start;
	params_t params = PARAMS_INIT;

	va_start(ap, format);

	if(format == '' || (format[0] == '%' && format[1] == ''))
		return (-1);

	if(format[0] == '%' && format[1] == ' ' && format[2] == '')
	 	return (-1);

	for(param = (char *)format; *p; p++)
	{
		init_params(&params, ap);

		if(*param != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = param;
		param++;

		while (get_flag(param, &params))
		{
			param++;
		}
 		param = get_width(param, &params, ap);
		param = get_precision(param, &params, ap);

		if(get_modifier(p, &params))
			param++;

		if(!get_specifier(param))
		   	sum += print_from_to(start, param, params.l_modifier || params.hmodifier ? param-1 : 0);
		else
			sum += get_print_func(param, ap, &params);
	}

	_putchar(BUF_FLUSH);
	va_end(ap)
	
	return (sum);
}
