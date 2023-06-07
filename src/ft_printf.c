/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:07:33 by knottey           #+#    #+#             */
/*   Updated: 2023/06/07 14:27:06 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_printf_flags(t_pformats *p_exf, const char **format)
{
	while (ft_strchr(PRINTF_FLAGS, **format))
	{
		if (**format == '-')
			p_exf->left = 1;
		else if (**format == '0')
			p_exf->zero = 1;
		else if (**format == '#')
			p_exf->prefix = 1;
		else if (**format == ' ')
			p_exf->space = 1;
		else if (**format == '+')
			p_exf->plus = 1;
		(*format)++;
	}
}

static void	measure_width_prec(t_pformats *p_exf, const char **format)
{
	while ('0' <= **format && **format <= '9')
	{
		p_exf->width *= 10;
		p_exf->width += (**format - '0');
		(*format)++;
	}
	if (**format == '.')
	{
		(*format)++;
		while ('0' <= **format && **format <= '9')
		{
			p_exf->prec *= 10;
			p_exf->prec += (**format - '0');
			(*format)++;
		}
	}
	else
		p_exf->prec = -1;
}

static int	select_conspec(const char format, va_list *args, t_pformats p_exf)
{
	int	p_len;

	p_len = 0;
	if (format == 'c')
		p_len += ft_printf_char(va_arg(*args, int), p_exf);
	else if (format == 's')
		p_len += ft_printf_string(va_arg(*args, const char *), p_exf);
	// else if (format == 'p')
	// 	p_len += ft_printf_pointer(va_arg(*args, uintptr_t), p_exf);
	if (format == 'd' || format == 'i')
		p_len += ft_printf_int(va_arg(*args, int), p_exf);
	else if (format == 'u')
		p_len += ft_printf_int(va_arg(*args, unsigned int), p_exf);
	else if (format == 'x' || format == 'X')
		p_len += ft_printf_hex(va_arg(*args, unsigned int), format, p_exf);
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
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			p_exf = (t_pformats){0};
			check_printf_flags(&p_exf, &format);
			measure_width_prec(&p_exf, &format);
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

// int main(void)
// {
// 	printf("%d\n", printf(" %-2x ", -1));
// 	printf("%d\n", ft_printf(" %-2x ", -1));
// }