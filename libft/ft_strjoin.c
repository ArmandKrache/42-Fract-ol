/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:03:16 by akrache           #+#    #+#             */
/*   Updated: 2018/11/15 13:27:46 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		t1;
	int		t2;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	t1 = ft_strlen((char *)s1);
	t2 = ft_strlen((char *)s2);
	if (!(res = (char *)malloc(sizeof(char) * (t1 + t2) + 1)))
		return (NULL);
	i = 0;
	while (i < t1)
	{
		res[i] = s1[i];
		i++;
	}
	t1 = 0;
	while (t1 < t2)
		res[i++] = s2[t1++];
	res[i] = '\0';
	return (res);
}
