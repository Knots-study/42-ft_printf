/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:35:19 by knottey           #+#    #+#             */
/*   Updated: 2023/06/08 17:37:58 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(uintptr_t hex)
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

int	ft_put_hexnbr(uintptr_t hexnbr, const char *hexstr, int count)
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

int	printf_hexsharp(uintptr_t num, t_pformats *p_exf)
{
	int	p_len;

	p_len = 0;
	if (p_exf->prefix == 0 || num == 0)
		return (p_len);
	if (p_exf->hexconv == 0)
	{
		p_len += ft_putstr("0x", 2);
		(p_exf->width) -= 2;
	}
	else
	{
		p_len += ft_putstr("0X", 2);
		(p_exf->width) -= 2;
	}
	return (p_len);
}

const char	*change_hexmode(int hexconv)
{
	if (hexconv == 0)
		return (HEX);
	else
		return (HEX_CAP);
}
