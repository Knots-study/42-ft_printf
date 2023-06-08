/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 23:25:48 by knottey           #+#    #+#             */
/*   Updated: 2023/06/07 15:38:18 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printf_hexleft(uintptr_t num, t_pformats *p_exf, int num_len)
{
	int	p_len;

	p_len = 0;
	p_len += printf_hexsharp(num, p_exf);
	p_len += repeat_char(p_exf->prec - num_len, '0');
	p_len += ft_put_hexnbr(num, change_hexmode(p_exf->hexconv), 0);
	p_len += repeat_char(p_exf->width - p_exf->prec, ' ');
	return (p_len);
}

static int	printf_hexzero(uintptr_t num, t_pformats *p_exf, int num_len)
{
	int	p_len;

	p_len = 0;
	if (p_exf->is_prec == 0)
	{
		p_len += repeat_char(p_exf->width - p_exf->prec, '0');
		p_len += repeat_char(p_exf->prec - num_len, '0');
		p_len += printf_hexsharp(num, p_exf);
		p_len += ft_put_hexnbr(num, change_hexmode(p_exf->hexconv), 0);
	}
	else
	{
		p_len += printf_hexsharp(num, p_exf);
		p_len += repeat_char(p_exf->width - p_exf->prec, ' ');
		p_len += repeat_char(p_exf->prec - num_len, '0');
		p_len += ft_put_hexnbr(num, change_hexmode(p_exf->hexconv), 0);
	}
	return (p_len);
}

static int	printf_hexnorm(uintptr_t num, t_pformats *p_exf, int num_len)
{
	int	p_len;

	p_len = 0;
	p_len += printf_hexsharp(num, p_exf);
	p_len += repeat_char(p_exf->width - p_exf->prec, ' ');
	p_len += repeat_char(p_exf->prec - num_len, '0');
	p_len += ft_put_hexnbr(num, change_hexmode(p_exf->hexconv), 0);
	return (p_len);
}

int	ft_printf_hex(uintptr_t num, const char format, t_pformats p_exf)
{
	int	p_len;
	int	num_len;

	p_len = 0;
	num_len = ft_hex_len(num);
	if (p_exf.prec == 0 && p_exf.is_prec != 0 && num == 0)
	{
		p_len += repeat_char(p_exf.width - p_exf.prec, ' ');
		return (p_len);
	}
	p_exf.prec = max_int(num_len, p_exf.prec);
	p_exf.width = max_int(p_exf.prec, p_exf.width);
	if (format == 'X')
		p_exf.hexconv = 1;
	if (p_exf.left == 1)
		p_len += printf_hexleft(num, &p_exf, num_len);
	else if (p_exf.zero == 1)
		p_len += printf_hexzero(num, &p_exf, num_len);
	else
		p_len += printf_hexnorm(num, &p_exf, num_len);
	return (p_len);
}
