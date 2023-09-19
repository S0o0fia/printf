#include "main.h"

/**
 * print_from_to - print a range of char addresses
 *
 *return number of bytes printed 
 */
int print_from_to(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);

		start++
	}

	return (sum);
}

/**
 * print_rev - print string in reverse 
 *
 * return number of byte printed 
 */

int print_rev(va_list ap, params_t *params)
{
	int length, sum = 0;
	char *string = va_arg(ap, char *);

	if(string)
	{
		for(length = 0; *string; string++)
			length++;

		string--;

		for(; length > 0; length--, string--)
			sum += _putchar(*string);
	}

	return (sum);
}

/**
 * print_rot13 - prints string in rot13
 *
 * return number bytes printed
 */

int print_rot13(va_list ap, params_t *params)
{
	int num, index;
	int count = 0;
	char array[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM	nopqrstuvwxyzabcdefghijklm";
	char *arr = va_arg(ap, char *);

	(void)params;

	num = 0;
	index =0;

	while(arr[num])
	{
		if ((arr[num] >= 'A' && arr[num] <= 'Z') || (arr[num] >= 'a' && arr[num] <= 'z'))
		{
			index = arr[num] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(arr[num]);

		num++;
	}

	return (count);
} 
