/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ex_formats.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:28:51 by knottey           #+#    #+#             */
/*   Updated: 2023/06/05 08:30:21 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_zeroleft(int word_length, t_formats ex_formats)
{
	int	print_length;

	print_length = 0;
	while (word_length < ex_formats.width)
	{
		if (ex_formats.zero == 1)
			print_length += ft_putchar('0');
		word_length++;
	}
	return (print_length);
}

void ft_flags_print(t_formats ex_formats)
{
	printf("flag = %d\n", ex_formats.flag);
	printf("left = %d\n", ex_formats.left);
	printf("width = %d\n", ex_formats.width);
	printf("prec = %d\n", ex_formats.prec);
	printf("plus = %d\n", ex_formats.plus);
	printf("zero = %d\n", ex_formats.zero);
	printf("space = %d\n", ex_formats.space);
	printf("prefix = %d\n", ex_formats.prefix);
	printf("base = %d\n", ex_formats.base);
	printf("putnum = %d\n", ex_formats.putnum);
}

