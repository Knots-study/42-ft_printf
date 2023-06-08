/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:13:00 by knottey           #+#    #+#             */
/*   Updated: 2023/06/08 19:38:39 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

char	*ft_strchr(const char *s, int c)
{
	int	idx;
	int	length;

	if (s == NULL)
		return (NULL);
	length = ft_strlen(s) + 1;
	idx = 0;
	while (idx < length)
	{
		if (s[idx] == (char)c)
			return ((char *)(s + idx));
		idx++;
	}
	return (NULL);
}

int	repeat_char(int times, const char smth)
{
	int	i;

	i = 0;
	while (i < times)
	{
		ft_putchar(smth);
		i++;
	}
	return (max_int(times, 0));
}

int	max_int(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	min_int(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
