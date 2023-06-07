/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:08:06 by knottey           #+#    #+#             */
/*   Updated: 2023/06/06 07:28:46 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>

# define MODIFIER "cspdiuxX%"
# define HEX "0123456789abcdef"
# define HEX_CAP "0123456789ABCDEF"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct s_formats
{
	int		flag;
	int		left;
	int		width;
	int		prec;
	int		prefix;
	int		body;
	int		zero;
	int		space;
	int 	plus;
	int		base;
	int		putnum;
}	t_formats;

void 	ft_flags_print(t_formats ex_formats);
int 	padding_something(int times, const char something);

int		ft_printf(const char *format, ...);
int 	ft_printf_char(int c, t_formats ex_formats);
int 	ft_putchar(unsigned char c);
int		ft_zeroleft(int word_length, t_formats ex_formats);
int		ft_printf_string(const char *str, t_formats ex_formats);
int		ft_putstr(const char *str);
int		ft_printf_hex(unsigned int addr, const char format, t_formats ex_formats);
int		ft_printf_int10(long long int di, t_formats ex_formats);
int		ft_addr_len(uintptr_t addr);
int		ft_put_address(uintptr_t addr, const char *hex, int count);
int		ft_printf_pointer(uintptr_t addr);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);

#endif