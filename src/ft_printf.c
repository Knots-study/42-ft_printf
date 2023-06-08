/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:07:33 by knottey           #+#    #+#             */
/*   Updated: 2023/06/07 20:50:55 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_printf_flags(t_pformats *p_exf, const char **format)
{
	*p_exf = (t_pformats){0};
	while (ft_strchr(PRINTF_FLAGS, **format))
	{
		if (**format == '-')
			p_exf->left = 1;
		if (**format == '0')
			p_exf->zero = 1;
		if (**format == '#')
			p_exf->prefix = 1;
		if (**format == ' ')
			p_exf->space = 1;
		if (**format == '+')
			p_exf->plus = 1;
		(*format)++;
	}
}

static int	measure_width_prec(const char **format)
{
	long long int	num;

	num = 0;
	while ('0' <= **format && **format <= '9')
	{
		num *= 10;
		num += (**format - '0');
		if (num > INT_MAX)
			return (-1);
		(*format)++;
	}
	return ((int)num);
}

static int	check_printf_width_prec(t_pformats *p_exf, const char **format)
{
	long long int	prec;
	long long int	width;

	width = measure_width_prec(format);
	prec = 0;
	if (**format == '.')
	{
		(*format)++;
		p_exf->is_prec = 1;
		prec = measure_width_prec(format);
	}
	if (width == -1 || prec == -1)
		return (1);
	else
	{
		p_exf->prec = (int)prec;
		p_exf->width = (int)width;
	}
	return (0);
}

static int	select_conspec(const char format, va_list *args, t_pformats p_exf)
{
	int	p_len;

	p_len = 0;
	if (format == 'c')
		p_len += ft_printf_char(va_arg(*args, int), p_exf);
	else if (format == 's')
		p_len += ft_printf_string(va_arg(*args, const char *), p_exf);
	else if (format == 'd' || format == 'i')
		p_len += ft_printf_int(va_arg(*args, int), p_exf);
	else if (format == 'u')
		p_len += ft_printf_int(va_arg(*args, unsigned int), p_exf);
	else if (format == 'x' || format == 'X')
		p_len += ft_printf_hex(va_arg(*args, unsigned int), format, p_exf);
	else if (format == 'p')
		p_len += ft_printf_ptr(va_arg(*args, uintptr_t), p_exf);
	else if (format == '%')
		p_len += ft_putchar(format);
	return (p_len);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_pformats	p_exf;
	size_t		p_len;

	p_len = 0;
	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			check_printf_flags(&p_exf, &format);
			if (check_printf_width_prec(&p_exf, &format))
				return (-1);
			if (ft_strchr(MODIFIER, *format))
				p_len += select_conspec(*format, &args, p_exf);
		}
		else
			p_len += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (p_len);
}
