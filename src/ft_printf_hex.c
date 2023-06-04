/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 23:30:16 by knottey           #+#    #+#             */
/*   Updated: 2023/06/05 08:15:49 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hex(unsigned int addr, const char format, t_formats ex_formats)
{
	int	print_length;

	print_length = 0;
	if (ex_formats.left == 1)
	{
		if (ex_formats.prefix == 1 && format == 'x')
			print_length += write(1, "0x", 2);
		else if (ex_formats.prefix == 1 && format == 'X')
			print_length += write(1, "0X", 2);
		if (addr == 0)
			print_length += ft_putchar('0');
		if (format == 'x')
			ft_put_address(addr, HEX);
		else
			ft_put_address(addr, HEX_CAP);
		print_length += ft_addr_len(addr);
	}
	print_length += ft_zeroleft(ft_addr_len(addr), ex_formats);
	if (ex_formats.left == 0)
	{
		if (ex_formats.prefix == 1 && format == 'x')
			print_length += write(1, "0x", 2);
		else if (ex_formats.prefix == 1 && format == 'X')
			print_length += write(1, "0X", 2);
		if (addr == 0)
			print_length += ft_putchar('0');
		if (format == 'x')
			ft_put_address(addr, HEX);
		else
			ft_put_address(addr, HEX_CAP);
		print_length += ft_addr_len(addr);
	}
	return (print_length);
}
