/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 23:34:29 by tnakamur          #+#    #+#             */
/*   Updated: 2020/07/27 01:06:17 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		minus_chr(const char *fmt, t_flag f)
{
	while (*fmt && !is_type(*fmt))
	{
		if (is_flag(*fmt))
		{
			if (*fmt == '-')
				f.minus = 1;
		}
		fmt++;
	}
	return (f.minus);
}

char	zero_chr(const char *fmt, t_flag f)
{
	while (is_flag(*fmt) && *fmt && !is_type(*fmt))
	{
		if (*fmt == '0' && !f.minus)
			f.zero = '0';
		fmt++;
	}
	return (f.zero);
}

int		decide_type(va_list ap, t_flag f, const char *fmt)
{
	if (*(fmt + 1) == 'd' || *(fmt + 1) == 'i')
		f.ag = ft_output_d(ap, f, ((fmt) - f.pt));
	else if (*(fmt + 1) == 'c')
		f.ag = ft_output_c(ap, f, ((fmt) - f.pt));
	else if (*(fmt + 1) == 's')
		f.ag = ft_output_s(ap, f, ((fmt) - f.pt));
	else if (*(fmt + 1) == 'u')
		f.ag = ft_output_u(ap, f, ((fmt) - f.pt));
	else if (*(fmt + 1) == 'p')
		f.ag = ft_output_p(ap, f, ((fmt) - f.pt));
	else if (*(fmt + 1) == 'x')
		f.ag = ft_output_x(ap, f, ((fmt) - f.pt));
	else if (*(fmt + 1) == 'X')
		f.ag = ft_output_lx(ap, f, ((fmt) - f.pt));
	return (f.ag);
}

int		ft_output(const char *fmt, va_list ap, t_flag f)
{
	while (*fmt)
	{
		if (*fmt == '%' && *(fmt + 1) != '%')
		{
			f = parse_flag(f, fmt, ap);
			while (!is_type(*fmt) && *(fmt + 1) != '\0')
			{
				if (*(fmt + 1) != '%' && is_type(*(fmt + 1)))
					f.ag = decide_type(ap, f, fmt);
				else if (*(fmt + 1) == '%')
				{
					f.ag = ft_output_per(f.ag, f, (++fmt - f.pt));
					break ;
				}
				fmt++;
			}
		}
		else if (*fmt == '%' && *(fmt + 1) == '%')
			f.ag = ft_putchar_per(*(++fmt), 1, f);
		else
			ft_putchar_fd(*fmt, 1);
		fmt++;
	}
	return (f.ag);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_flag	f;
	int		ret;

	if (!format)
		return (0);
	va_start(ap, format);
	f.ag = ft_strlen(format);
	ret = ft_output(format, ap, f);
	va_end(ap);
	return (ret);
}
