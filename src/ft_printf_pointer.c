/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 23:25:48 by knottey           #+#    #+#             */
/*   Updated: 2023/06/04 22:02:56 by knottey          ###   ########.fr       */
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

void	ft_put_address(uintptr_t addr, const char *hex)
{
	char	addr_char;

	if (addr > 0)
	{
		ft_put_address(addr / 16, hex);
		addr_char = hex[addr % 16];
		ft_putchar(addr_char);
	}
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
	{
		ft_put_address(addr, HEX);
		addr_len += ft_addr_len(addr);
	}
	return (addr_len);
}
