/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 21:50:29 by tnakamur          #+#    #+#             */
/*   Updated: 2021/05/09 10:55:36 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**mem_free(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static int	cnt_words(char const *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if ((s[i] != c && i == 0) || (s[i] != c && s[i - 1] == c))
			cnt++;
		i++;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		bgn;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (cnt_words(s, c) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (s[++i])
	{
		if ((s[i] != c && i == 0) || (s[i] != c && s[i - 1] == c))
			bgn = i;
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
		{
			str[j++] = ft_substr(s, bgn, (size_t)(i - bgn + 1));
			if (str[j - 1] == NULL)
				return (mem_free(str));
		}
	}
	str[j] = 0;
	return (str);
}
