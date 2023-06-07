/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 23:30:59 by knottey           #+#    #+#             */
/*   Updated: 2023/06/07 14:01:43 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_digit(long long int num)
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

static int	ft_putnbr(long long int num)
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

static int ft_printf_sign(long long int *num, t_pformats *p_exf)
{
	int p_len;

	p_len = 0;
	if (*num < 0)
	{
		p_len += ft_putchar('-');
		(*num) *= -1;
		(p_exf->width)--;
	}
	else if (p_exf->plus == 1)
	{
		p_len += ft_putchar('+');
	}
	else if(p_exf->space == 1)
	{
		p_len += ft_putchar(' ');
	}
	return (p_len);
}

static int printf_intleft(long long int num, t_pformats *p_exf, int num_len)
{
	int	p_len;

	p_len = 0;
	p_len += ft_printf_sign(&num, p_exf);
	p_len += repeat_char(p_exf->prec - num_len, '0');
	p_len += ft_putnbr(num);
	p_len += repeat_char(p_exf->width - p_exf->prec, ' ');
	return (p_len);
}

static int printf_intzero(long long int num, t_pformats *p_exf)
{
	int	p_len;

	p_len = 0;
	if (p_exf->prec == -1)
	{
		p_len += repeat_char(p_exf->width - p_exf->prec, ' ');
		p_len += ft_putnbr(num);
	}
	else
	{
		p_len += ft_printf_sign(&num, p_exf);
		p_len += repeat_char(p_exf->width - p_exf->prec, '0');
		p_len += ft_putnbr(num);
	}
	return (p_len);
}

static int printf_intnorm(long long int num, t_pformats *p_exf, int num_len)
{
	int	p_len;

	p_len = 0;
	p_len += repeat_char(p_exf->width - p_exf->prec, ' ');
	p_len += ft_printf_sign(&num, p_exf);
	p_len += repeat_char(p_exf->prec - num_len, '0');
	p_len += ft_putnbr(num);
	return (p_len);
}

int	ft_printf_int(long long int num, t_pformats p_exf)
{
	int p_len;
	int num_len;

	p_len = 0;
	num_len = ft_get_digit(num);
	p_exf.prec = MAX(num_len, p_exf.prec);
	p_exf.width = MAX(p_exf.prec, p_exf.width);
	if (p_exf.left == 1)
		p_len += printf_intleft(num, &p_exf, num_len);
	else if (p_exf.zero == 1)
		p_len += printf_intzero(num, &p_exf);
	else
		p_len += printf_intnorm(num, &p_exf, num_len);
	return (p_len);
}
