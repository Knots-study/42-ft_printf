/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 23:30:16 by knottey           #+#    #+#             */
/*   Updated: 2023/06/06 07:29:26 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	ft_printf_hex(unsigned int addr, const char format, t_formats ex_formats)
// {
// 	int	print_length;

// 	print_length = 0;
// 	if (ex_formats.left == 1)
// 	{
// 		if (ex_formats.prefix == 1 && format == 'x')
// 			print_length += write(1, "0x", 2);
// 		else if (ex_formats.prefix == 1 && format == 'X')
// 			print_length += write(1, "0X", 2);
// 		if (addr == 0)
// 			print_length += ft_putchar('0');
// 		if (format == 'x')
// 			ft_put_address(addr, HEX);
// 		else
// 			ft_put_address(addr, HEX_CAP);
// 		print_length += ft_addr_len(addr);
// 	}
// 	print_length += ft_zeroleft(ft_addr_len(addr), ex_formats);
// 	if (ex_formats.left == 0)
// 	{
// 		if (ex_formats.prefix == 1 && format == 'x')
// 			print_length += write(1, "0x", 2);
// 		else if (ex_formats.prefix == 1 && format == 'X')
// 			print_length += write(1, "0X", 2);
// 		if (addr == 0)
// 			print_length += ft_putchar('0');
// 		if (format == 'x')
// 			ft_put_address(addr, HEX);
// 		else
// 			ft_put_address(addr, HEX_CAP);
// 		print_length += ft_addr_len(addr);
// 	}
// 	return (print_length);
// }

int	ft_printf_hex(unsigned int addr, const char format, t_formats ex_formats)
{
	int print_length;

	//ft_flags_print(ex_formats);
	print_length = 0;
	//実際に表示する数字の文字数(flagで指定した0とか空白とか含まず)
	ex_formats.prec = MAX(ft_addr_len(addr), ex_formats.prec);
	ex_formats.width = MAX(ex_formats.prec, ex_formats.width);//実際に表示する文字の文字数
	if (ex_formats.left == 1)
	{
		if (ex_formats.prefix == 1 && format == 'x')
			print_length += write(1, "0x", 2);
		else if (ex_formats.prefix == 1 && format == 'X')
			print_length += write(1, "0X", 2);
		print_length += padding_something(ex_formats.prec - ft_addr_len(addr), '0');
		if (format == 'x')
			print_length += ft_put_address(addr, HEX, 0);
		else
			print_length += ft_put_address(addr, HEX_CAP, 0);
		print_length += padding_something(ex_formats.width - ex_formats.prec, ' ');
	}
	else if (ex_formats.zero == 1)//(-と0が同時に指定された場合0が無視される)
	{
		if (ex_formats.prec == -1)
		{
			print_length += padding_something(ex_formats.width - ex_formats.prec, ' ');
			if (format == 'x')
				print_length += ft_put_address(addr, HEX, 0);
			else
				print_length += ft_put_address(addr, HEX_CAP, 0);
		}
		else
		{
			print_length += padding_something(ex_formats.width - ex_formats.prec, '0');
			if (format == 'x')
				print_length += ft_put_address(addr, HEX, 0);
			else
				print_length += ft_put_address(addr, HEX_CAP, 0);
		}
		
	}
	else
	{
		if (ex_formats.prefix == 1 && format == 'x')
			print_length += write(1, "0x", 2);
		else if (ex_formats.prefix == 1 && format == 'X')
			print_length += write(1, "0X", 2);
		print_length += padding_something(ex_formats.width - ex_formats.prec, ' ');
		print_length += padding_something(ex_formats.prec - ft_addr_len(addr), '0');
		if (format == 'x')
			print_length += ft_put_address(addr, HEX, 0);
		else
			print_length += ft_put_address(addr, HEX_CAP, 0);
	}
	return (print_length);
}
