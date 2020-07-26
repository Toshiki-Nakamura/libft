/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 12:35:50 by tnakamur          #+#    #+#             */
/*   Updated: 2020/07/27 00:44:42 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int		ft_padding(char c, int n)
{
	int i;

	i = 1;
	while (i <= n)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
	return (i);
}

int		ft_output_c(va_list ap, t_flag f, int len)
{
	char	value;
	int		i;

	value = va_arg(ap, int);
	i = 1;
	if (f.minus != 1 && f.zero != '0' && f.width > 1)
	{
		i = ft_padding(' ', f.width - 1);
	}
	else if (f.minus != 1 && f.zero == '0' && f.width > 1)
	{
		i = ft_padding('0', f.width - 1);
	}
	ft_putchar_fd(value, 1);
	if (f.minus == 1 && f.zero != '0' && f.width > 1)
	{
		i = ft_padding(' ', f.width - 1);
	}
	else if (f.minus == 1 && f.zero == '0' && f.width > 1)
	{
		i = ft_padding('0', f.width - 1);
	}
	f.ag = ad_len(f.ag, i, len + 2);
	return (f.ag);
}

int		ft_output_per(int ag, t_flag f, int len)
{
	char	*val;
	char	*sp;

	val = ft_strdup("%");
	if (f.width && (int)ft_strlen(val) < f.width)
	{
		sp = sp_zero(f.width - (int)ft_strlen(val), f.zero);
		if (!f.minus)
			val = ft_strjoin_free(sp, val);
		else
			val = ft_strjoin_free(val, sp);
	}
	ft_putstr_fd(val, 1);
	ag = ad_len(ag, ft_strlen(val), len + 1);
	free(val);
	return (ag);
}

char	*dup_and_free(char *val, char *s)
{
	char *tmp;

	tmp = val;
	val = ft_strdup(s);
	free(tmp);
	return (val);
}

int		ft_output_s(va_list ap, t_flag f, int len)
{
	char	*val;
	char	*sp;

	val = ft_strdup(va_arg(ap, char *));
	if (!val && f.prec != 0)
		val = ft_strdup("(null)");
	else if (f.prec == 0)
		val = dup_and_free(val, "");
	if (f.prec > 0)
		val[f.prec] = '\0';
	if (f.width && (int)ft_strlen(val) < f.width)
	{
		sp = sp_zero(f.width - (int)ft_strlen(val), f.zero);
		if (!f.minus)
			val = ft_strjoin_free(sp, val);
		else
			val = ft_strjoin_free(val, sp);
	}
	ft_putstr_fd(val, 1);
	f.ag = ad_len(f.ag, ft_strlen(val), len + 2);
	free(val);
	return (f.ag);
}
