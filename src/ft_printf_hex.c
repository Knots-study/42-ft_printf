/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 23:25:48 by knottey           #+#    #+#             */
/*   Updated: 2023/06/07 14:33:32 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_len(uintptr_t hex)
{
	int	length;

	length = 0;
	if (hex == 0)
		return (1);
	while (hex > 0)
	{
		length++;
		hex /= 16;
	}
	return (length);
}

static int	ft_put_hexnbr(uintptr_t hexnbr, const char *hexstr, int count)
{
	int		hex_len;
	char	hex_char;

	hex_len = 0;
	if (count == 0 && hexnbr == 0)
		return (ft_putchar('0'));
	if (hexnbr > 0)
	{
		hex_len += ft_put_hexnbr(hexnbr / 16, hexstr, count + 1);
		hex_char = hexstr[hexnbr % 16];
		hex_len += ft_putchar(hex_char);
	}
	return (hex_len);
}

static int	printf_hexsharp(unsigned int num, int hexconv, int prefix)
{
	int	p_len;

	p_len = 0;
	if (prefix == 0 || num == 0)
		return (p_len);
	if (hexconv == 0)
		p_len += ft_putstr("0x", 2);
	else
		p_len += ft_putstr("0X", 2);
	return (p_len);
}

static const char	*change_hexmode(int hexconv)
{
	if (hexconv == 0)
		return (HEX);
	else
		return(HEX_CAP);
}

static int printf_hexleft(unsigned int num, t_pformats *p_exf, int num_len)
{
	int	p_len;

	p_len = 0;
	p_len += printf_hexsharp(num, p_exf->hexconv, p_exf->prefix);
	p_len += repeat_char(p_exf->prec - num_len, '0');
	p_len += ft_put_hexnbr(num, change_hexmode(p_exf->hexconv), 0);
	p_len += repeat_char(p_exf->width - p_exf->prec, ' ');
	return (p_len);
}

static int printf_hexzero(unsigned int num, t_pformats *p_exf)
{
	int	p_len;

	p_len = 0;
	if (p_exf->prec == -1)
	{
		p_len += repeat_char(p_exf->width - p_exf->prec, ' ');
		p_len += printf_hexsharp(num, p_exf->hexconv, p_exf->prefix);
		p_len += ft_put_hexnbr(num, change_hexmode(p_exf->hexconv), 0);
	}
	else
	{
		p_len += printf_hexsharp(num, p_exf->hexconv, p_exf->prefix);
		p_len += repeat_char(p_exf->width - p_exf->prec, '0');
		p_len += ft_put_hexnbr(num, change_hexmode(p_exf->hexconv), 0);
	}
	return (p_len);
}

static int printf_hexnorm(unsigned int num, t_pformats *p_exf, int num_len)
{
	int	p_len;

	p_len = 0;
	p_len += printf_hexsharp(num, p_exf->hexconv, p_exf->prefix);
	p_len += repeat_char(p_exf->width - p_exf->prec, ' ');
	p_len += repeat_char(p_exf->prec - num_len, '0');
	p_len += ft_put_hexnbr(num, change_hexmode(p_exf->hexconv), 0);
	return (p_len);
}

int	ft_printf_hex(unsigned int num, const char format, t_pformats p_exf)
{
	int p_len;
	int num_len;

	p_len = 0;
	num_len = ft_hex_len(num);
	p_exf.prec = MAX(num_len, p_exf.prec);
	p_exf.width = MAX(p_exf.prec, p_exf.width);
	if (format == 'X')
		p_exf.hexconv = 1;
	if (p_exf.left == 1)
		p_len += printf_hexleft(num, &p_exf, num_len);
	else if (p_exf.zero == 1)
		p_len += printf_hexzero(num, &p_exf);
	else
		p_len += printf_hexnorm(num, &p_exf, num_len);
	return (p_len);
}
