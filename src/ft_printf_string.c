/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:26:01 by knottey           #+#    #+#             */
/*   Updated: 2023/06/08 19:37:24 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *str, int times)
{
	int	idx;

	idx = 0;
	if (str == NULL)
		return (idx);
	while (str[idx] != '\0' && idx < times)
	{
		ft_putchar(str[idx]);
		idx++;
	}
	return (idx);
}

int	ft_printf_string(const char *str, t_pformats p_exf)
{
	int	p_len;

	p_len = 0;
	if (str == NULL)
		return (ft_putstr("(null)", ft_strlen("(null)")));
	if (p_exf.is_prec == 0)
		p_exf.prec = ft_strlen(str);
	else
		p_exf.prec = min_int(ft_strlen(str), p_exf.prec);
	p_exf.width = max_int(p_exf.prec, p_exf.width);
	if (p_exf.left == 1)
	{
		p_len += ft_putstr(str, p_exf.prec);
		p_len += repeat_char(p_exf.width - p_exf.prec, ' ');
	}
	else
	{
		p_len += repeat_char(p_exf.width - p_exf.prec, ' ');
		p_len += ft_putstr(str, p_exf.prec);
	}
	return (p_len);
}
