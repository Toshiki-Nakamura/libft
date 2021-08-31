/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 01:09:44 by tnakamur          #+#    #+#             */
/*   Updated: 2020/07/27 00:40:36 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char *str;

	str = ft_strjoin(s1, s2);
	free_set(s1, s2);
	return (str);
}

void	free_set(char *s1, char *s2)
{
	free(s1);
	free(s2);
}

int		is_flag(char c)
{
	if (c == '0' || c == '-')
		return (1);
	return (0);
}

int		ft_putchar_per(char c, int fd, t_flag f)
{
	write(fd, &c, 1);
	f.ag--;
	return (f.ag);
}

char	*itos_for_d(int n, t_flag f)
{
	char *s;

	if (!f.prec && !n)
		s = ft_strdup("");
	else
		s = ft_itoa(n);
	return (s);
}
