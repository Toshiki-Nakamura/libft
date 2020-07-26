/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 23:30:28 by tnakamur          #+#    #+#             */
/*   Updated: 2020/07/26 15:49:24 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long		digit(unsigned long n)
{
	long cnt;

	cnt = 1;
	while (n > 9)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

static int		hex_digit(unsigned long n)
{
	long cnt;

	cnt = 1;
	while (n > 15)
	{
		n /= 16;
		cnt++;
	}
	return (cnt);
}

char			*ft_uitoa(int n)
{
	int					i;
	unsigned long		nb;
	char				*str;

	nb = (unsigned int)n;
	if (!(str = (char *)malloc(sizeof(char) * (digit(nb) + 1))))
		return (0);
	i = digit(nb) - 1;
	str[digit(nb)] = '\0';
	while (i >= 0)
	{
		str[i] = (nb % 10) + '0';
		nb /= 10;
		i--;
	}
	return (str);
}

char			*ft_hextoa_0x(unsigned long n)
{
	int			i;
	int			j;
	char		*ans;
	char		*ret;
	const char	*hex = "0123456789abcdef";

	ans = malloc(sizeof(char) * (hex_digit(n) + 1));
	if (!ans)
		return (NULL);
	j = 0;
	i = hex_digit(n) - 1;
	ans[hex_digit(n)] = '\0';
	while (i >= 0)
	{
		j = n % 16;
		n /= 16;
		ans[i] = hex[j];
		i--;
	}
	ret = ft_strjoin("0x", ans);
	free(ans);
	return (ret);
}

char			*ft_hextoa(unsigned long n, char x)
{
	int			i;
	int			j;
	char		*ans;
	const char	*hex = "0123456789abcdef";

	ans = malloc(sizeof(char) * (hex_digit(n) + 1));
	if (!ans)
		return (NULL);
	j = 0;
	i = hex_digit(n) - 1;
	ans[hex_digit(n)] = '\0';
	while (i >= 0)
	{
		j = n % 16;
		n /= 16;
		ans[i] = hex[j];
		i--;
	}
	if (x == 'X')
		hex_upper(ans);
	return (ans);
}
