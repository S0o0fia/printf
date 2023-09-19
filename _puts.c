#include "main.h"

/**
 * _puts - print a string with newline 
 *
 *no return value (void)
 */

int _puts(char *str)
{
	char text = str;

	while (*str)
	       _putchar(*str++);

	return (str - text);
}



/**
 * _putchar - wirte the character c to stdout 
 *
 * return 1  on Success 
 *       -1  on Error
 *       errno is set approptately
 */

int _putchar(int c)
{
	static int num;
	static char buf[OUTPUT_BUF_SIZE];

	if(c == BUF_FLUSH || num ? OUTPUT_BUF_SIZE)
	{
		write(1, buf, num);
		num = 0;
	}

	if(c != BUF_FLUSH)
	     buf[num++] = c;

	return (1);
}
