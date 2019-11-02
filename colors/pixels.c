/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:27:36 by akrache           #+#    #+#             */
/*   Updated: 2019/02/07 15:50:47 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract.h"

void		img_pixel_put(t_fract *tab, int x, int y, int c)
{
	int i;

	if (x >= 0 && x < WIDTH)
	{
		if (y >= 0 && y < HEIGHT)
		{
			i = 0;
			while (i < (tab->bpp / 8))
			{
				tab->img_adr[x * (tab->bpp / 8) + (y * tab->sl) + i] = c & 255;
				i++;
				c = c >> 8;
			}
		}
	}
}

int			ft_colormode7(t_fract *tab, long double max)
{
	return (tab->pal2[lrint(max * 64)]);
}

int			ft_getcolor(t_fract *tab, long double max)
{
	if (tab->colormode == 1)
		return (ft_colormode1(max));
	else if (tab->colormode == 2)
		return (ft_colormode2(max));
	else if (tab->colormode == 3)
		return (ft_colormode3(tab, max));
	else if (tab->colormode == 4)
		return (ft_colormode4(max));
	else if (tab->colormode == 6)
		return (ft_colormode6(tab, max));
	else if (tab->colormode == 7)
		return (ft_colormode7(tab, max));
	else
		return (0);
}

void		ft_putpixel(t_fract *tab, long double max, int x, int y)
{
	int col;

	col = 0;
	(tab->colormode == 5 ? col = 0xFF0000 : 0);
	(tab->colormode == 2 ? col = 0xe7dbf6 : 0);
	if (max == 1.0)
		img_pixel_put(tab, x, y, col);
	else
		img_pixel_put(tab, x, y, ft_getcolor(tab, max));
}
