/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:04:55 by akrache           #+#    #+#             */
/*   Updated: 2018/11/15 13:28:31 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *nd, size_t len)
{
	size_t		i;
	size_t		pos;
	size_t		needle_len;

	needle_len = ft_strlen(nd);
	if (needle_len == 0)
		return ((char *)h);
	pos = 0;
	while (h[pos] != '\0' && pos < len)
	{
		if (h[pos] == nd[0])
		{
			i = 0;
			while (nd[i] != '\0' && h[pos + i] == nd[i] && pos + i < len)
				i++;
			if (nd[i] == '\0')
				return ((char *)&h[pos]);
		}
		pos++;
	}
	return (0);
}
