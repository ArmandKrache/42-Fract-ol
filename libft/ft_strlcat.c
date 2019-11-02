/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:22:06 by akrache           #+#    #+#             */
/*   Updated: 2018/11/15 13:27:49 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		x;
	size_t		dest_size;
	const char	*sr;
	char		*dst;

	sr = src;
	dst = dest;
	x = size;
	while (*dst != '\0' && x-- != 0)
		dst++;
	dest_size = dst - dest;
	x = size - dest_size;
	if (x == 0)
		return (dest_size + ft_strlen(src));
	while (*sr != '\0')
	{
		if (x != 1)
		{
			*dst++ = *sr;
			x--;
		}
		sr++;
	}
	*dst = '\0';
	return (dest_size + (sr - src));
}
