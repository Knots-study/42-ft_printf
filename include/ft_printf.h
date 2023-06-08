/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:08:06 by knottey           #+#    #+#             */
/*   Updated: 2023/06/08 19:38:04 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <limits.h>

# define MODIFIER "cspdiuxX%"
# define HEX "0123456789abcdef"
# define HEX_CAP "0123456789ABCDEF"
# define PRINTF_FLAGS "#0- +"

typedef struct s_pformats
{
	int	flag;
	int	left;
	int	width;
	int	prec;
	int	is_prec;
	int	prefix;
	int	hexconv;
	int	zero;
	int	space;
	int	plus;
}	t_pformats;

int			ft_printf(const char *format, ...);
int			ft_printf_char(int c, t_pformats p_exf);
int			ft_printf_string(const char *str, t_pformats p_exf);
int			ft_printf_int(long long int num, t_pformats p_exf);
int			ft_printf_hex(uintptr_t num, const char format, t_pformats p_exf);
int			ft_printf_ptr(uintptr_t num, t_pformats p_exf);

int			max_int(int a, int b);
int			min_int(int a, int b);
int			ft_putchar(unsigned char c);
int			ft_putstr(const char *str, int times);
int			ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
int			repeat_char(int times, const char smth);
int			ft_get_digit(long long int num);
int			ft_putnbr(long long int num);
int			ft_hex_len(uintptr_t hex);
int			ft_put_hexnbr(uintptr_t hexnbr, const char *hexstr, int count);
int			printf_hexsharp(uintptr_t num, t_pformats *p_exf);
const char	*change_hexmode(int hexconv);

#endif