/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:26:01 by knottey           #+#    #+#             */
/*   Updated: 2023/06/05 09:38:18 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putstr(const char *str)
{
	int	idx;

	idx = 0;
	if (str == NULL)
		return (idx);
	while (str[idx] != '\0')
	{
		ft_putchar(str[idx]);
		idx++;
	}
	return (idx);
}

int	ft_printf_string(const char *str, t_formats ex_formats)
{
	int	print_length;
	int	word_length;

	print_length = 0;
	word_length = ft_strlen(str);
	if (str == NULL)
	{
		ft_putstr("(null)");
		print_length = 6;
	}
	else
	{
		if (ex_formats.left == 1)
			print_length += ft_putstr(str);
		print_length += ft_zeroleft(word_length, ex_formats);
		if (ex_formats.left == 0)
			print_length += ft_putstr(str);
	}
	return (print_length);
}
