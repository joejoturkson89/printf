#include "main.h"
/**
 * _printf - printf function
 * @format: format
 * Return: returns characters
 */
int _printf(const char *format, ...)
{
	int char_to_print = 0;
	va_list list;

	va_start(list, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			char_to_print++;
		}
		else
		{
			format++;
			if (*format == '\0')
				return (-1);
		}
		switch (*format)
		{
			case 'c':
				{
					char c = va_arg(list, int);
					write(1, &c, 1);
					char_to_print++;
					break;
				}
			case 's':
				{
					char *str = va_arg(list, char*);
					int str_len = strlen(str);
					write(1, str, str_len);
					char_to_print++;
					break;
				}
			case '%':
				{
					write(1, "%", 1);
						char_to_print++;
					break;
				}
			case 'd':
			case 'i':
				{
					int num = va_arg(list, int);
					char str[10];
					sprintf(str, "%d", num);
					write(1, str, strlen(str));
					char_to_print += strlen(str);
					break;
				}

			default:
				{
					break;
				}
		}
		format++;
	}
	va_end(list);
	return (char_to_print);
}

