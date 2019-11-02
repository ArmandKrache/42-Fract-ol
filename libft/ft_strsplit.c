/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:17:46 by akrache           #+#    #+#             */
/*   Updated: 2018/11/15 16:37:19 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_words(char const *s, char c)
{
	int	i;
	int	nb;
	int	j;

	if (!s)
		return (0);
	j = ft_strlen(s) - 1;
	nb = 0;
	i = 0;
	while ((s[j] == c && j >= 0))
		j--;
	while (i <= j)
	{
		while ((s[i] == c && s[i] != '\0'))
			i++;
		while (s[i] != c && s[i] != '\0')
			i++;
		nb++;
	}
	return (nb);
}

static	int	ft_nwl(char const *s, int index, char c)
{
	int res;

	res = 1;
	while (s[index] != c && s[index])
	{
		res++;
		index++;
	}
	return (res);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		h;

	if (!(res = (char **)malloc((ft_nb_words(s, c) + 1) * sizeof(char*))) || !s)
		return (NULL);
	h = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while ((s[i] == c && s[i]))
			i++;
		if (!(res[h] = (char *)malloc(ft_nwl(s, i, c) * sizeof(char) + 1)))
			return (NULL);
		j = 0;
		while (s[i] != c && s[i])
			res[h][j++] = s[i++];
		res[h++][j] = '\0';
	}
	res[ft_nb_words(s, c)] = 0;
	return (res);
}
