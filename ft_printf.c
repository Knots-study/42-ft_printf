/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:07:33 by knottey           #+#    #+#             */
/*   Updated: 2023/06/07 07:46:33 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	judge_ex_formats(t_formats *ex_formats, const char **format);

static size_t	select_formats(const char format, va_list *args, t_formats ex_formats)
{
	size_t	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_printf_char(va_arg(*args, int), ex_formats);
	else if (format == 's')
		print_length += ft_printf_string(va_arg(*args, const char *), ex_formats);
	else if (format == 'p')
		print_length += ft_printf_pointer(va_arg(*args, uintptr_t));
	else if (format == 'd' || format == 'i')
		print_length += ft_printf_int10(va_arg(*args, int), ex_formats);
	else if (format == 'u')
		print_length += ft_printf_int10(va_arg(*args, unsigned int), ex_formats);
	else if (format == 'x' || format == 'X')
		print_length += ft_printf_hex(va_arg(*args, unsigned int), format, ex_formats);
	else if (format == '%')
		print_length += ft_putchar(format);
	return (print_length);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_formats	ex_formats;
	size_t		print_length;

	print_length = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			judge_ex_formats(&ex_formats, &format);
			if (ft_strchr(MODIFIER, *format))
				print_length += select_formats(*format, &args, ex_formats);
		}
		else
			print_length += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (print_length);
}

static void	judge_ex_formats(t_formats *ex_formats, const char **format)
{
	*ex_formats = (t_formats){0};
	while (ft_strchr(" -+#0", **format))
	{
		if (**format == '-')
			ex_formats->left = 1;
		else if (**format == '0')
			ex_formats->zero = 1;
		else if (**format == '#')
			ex_formats->prefix = 1;
		else if (**format == ' ')
			ex_formats->space = 1;
		else if (**format == '+')
			ex_formats->plus = 1;	
		(*format)++;
	}
	while ('0' <= **format && **format <= '9')
	{
		ex_formats->width *= 10;
		ex_formats->width += (**format - '0');
		(*format)++;
	}
	if (**format == '.')
	{
		(*format)++;
		while ('0' <= **format && **format <= '9')
		{
			ex_formats->prec *= 10;
			ex_formats->prec += (**format - '0');
			(*format)++;
		}
	}
}

int main(void)
{
	printf("%d\n",printf(" %-9X \n%-10X \n%-11X \n%-12X \n%-13X \n%-14X a\n%-15X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	printf("%d\n",ft_printf(" %-9X \n%-10X \n%-11X \n%-12X \n%-13X \n%-14X a\n%-15X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
}