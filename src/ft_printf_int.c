/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 23:30:59 by knottey           #+#    #+#             */
/*   Updated: 2023/06/07 15:34:02 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_sign(long long int *num, t_pformats *p_exf)
{
	int	p_len;

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
	else if (p_exf->space == 1)
	{
		p_len += ft_putchar(' ');
	}
	return (p_len);
}

static int	printf_intleft(long long int num, t_pformats *p_exf, int num_len)
{
	int	p_len;

	p_len = 0;
	p_len += ft_printf_sign(&num, p_exf);
	p_len += repeat_char(p_exf->prec - num_len, '0');
	p_len += ft_putnbr(num);
	p_len += repeat_char(p_exf->width - p_exf->prec, ' ');
	return (p_len);
}

static int	printf_intzero(long long int num, t_pformats *p_exf)
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

static int	printf_intnorm(long long int num, t_pformats *p_exf, int num_len)
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
	int	p_len;
	int	num_len;

	p_len = 0;
	num_len = ft_get_digit(num);
	if (num == 0 && p_exf.prec == 0)
		return (p_len);
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
