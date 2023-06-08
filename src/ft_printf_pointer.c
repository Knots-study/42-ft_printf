/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:55:40 by knottey           #+#    #+#             */
/*   Updated: 2023/06/08 19:37:34 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printf_ptrleft(uintptr_t num, t_pformats *p_exf, int num_len)
{
	int	p_len;

	p_len = 0;
	(p_exf->width) -= 2;
	p_len += ft_putstr("0x", 2);
	p_len += repeat_char(p_exf->prec - num_len, '0');
	p_len += ft_put_hexnbr(num, change_hexmode(p_exf->hexconv), 0);
	p_len += repeat_char(p_exf->width - p_exf->prec, ' ');
	return (p_len);
}

static int	printf_ptrzero(uintptr_t num, t_pformats *p_exf, int num_len)
{
	int	p_len;

	p_len = 0;
	if (p_exf->is_prec == 0)
	{
		(p_exf->width) -= 2;
		p_len += repeat_char(p_exf->width - p_exf->prec, '0');
		p_len += repeat_char(p_exf->prec - num_len, '0');
		p_len += ft_putstr("0x", 2);
		p_len += ft_put_hexnbr(num, change_hexmode(p_exf->hexconv), 0);
	}
	else
	{
		(p_exf->width) -= 2;
		p_len += repeat_char(p_exf->width - p_exf->prec, ' ');
		p_len += ft_putstr("0x", 2);
		p_len += repeat_char(p_exf->prec - num_len, '0');
		p_len += ft_put_hexnbr(num, change_hexmode(p_exf->hexconv), 0);
	}
	return (p_len);
}

static int	printf_ptrnorm(uintptr_t num, t_pformats *p_exf, int num_len)
{
	int	p_len;

	p_len = 0;
	(p_exf->width) -= 2;
	p_len += repeat_char(p_exf->width - p_exf->prec, ' ');
	p_len += ft_putstr("0x", 2);
	p_len += repeat_char(p_exf->prec - num_len, '0');
	p_len += ft_put_hexnbr(num, change_hexmode(p_exf->hexconv), 0);
	return (p_len);
}

int	ft_printf_ptr(uintptr_t num, t_pformats p_exf)
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
	if (p_exf.left == 1)
		p_len += printf_ptrleft(num, &p_exf, num_len);
	else if (p_exf.zero == 1)
		p_len += printf_ptrzero(num, &p_exf, num_len);
	else
		p_len += printf_ptrnorm(num, &p_exf, num_len);
	return (p_len);
}
