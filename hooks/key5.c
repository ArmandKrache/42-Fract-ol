/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 12:39:13 by akrache           #+#    #+#             */
/*   Updated: 2019/02/07 19:48:04 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract.h"

int	mouse_move(int x, int y, t_fract *tab)
{
	if ((x >= 0 && x <= WIDTH) && (y >= 0 && y <= HEIGHT))
	{
		tab->x = x;
		tab->y = y;
	}
	else
	{
		tab->x = WIDTH / 2;
		tab->y = HEIGHT / 2;
	}
	mouse_julia(tab, x, y);
	return (0);
}

int	mouse_julia(t_fract *tab, int x, int y)
{
	if (tab->lock && (tab->act == 2 || tab->act == 5) && (x >= 0 && x <= WIDTH)
		&& (y >= 0 && y <= HEIGHT))
	{
		if (tab->act == 2)
		{
			tab->m->jc_r = x * (tab->m->x2 - tab->m->x1) / WIDTH + tab->m->x1;
			tab->m->jc_i = y * (tab->m->y2 - tab->m->y1) / HEIGHT + tab->m->y1;
		}
		else if (tab->act == 5)
		{
			tab->m->tc_r = x * (tab->m->x2 - tab->m->x1) / WIDTH + tab->m->x1;
			tab->m->tc_i = y * (tab->m->y2 - tab->m->y1) / HEIGHT + tab->m->y1;
		}
		ft_display_again(tab, -1);
	}
	return (1);
}

int	key_pressed_c6(t_fract *tab, int keycode)
{
	if (tab->colormode != 6)
	{
		tab->colormode = 6;
		tab->nbl = 64;
		ft_display_again(tab, keycode);
	}
	return (keycode);
}

int	key_pressed_c7(t_fract *tab, int keycode)
{
	if (tab->colormode != 7)
	{
		tab->colormode = 7;
		tab->nbl = 64;
		ft_display_again(tab, keycode);
	}
	return (keycode);
}

int	mouse_press(int button, int x, int y, t_fract *tab)
{
	if ((x >= 0 && x <= WIDTH) && (y >= 0 && y <= HEIGHT))
	{
		tab->x = x;
		tab->y = y;
		if (button == 4)
			key_pressed_i(tab, -13);
		if (button == 5)
			key_pressed_o(tab, -13);
	}
	return (0);
}
