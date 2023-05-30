/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 23:30:16 by knottey           #+#    #+#             */
/*   Updated: 2023/05/31 05:30:26 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hex(unsigned int addr, const char format)
{
	int addr_len;

	addr_len = 0;
	if (format == 'x')
		ft_put_address(addr, HEX);
	else
		ft_put_address(addr, HEX_CAP);
	addr_len += ft_addr_len(addr);
	return (addr_len);
}