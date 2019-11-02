/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 09:51:03 by akrache           #+#    #+#             */
/*   Updated: 2018/11/15 13:26:34 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*tmp;
	unsigned const char	*tmp2;

	tmp = dst;
	tmp2 = src;
	while (n != 0)
	{
		*tmp = *tmp2;
		tmp++;
		tmp2++;
		n--;
	}
	return (dst);
}
