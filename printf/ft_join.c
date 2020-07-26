/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 01:14:23 by tnakamur          #+#    #+#             */
/*   Updated: 2020/07/27 00:43:35 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*prec_join(char *str, long n, int size)
{
	char *tmp;
	char *ze;

	tmp = str;
	if (n >= 0)
	{
		ze = zero(size - (int)ft_strlen(str));
		str = ft_strjoin(ze, tmp);
		free_set(ze, tmp);
	}
	else
	{
		str[0] = '0';
		tmp = str;
		ze = zero(size - (int)ft_strlen(str));
		str = ft_strjoin(ze, tmp);
		free_set(ze, tmp);
		tmp = str;
		str = ft_strjoin("-", tmp);
		free(tmp);
	}
	return (str);
}

char	*wide_join(char *sp, char *str, long n, t_flag f)
{
	char	*ans;
	int		len;

	if (f.zero == '0' && n < 0)
	{
		len = (int)ft_strlen(sp) - 1;
		str[0] = sp[len];
		sp[len] = '\0';
		ans = ft_strjoin(sp, str);
		free_set(sp, str);
		str = ans;
		ans = ft_strjoin("-", str);
		free(str);
	}
	else
	{
		ans = ft_strjoin(sp, str);
		free_set(sp, str);
	}
	return (ans);
}

char	*wide_join_0x(char *sp, char *str, t_flag f)
{
	char *ans;

	if (f.zero == '0')
	{
		str[1] = '0';
		ans = ft_strjoin(sp, str);
		free_set(sp, str);
		ans[1] = 'x';
	}
	else
	{
		ans = ft_strjoin(sp, str);
		free_set(sp, str);
	}
	return (ans);
}

char	*prec_join_0x(char *val, t_flag f)
{
	char *tmp;
	char *sub;

	val += 2;
	tmp = val;
	sub = zero(f.prec - (int)ft_strlen(val));
	val = ft_strjoin(sub, tmp);
	free_set(sub, (tmp - 2));
	tmp = val;
	val = ft_strjoin("0x", tmp);
	free(tmp);
	return (val);
}

char	*precjoin_free(char *str, int size)
{
	char *tmp;
	char *sub;

	tmp = str;
	sub = zero(size - (int)ft_strlen(str));
	str = ft_strjoin(sub, tmp);
	free_set(sub, tmp);
	return (str);
}
