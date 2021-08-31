/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 01:41:44 by tnakamur          #+#    #+#             */
/*   Updated: 2020/07/27 00:26:11 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

t_flag	reset_flag(t_flag f)
{
	f.width = 0;
	f.minus = 0;
	f.zero = ' ';
	f.prec = -1;
	f.field = 0;
	f.star = 0;
	f.dot = 0;
	return (f);
}

t_flag	width_reset(t_flag f)
{
	f.width = 0;
	f.field = 0;
	f.star = 0;
	return (f);
}

t_flag	prec_flag(t_flag f, va_list ap, const char *fmt)
{
	f.prec = 0;
	while (*fmt != '.')
		fmt--;
	while (ft_isdigit(*fmt) || *fmt == '.' || *fmt == '*')
	{
		if (*fmt == '.')
			f.prec = 0;
		if (ft_isdigit(*fmt))
			f.prec = (f.prec * 10) + (*fmt - '0');
		if (*fmt == '*' && *(fmt - 1) == '.')
		{
			f.prec = va_arg(ap, int);
			if (f.prec < 0)
				f.prec = -1;
		}
		fmt++;
	}
	f.field = 1;
	f.dot = 1;
	return (f);
}

t_flag	width_star(t_flag f, va_list ap)
{
	f.star = 1;
	f.width = va_arg(ap, int);
	if (f.width < 0)
	{
		f.minus = 1;
		f.zero = ' ';
		f.width *= -1;
	}
	return (f);
}

t_flag	parse_flag(t_flag f, const char *fmt, va_list ap)
{
	f.pt = fmt;
	f = reset_flag(f);
	fmt++;
	f.minus = minus_chr(fmt, f);
	f.zero = zero_chr(fmt, f);
	while (!is_type(*fmt) && *(fmt) != '\0')
	{
		if ((*fmt == '-') && ft_isdigit(*(fmt + 1)))
			f = width_reset(f);
		if (*fmt == '.' && !f.dot)
			f = prec_flag(f, ap, fmt);
		if (*fmt == '*' && !f.field)
			f = width_star(f, ap);
		if (ft_isdigit(*fmt) && *fmt && !f.field)
		{
			if (f.star == 1)
				f.width = 0;
			f.width = (f.width * 10) + (*fmt - '0');
		}
		if (*(fmt + 1) == '%')
			break ;
		fmt++;
	}
	return (f);
}
