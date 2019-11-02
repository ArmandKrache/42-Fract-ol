/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colormode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:12:31 by akrache           #+#    #+#             */
/*   Updated: 2019/02/07 15:56:53 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract.h"

int	ft_colormode2(long double max)
{
	int res;

	res = 0xFFF000 * max;
	res = (((0xFF & res) << 16) + ((0xFF0000 & res) >> 16));
	return (res);
}

int	ft_colormode1(long double max)
{
	int res;
	int pal[7];

	pal[0] = 0xFFFFFF;
	pal[1] = 0xd4fbff;
	pal[2] = 0xaaf7ff;
	pal[3] = 0x7ff4ff;
	pal[4] = 0x55f0ff;
	pal[5] = 0x2aecff;
	pal[6] = 0x00E9FF;
	res = pal[lrint(max * 7)];
	return (res);
}

int	ft_colormode3(t_fract *tab, long double max)
{
	int res;
	int tmp;

	tmp = (((0xFF0000 & tab->color) >> 16) * max
		+ ((0xFF00 & tab->color) >> 8) * max + (0xFF & tab->color) * max) / 3;
	res = 0;
	res = ((tmp << 16) * tab->nbl) % 0xF000000
		+ ((tmp << 8) * tab->nbl) % 0xF0000 + (tmp * tab->nbl) % 256;
	return (res);
}

int	ft_colormode4(long double max)
{
	int res;

	res = (lrint(0xFF00 * max) << 16) >> 8;
	return (res < 0xF000 ? res << 8 : res);
}

int	ft_colormode6(t_fract *tab, long double max)
{
	return (tab->pal[lrint(max * 64)]);
}
