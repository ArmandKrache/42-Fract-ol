/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:43:56 by akrache           #+#    #+#             */
/*   Updated: 2018/11/15 13:26:41 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	i = 0;
	tmp1 = (unsigned char *)dst;
	tmp2 = (unsigned char *)src;
	while (i < len)
	{
		if (tmp1 > tmp2)
		{
			tmp1[len - 1] = tmp2[len - 1];
			len--;
		}
		else
		{
			tmp1[i] = tmp2[i];
			i++;
		}
	}
	return (dst);
}
