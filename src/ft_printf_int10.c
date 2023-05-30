/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int10.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 23:30:59 by knottey           #+#    #+#             */
/*   Updated: 2023/05/30 23:38:04 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_intlen(long long int n)
{
	size_t	length;

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

int	ft_printf_int10(long long int di)
{
	ft_putnbr(di);
	return (ft_intlen(di));
}