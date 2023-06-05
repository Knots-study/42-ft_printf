/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int10.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 23:30:59 by knottey           #+#    #+#             */
/*   Updated: 2023/06/05 14:23:41 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen(long long int n)
{
	int	length;

	length = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		length++;
		n *= -1;
	}
	while (n > 0)
	{
		length++;
		n /= 10;
	}
	return (length);
}

static int	ft_putnbr(long long int n)
{
	char			cn;
	int				print_length;
	long long int	lln;

	print_length = 0;
	lln = (long long int)n;
	if (lln < 0)
	{
		lln *= -1;
		print_length += ft_putchar('-');
	}
	if (lln >= 10)
		print_length += ft_putnbr(lln / 10);
	cn = lln % 10 + '0';
	print_length += ft_putchar(cn);
	return (print_length);
}

int	ft_padding_num(int word_length, t_formats ex_formats)
{
	int	print_length;

	print_length = 0;
	while (word_length < ex_formats.width)
	{
		if (ex_formats.zero == 1)
			print_length += ft_putchar('0');
		else
			print_length += ft_putchar(' ');
		word_length++;
	}
	return (print_length);
}

int ft_printf_sign(long long int *num, t_formats *ex_formats)
{
	int print_length;

	print_length = 0;
	if (*num < 0 && ex_formats->prec == 0)
	{
		print_length += ft_putchar('-');
		(*num) *= -1;
		(ex_formats->width)--;
	}
	else if (ex_formats->plus == 1)
	{
		print_length += ft_putchar('+');
		(ex_formats->width)--;
	}
	else if(ex_formats->space == 1)
	{
		print_length += ft_putchar(' ');
		(ex_formats->width)--;
	}
	return (print_length);
}

int padding_something(int times, const char something)
{
	int	i;

	i = 0;
	while (i < times)
	{
		ft_putchar(something);
		i++;
	}
	return (times);
}

int	ft_printf_int10(long long int num, t_formats ex_formats)
{
	int print_length;
	int	int_len;
	int actual_numlen;
	int actual_width;

	//ft_flags_print(ex_formats);
	print_length = 0;
	int_len = ft_intlen(num);
	actual_numlen = MAX(int_len, ex_formats.prec);
	actual_width = MAX(actual_numlen, ex_formats.width);	
	if (ex_formats.left == 1)
	{
		print_length += ft_printf_sign(&num, &ex_formats);
		print_length += ft_putnbr(num);
		print_length += padding_something(actual_width - actual_numlen, ' ');
	}
	else if (ex_formats.zero == 1)
	{
		if (ex_formats.prec == 0)
		{
			print_length += ft_printf_sign(&num, &ex_formats);
			print_length += padding_something(actual_width - actual_numlen, ' ');
			print_length += ft_putnbr(num);
		}
		else
		{
			print_length += ft_printf_sign(&num, &ex_formats);
			print_length += padding_something(actual_width - actual_numlen, '0');
			print_length += ft_putnbr(num);
		}
	}
	else
	{
		print_length += ft_printf_sign(&num, &ex_formats);
		print_length += padding_something(actual_width - actual_numlen, ' ');
		print_length += ft_putnbr(num);
	}
	return (print_length);
}
