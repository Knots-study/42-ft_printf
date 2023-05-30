/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:07:33 by knottey           #+#    #+#             */
/*   Updated: 2023/05/31 06:11:04 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static size_t	select_formats(const char format, va_list args)
{
	size_t	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_printf_char(va_arg(args, const int));
	else if (format == 's')
		print_length += ft_printf_string(va_arg(args, const char *));
	else if (format == 'p')
		print_length += ft_printf_pointer(va_arg(args, uintptr_t));
	else if (format == 'd' || format == 'i')
		print_length += ft_printf_int10(va_arg(args, const int));
	else if (format == 'u')
		print_length += ft_printf_int10(va_arg(args, const unsigned int));
	else if (format == 'x' || format == 'X')
		print_length += ft_printf_hex(va_arg(args, const unsigned int), format);
	else if (format == '%')
		print_length += ft_printf_char(va_arg(args, const int));
	return (print_length);
}

// %[フラグ][最小フィールド幅].[精度][長さ修飾子][変換指定子]
int ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	print_length;

	print_length = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (ft_strchr(modifier, *format))
				print_length += select_formats(*format, args);
		}
		else
			print_length += ft_printf_char(*format);
		format++;
	}
	va_end(args);
	return (print_length);
}

int main(void)
{
	ft_printf(" %p %p\n", INT_MAX, INT_MIN);
	printf(" %p %p\n", INT_MAX, INT_MIN);
}