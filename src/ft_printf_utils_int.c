/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:32:24 by knottey           #+#    #+#             */
/*   Updated: 2023/06/07 15:33:49 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_digit(long long int num)
{
	int	length;

	length = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		num *= -1;
	while (num > 0)
	{
		length++;
		num /= 10;
	}
	return (length);
}

int	ft_putnbr(long long int num)
{
	char			c_digit;
	int				p_len;
	long long int	ll_num;

	p_len = 0;
	ll_num = (long long int)num;
	if (ll_num < 0)
	{
		ll_num *= -1;
		p_len += ft_putchar('-');
	}
	if (ll_num >= 10)
		p_len += ft_putnbr(ll_num / 10);
	c_digit = ll_num % 10 + '0';
	p_len += ft_putchar(c_digit);
	return (p_len);
}
