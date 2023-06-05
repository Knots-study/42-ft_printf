/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ex_formats.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:28:51 by knottey           #+#    #+#             */
/*   Updated: 2023/06/05 10:19:11 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//精度問題
//数値変換の場合->printf("[%.10d]\n", 1234567);[0001234567]//0埋めされる
//文字列の場合->printf("[%.10s]\n", "apple"); [apple]//0埋めされない
//フィールド長と精度の関係をちゃんと考える
int	ft_zeroleft(int word_length, t_formats ex_formats)
{
	int	print_length;

	print_length = 0;
	while (word_length < ex_formats.width)
	{
		if (ex_formats.zero == 1)
			print_length += ft_putchar('0');
		else
			print_length += ft_putchar(' ');
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

