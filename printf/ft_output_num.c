/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 12:30:12 by tnakamur          #+#    #+#             */
/*   Updated: 2020/07/27 00:21:45 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int		ft_output_d(va_list ap, t_flag f, int len)
{
	int		n;
	char	*s;
	char	*sp;

	n = va_arg(ap, int);
	s = itos_for_d(n, f);
	if ((f.prec > 0 && f.prec > (int)ft_strlen(s) && n >= 0) || \
	(f.prec > 0 && f.prec > ((int)ft_strlen(s) - 1) && n < 0))
		s = prec_join(s, n, f.prec);
	if (f.prec != -1 && f.prec < f.width && f.zero == '0')
		f.zero = ' ';
	if (f.width && (int)ft_strlen(s) < f.width)
	{
		sp = sp_zero(f.width - (int)ft_strlen(s), f.zero);
		if (!f.minus)
			s = wide_join(sp, s, n, f);
		else
			s = ft_strjoin_free(s, sp);
	}
	ft_putstr_fd(s, 1);
	f.ag = ad_len(f.ag, ft_strlen(s), len + 2);
	free(s);
	return (f.ag);
}

int		ft_output_u(va_list ap, t_flag f, int len)
{
	unsigned int	n;
	char			*str;
	char			*sp;

	n = (unsigned int)va_arg(ap, int);
	if (!f.prec && !n)
		str = ft_strdup("");
	else
		str = ft_uitoa(n);
	if (f.prec > 0 && f.prec > (int)ft_strlen(str))
		str = precjoin_free(str, f.prec);
	if (f.prec != -1 && f.prec < f.width && f.zero == '0')
		f.zero = ' ';
	if (f.width && (int)ft_strlen(str) < f.width)
	{
		sp = sp_zero(f.width - (int)ft_strlen(str), f.zero);
		if (!f.minus)
			str = ft_strjoin_free(sp, str);
		else
			str = ft_strjoin_free(str, sp);
	}
	ft_putstr_fd(str, 1);
	f.ag = ad_len(f.ag, ft_strlen(str), len + 2);
	free(str);
	return (f.ag);
}

int		ft_output_p(va_list ap, t_flag f, int len)
{
	char			*val;
	char			*sp;
	unsigned long	p;

	p = (unsigned long)va_arg(ap, void *);
	if (!f.prec && !p)
		val = ft_strdup("0x");
	else
		val = ft_hextoa_0x(p);
	if (f.prec > 0 && f.prec > ((int)ft_strlen(val) - 2))
		val = prec_join_0x(val, f);
	if (f.prec != -1 && f.prec < f.width && f.zero == '0')
		f.zero = ' ';
	if (f.width && (int)ft_strlen(val) < f.width)
	{
		sp = sp_zero(f.width - (int)ft_strlen(val), f.zero);
		if (!f.minus)
			val = wide_join_0x(sp, val, f);
		else
			val = ft_strjoin_free(val, sp);
	}
	ft_putstr_fd(val, 1);
	f.ag = ad_len(f.ag, ft_strlen(val), len + 2);
	free(val);
	return (f.ag);
}

int		ft_output_x(va_list ap, t_flag f, int len)
{
	char			*str;
	char			*sp;
	unsigned long	p;

	p = (unsigned long)va_arg(ap, unsigned int);
	if (!f.prec && !p)
		str = ft_strdup("");
	else
		str = ft_hextoa(p, 'x');
	if (f.prec != -1 && f.prec < f.width && f.zero == '0')
		f.zero = ' ';
	if (f.prec > 0 && f.prec > (int)ft_strlen(str))
		str = precjoin_free(str, f.prec);
	if (f.width && (int)ft_strlen(str) < f.width)
	{
		sp = sp_zero(f.width - (int)ft_strlen(str), f.zero);
		if (!f.minus)
			str = ft_strjoin_free(sp, str);
		else
			str = ft_strjoin_free(str, sp);
	}
	ft_putstr_fd(str, 1);
	f.ag = ad_len(f.ag, ft_strlen(str), len + 2);
	free(str);
	return (f.ag);
}

int		ft_output_lx(va_list ap, t_flag f, int len)
{
	char			*str;
	char			*sp;
	unsigned long	p;

	p = (unsigned long)va_arg(ap, unsigned int);
	if (!f.prec && !p)
		str = ft_strdup("");
	else
		str = ft_hextoa(p, 'X');
	if (f.prec != -1 && f.prec < f.width && f.zero == '0')
		f.zero = ' ';
	if (f.prec > 0 && f.prec > (int)ft_strlen(str))
		str = precjoin_free(str, f.prec);
	if (f.width && (int)ft_strlen(str) < f.width)
	{
		sp = sp_zero(f.width - (int)ft_strlen(str), f.zero);
		if (!f.minus)
			str = ft_strjoin_free(sp, str);
		else
			str = ft_strjoin_free(str, sp);
	}
	ft_putstr_fd(str, 1);
	f.ag = ad_len(f.ag, ft_strlen(str), len + 2);
	free(str);
	return (f.ag);
}
