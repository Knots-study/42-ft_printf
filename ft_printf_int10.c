/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int10.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 23:30:59 by knottey           #+#    #+#             */
/*   Updated: 2023/06/07 09:45:14 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_digit(long long int n)
{
	int	length;

	length = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		//length++;
		n *= -1;
	}
	while (n > 0)
	{
		length++;
		n /= 10;
	}
	return (length);
}

static int	ft_putnbr(long long int n)
{
	char			cn;
	int				print_length;
	long long int	lln;

	print_length = 0;
	lln = (long long int)n;
	if (lln < 0)
	{
		lln *= -1;
		print_length += ft_putchar('-');
	}
	if (lln >= 10)
		print_length += ft_putnbr(lln / 10);
	cn = lln % 10 + '0';
	print_length += ft_putchar(cn);
	return (print_length);
}

int	ft_padding_num(int word_length, t_formats ex_formats)
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

int ft_printf_sign(long long int *num, t_formats *ex_formats)
{
	int print_length;

	print_length = 0;
	if (*num < 0)
	{
		print_length += ft_putchar('-');
		(*num) *= -1;
		(ex_formats->width)--;
	}
	else if (ex_formats->plus == 1)
	{
		print_length += ft_putchar('+');
	}
	else if(ex_formats->space == 1)
	{
		print_length += ft_putchar(' ');
	}
	return (print_length);
}

int padding_something(int times, const char something)
{
	int	i;

	i = 0;
	while (i < times)
	{
		ft_putchar(something);
		i++;
	}
	return (MAX(times, 0));
}

// 最小フィールド幅は、 変換した結果がその長さ以下であった場合に、左側が空白で埋められる
    //フラグに0がある場合、変換した値の左側を空白の代わりに0で埋める。
// 精度は、最低表示桁数を表し、足りない場合は0で埋められる
// -の場合、フィールド幅は表示桁数に-の一文字分を含むが、精度は-を表示桁数に含めない。
int	ft_printf_int10(long long int num, t_formats ex_formats)
{
	int print_length;

	//ft_flags_print(ex_formats);
	print_length = 0;
	//実際に表示する数字の文字数(flagで指定した0とか空白とか含まず)
	ex_formats.prec = MAX(ft_get_digit(num), ex_formats.prec);
	ex_formats.width = MAX(ex_formats.prec, ex_formats.width);//実際に表示する文字の文字数
	if (ex_formats.left == 1)
	{
		print_length += ft_printf_sign(&num, &ex_formats);
		print_length += padding_something(ex_formats.prec - ft_get_digit(num), '0');
		print_length += ft_putnbr(num);
		print_length += padding_something(ex_formats.width - ex_formats.prec, ' ');
	}
	else if (ex_formats.zero == 1)//(-と0が同時に指定された場合0が無視される)
	{
		if (ex_formats.prec == -1)
		{
			print_length += padding_something(ex_formats.width - ex_formats.prec, ' ');
			print_length += ft_putnbr(num);
		}
		else
		{
			if (num < 0)
			{
				print_length += ft_printf_sign(&num, &ex_formats);
				print_length += padding_something(ex_formats.width - ex_formats.prec, '0');
				print_length += ft_putnbr(num);
			}
			else
			{
				print_length += ft_printf_sign(&num, &ex_formats);
				print_length += padding_something(ex_formats.width - ex_formats.prec, '0');
				print_length += ft_putnbr(num);
			}
		}
		
	}
	else
	{
		print_length += padding_something(ex_formats.width - ex_formats.prec, ' ');
		print_length += ft_printf_sign(&num, &ex_formats);
		print_length += padding_something(ex_formats.prec - ft_get_digit(num), '0');
		print_length += ft_putnbr(num);
	}
	return (print_length);
}
