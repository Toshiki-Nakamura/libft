/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 12:12:08 by tnakamur          #+#    #+#             */
/*   Updated: 2020/07/27 00:45:28 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int		is_type(char c)
{
	if (c == 's' || c == 'c' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'p' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

int		ad_len(int ag, int len, int d)
{
	ag -= d;
	ag += len;
	return (ag);
}

char	*sp_zero(int w, char c)
{
	char	*s;
	int		i;

	s = malloc(sizeof(char) * (w + 1));
	i = 0;
	while (i < w)
		s[i++] = c;
	s[i] = '\0';
	return (s);
}

char	*zero(int w)
{
	char	*s;
	int		i;

	s = malloc(sizeof(char) * (w + 1));
	i = 0;
	while (i < w)
		s[i++] = '0';
	s[i] = '\0';
	return (s);
}

void	hex_upper(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
}
