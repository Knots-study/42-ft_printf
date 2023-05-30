/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:08:06 by knottey           #+#    #+#             */
/*   Updated: 2023/05/31 06:09:43 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>

# define modifier "cspdiuxX"
# define HEX "0123456789abcdef"
# define HEX_CAP "0123456789ABCDEF"

typedef struct s_formats
{
	int		flag;
	int		width;
	int		prec;
	int		spec;
	int		body;
	int		zero;
	int		blank;
	char	*prefix;
	char	*basestr;
	int		base;
	int		putnum;
}	t_formats;


/* ft_printf.c */
int ft_printf(const char *, ...);
//size_t	select_formats(const char format, const char *str);

/* ft_printf_char.c */
size_t	ft_printf_char(const int c);
void	ft_putchar(const char c);

/* ft_printf_string.c */
size_t	ft_printf_string(const char *str);
void	ft_putstr(const char *str);

/* ft_printf_hex.c */
int	ft_printf_hex(unsigned int addr, const char format);

/* ft_printf_int10.c */
int	ft_printf_int10(long long int di);

/* ft_printf_pointer */
int ft_addr_len(uintptr_t addr);
void	ft_put_address(uintptr_t addr, const char *hex);
int	ft_printf_pointer(uintptr_t addr);

/* ft_printf_utils.c */
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);

#endif