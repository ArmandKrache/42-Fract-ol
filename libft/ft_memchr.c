/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:28:48 by akrache           #+#    #+#             */
/*   Updated: 2018/11/15 13:26:27 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char const *tmp;

	tmp = s;
	while (n != 0)
	{
		if ((unsigned char)c == *(unsigned char *)tmp)
			return ((void *)tmp);
		tmp++;
		n--;
	}
	return (NULL);
}
