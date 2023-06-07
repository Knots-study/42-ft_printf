/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:13:00 by knottey           #+#    #+#             */
/*   Updated: 2023/06/05 06:29:07 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(unsigned char c)
{
	write(STDOUT_FILENO, &c, 1);
	return (1);
}

int ft_printf_char(int c, t_formats ex_formats)
{
	int print_length;

	print_length = 0;
	if (ex_formats.left == 1)
		print_length += ft_putchar(c);
	print_length += ft_zeroleft(1, ex_formats);
	if (ex_formats.left == 0)
		print_length += ft_putchar(c);
	return (print_length);
}
