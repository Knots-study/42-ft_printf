/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 23:25:48 by knottey           #+#    #+#             */
/*   Updated: 2023/06/06 07:33:30 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_addr_len(uintptr_t addr)
{
	int	length;

	length = 0;
	while (addr > 0)
	{
		length++;
		addr /= 16;
	}
	return (length);
}

int	ft_put_address(uintptr_t addr, const char *hex, int count)
{
	char	addr_char;
	int		addr_length;

	addr_length = 0;
	if (count == 0 && addr == 0)
		return (ft_putchar('0'));
	if (addr > 0)
	{
		addr_length += ft_put_address(addr / 16, hex, count + 1);
		addr_char = hex[addr % 16];
		addr_length += ft_putchar(addr_char);
	}
	
	return (addr_length);
}

int	ft_printf_pointer(uintptr_t addr)
{
	int	addr_len;

	addr_len = 0;
	addr_len += write(1, "0x", 2);
	if (addr == 0)
	{
		ft_putchar('0');
		addr_len++;
	}
	else
		addr_len += ft_put_address(addr, HEX, 0);
	return (addr_len);
}
