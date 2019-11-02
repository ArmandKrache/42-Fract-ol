/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:20:42 by akrache           #+#    #+#             */
/*   Updated: 2018/11/15 15:12:03 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char	*res;
	int		nb;
	int		neg;

	nb = ft_nb_digit(n);
	neg = 1;
	if (n < 0)
	{
		neg = -1;
		nb++;
	}
	if (!(res = (char *)malloc(sizeof(char) * nb + 1)))
		return (NULL);
	res[nb] = '\0';
	while (--nb > 0)
	{
		res[nb] = '0' + (n % 10) * neg;
		n = n / 10;
	}
	if (neg < 0)
		res[nb] = '-';
	else
		res[nb] = '0' + (n % 10);
	return (res);
}
