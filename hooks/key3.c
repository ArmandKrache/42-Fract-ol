/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 16:31:43 by akrache           #+#    #+#             */
/*   Updated: 2019/02/07 19:47:03 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract.h"

int	key_pressed_plus(t_fract *tab, int keycode)
{
	if (tab->colormode == 3 || tab->colormode == 7 || tab->colormode == 6)
	{
		if (tab->nbl >= 64)
			tab->nbl = 128;
		else
			tab->nbl = tab->nbl * 2;
		ft_display_again(tab, keycode);
	}
	return (keycode);
}

int	key_pressed_minus(t_fract *tab, int keycode)
{
	if (tab->colormode == 3 || tab->colormode == 7 || tab->colormode == 6)
	{
		if (tab->nbl <= 1)
			tab->nbl = 1;
		else
			tab->nbl = tab->nbl / 2;
		ft_display_again(tab, keycode);
	}
	return (keycode);
}

int	key_pressed_l(t_fract *tab, int keycode)
{
	if (tab->act == 2 || tab->act == 5)
	{
		if (tab->lock)
			tab->lock = 0;
		else
			tab->lock = 1;
	}
	return (keycode);
}

int	key_pressed_i(t_fract *tab, int keycode)
{
	long double w;
	long double h;
	long double nw;
	long double nh;

	w = (tab->m->x2 - tab->m->x1) / (tab->m->z);
	h = (tab->m->y2 - tab->m->y1) / (tab->m->z);
	tab->m->z *= 2.0;
	nw = (tab->m->x2 - tab->m->x1) / (tab->m->z);
	nh = (tab->m->y2 - tab->m->y1) / (tab->m->z);
	tab->m->zx -= (((long double)tab->x / HEIGHT) * (nw - w))
		- (tab->m->posx / tab->m->z);
	tab->m->zy -= (((long double)tab->y / HEIGHT) * (nh - h))
		- (tab->m->posy / tab->m->z);
	(tab->m->te < 5000 ? tab->m->te++ : 0);
	ft_display_again(tab, keycode);
	return (keycode);
}

int	key_pressed_o(t_fract *tab, int keycode)
{
	double w;
	double h;
	double nw;
	double nh;

	w = (tab->m->x2 - tab->m->x1) / (tab->m->z);
	h = (tab->m->y2 - tab->m->y1) / (tab->m->z);
	tab->m->z /= 2.0;
	nw = (tab->m->x2 - tab->m->x1) / (tab->m->z);
	nh = (tab->m->y2 - tab->m->y1) / (tab->m->z);
	tab->m->zx -= (((long double)tab->x / HEIGHT) * (nw - w))
		+ ((tab->m->posx / (tab->m->z * 2.0)));
	tab->m->zy -= (((long double)tab->y / HEIGHT) * (nh - h))
		+ ((tab->m->posy / (tab->m->z * 2.0)));
	(tab->m->te > 0 ? tab->m->te-- : 0);
	ft_display_again(tab, keycode);
	return (keycode);
}
