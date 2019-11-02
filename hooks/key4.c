/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 13:26:23 by akrache           #+#    #+#             */
/*   Updated: 2019/02/07 14:43:40 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract.h"

int	key_pressed_ar(t_fract *tab, int keycode)
{
	tab->m->posx -= 0.2;
	ft_display_again(tab, keycode);
	return (keycode);
}

int	key_pressed_al(t_fract *tab, int keycode)
{
	tab->m->posx += 0.2;
	ft_display_again(tab, keycode);
	return (keycode);
}

int	key_pressed_au(t_fract *tab, int keycode)
{
	tab->m->posy += 0.2;
	ft_display_again(tab, keycode);
	return (keycode);
}

int	key_pressed_ad(t_fract *tab, int keycode)
{
	tab->m->posy -= 0.2;
	ft_display_again(tab, keycode);
	return (keycode);
}

int	key_pressed_space(t_fract *tab, int keycode)
{
	tab->m->posx = 0;
	tab->m->posy = 0;
	tab->m->z = 1.0;
	tab->m->zx = 0.0;
	tab->m->zy = 0.0;
	tab->m->i = 0;
	tab->m->te = 0;
	if (tab->colormode == 3)
		tab->nbl = 1;
	else
		tab->nbl = 64;
	if (tab->act == 2 && keycode == 49)
	{
		tab->m->jc_r = 0.333333;
		tab->m->jc_i = -0.031200;
	}
	else if (tab->act == 5 && keycode == 49)
	{
		tab->m->tc_r = 0.0;
		tab->m->tc_i = 0.0;
	}
	ft_display_again(tab, keycode);
	return (keycode);
}
