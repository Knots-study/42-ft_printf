/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:07:33 by knottey           #+#    #+#             */
/*   Updated: 2023/05/29 16:49:56 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
//#include "ft_printf.h"

int	ft_printf_char(char c);

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	if (s == NULL)
		return (0);
	while (s[length] != '\0')
		length++;
	return (length);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*c_dest;
	const char	*c_src;
	size_t		i;

	c_dest = (char *)dest;
	c_src = (const char *)src;
	i = 0;
	while (i < n)
	{
		c_dest[i] = c_src[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	dest = (char *)malloc(sizeof(char) * (s_len + 1));
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, s, s_len + 1);
	dest[s_len] = '\0';
	return (dest);
}

int	select_formats(const char *format, const char *str)
{
	format++;
	if (*format == 'c')
		ft_printf_char(*str);
	// else if (format == 's')
	// 	ft_printf_s();
	// else if (format == 'p')
	// 	ft_printf_p();
	// else if (format == 'd' || format == 'i')
	// 	ft_printf_di();
	// else if (format == 'u')
	// 	ft_printf_u();
	// else if (format == 'x' || format == 'X')
	// 	ft_printf_xX();
	// else if (format == '%')
	// 	ft_print_percent();
	return (0);
}


int ft_printf(const char *format, ...)
{
	va_list	args;
	char	*str_formats;

	va_start(args, format);
	str_formats = ft_strdup(format);
	format = va_arg(args, char *);
	select_formats(str_formats, format);
	va_end(args);
	return (0);
}

int main(void)
{
	ft_printf("%c", 'a');
}
