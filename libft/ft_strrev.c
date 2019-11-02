/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 09:35:00 by akrache           #+#    #+#             */
/*   Updated: 2018/11/16 12:17:49 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		len;
	int		cpt;
	char	tmp;

	len = ft_strlen(str);
	cpt = 0;
	while (cpt < len)
	{
		tmp = str[cpt];
		str[cpt] = str[len - 1];
		str[len - 1] = tmp;
		cpt = cpt + 1;
		len = len - 1;
	}
	return (str);
}
