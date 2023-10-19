#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * print_char - writes the character c to stdout
 * @c: The character to be printed
 *
 * Return: 1.
 */
int print_char(va_list c)
{
	unsigned char my_char;

	my_char = va_arg(c, int);
	_putchar(my_char);
	return (1);
}
/**
 * print_string - writes the character c to stdout
 * @s:string to be print
 *
 * Return: 1.
 */
int print_string(va_list s)
{
	char *my_string;
	int  i = 0;

	my_string = va_arg(s, char *);
	if (my_string == NULL)
		my_string = "(null)";
	while (my_string[i])
	{
		_putchar(my_string[i]);
		i++;
	}
	return (i);
}
/**
 * print_percentage - prints percent sign
 *
 * Return: 1.
 */
int print_percentage(void)
{
	_putchar('%');
	return (1);
}

/**
* print_int - function that prints an integer
* @i: integer to print
* Description: prints a digit using _putchar
* Return: size the output text
*/
int print_int(va_list i)
{
	int len, powten, j, digit, n, count = 0, num;

	n = va_arg(i, int);
	if (n != 0)
	{
		if (n < 0)
		{
			_putchar('-');
			count++;
		}
		num = n;
		len = 0;
		while (num != 0)
		{
			num /= 10;
			len++;
		}
		powten = 1;
		for (j = 1; j <= len - 1; j++)
			powten *= 10;
		for (j = 1; j <= len; j++)
		{
			digit = n / powten;
			if (n < 0)
				_putchar((digit * -1) + 48);
			else
				_putchar(digit + '0');
			count++;
			n -= digit * powten;
			powten /= 10;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}
/**
* print_bin - convert to binary
* @b: number in decinal
* Return: number of chars printed
*/
int print_bin(va_list b)
{
	unsigned int len, powten, j, digit, n, num;
	int count = 0;

	n = va_arg(b, unsigned int);
	if (n != 0)
	{
		num = n;
		len = 0;
		while (num != 0)
		{
			num /= 2;
			len++;
		}
		powten = 1;
		for (j = 1; j <= len - 1; j++)
			powten *= 2;
		for (j = 1; j <= len; j++)
		{
			digit = n / powten;
			_putchar(digit + '0');
			count++;
			n -= digit * powten;
			powten /= 2;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}
