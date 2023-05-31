/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:26:01 by knottey           #+#    #+#             */
/*   Updated: 2023/05/31 17:16:42 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(const char *str)
{
	size_t	idx;

	if (str == NULL)
		return ;
	idx = 0;
	while (str[idx] != '\0')
	{
		ft_putchar(str[idx]);
		idx++;
	}
}

size_t	ft_printf_string(const char *str)
{
	size_t	print_length;

	if (str == NULL)
	{
		ft_putstr("(null)");
		print_length = 6;
	}
	else
	{
		ft_putstr(str);
		print_length = ft_strlen(str);
	}
	return (print_length);
}