#include "main.h"

/**
 * this func clear struct fields and resit buffer
 * void func 
 */

void int_params(params_t *params, va_list ap)
{
	params->unsign = 0;

	params->plus_flag = 0;
	params->space_flag = 0;
	params->hashtag_flag = 0;
	params->zero_flag = 0;
	params->minus_flag = 0;

	params->width = 0;
	params->precision = UNIT_MAX;

	params->h_modifier = 0;
	params->l_modifier = 0;

	(void)ap;
}
