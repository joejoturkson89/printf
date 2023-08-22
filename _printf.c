#include "main.h"
/**
 * _printf - printf function
 * @format: format
 * Return: return printed characters
 */
int _printf(const char *format, ...)
{
	int char_to_print = 0;
	va_list list;

	if (format == NULL)
		return (-1);
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
		}
		if (*format == '\0')
			return (-1);
		if (*format == 'c')
		{
			char c = va_arg(list, int);
				write(1, &c, strlen("char"));
			char_to_print++;
		}
		else if (*format == '%')
		{
			write(1, format, strlen(format));
			char_to_print++;
		}
		else if (*format == 's')
		{
			char str = va_arg(list, int);
			int str_len = 0;
			while (str[str_len] != '\0')
				str_len++;
			write(1, str, str_len);
			char_to_print += str_len;
		}
		format++;
	}
	va_end(list);
	return (char_to_print);
}
