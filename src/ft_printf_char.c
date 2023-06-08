/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:13:00 by knottey           #+#    #+#             */
/*   Updated: 2023/06/08 19:33:50 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(unsigned char c)
{
	write(STDOUT_FILENO, &c, 1);
	return (1);
}

int	ft_printf_char(int c, t_pformats p_exf)
{
	int	p_len;

	p_len = 0;
	if (p_exf.left == 1)
	{
		p_len += ft_putchar(c);
		p_len += repeat_char(p_exf.width - 1, ' ');
	}
	else
	{
		p_len += repeat_char(p_exf.width - 1, ' ');
		p_len += ft_putchar(c);
	}
	return (p_len);
}
