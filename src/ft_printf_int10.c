/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int10.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 23:30:59 by knottey           #+#    #+#             */
/*   Updated: 2023/06/05 08:29:04 by knottey          ###   ########.fr       */
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

static void	ft_putnbr(long long int n)
{
	char			cn;
	long long int	lln;

	lln = (long long int)n;
	if (lln < 0)
	{
		ft_putchar('-');
		lln *= -1;
	}
	if (lln >= 10)
		ft_putnbr(lln / 10);
	cn = lln % 10 + '0';
	ft_putchar(cn);
}

int	ft_printf_int10(long long int di, t_formats ex_formats)
{
	int print_length;
	int	int_len;

	print_length = 0;
	int_len = ft_intlen(di);
	if (ex_formats.left == 1)
	{
		if (di >= 0 && ex_formats.plus == 1)
			print_length += ft_putchar('+');
		else if (di >= 0 && ex_formats.space == 1)
			print_length += ft_putchar(' ');
		ft_putnbr(di);
		print_length += int_len;
	}
	if (ex_formats.left == 0 && di < 0)
	{
		print_length += ft_putchar('-');
		di *= -1;
	}
	print_length += ft_zeroleft(int_len, ex_formats);
	if (ex_formats.left == 0)
	{
		if (di >= 0 && ex_formats.plus == 1)
			print_length += ft_putchar('+');
		else if (di >= 0 && ex_formats.space == 1)
			print_length += ft_putchar(' ');
		ft_putnbr(di);
		int_len = ft_intlen(di);
		print_length += int_len;
	}
	return (print_length);
}
