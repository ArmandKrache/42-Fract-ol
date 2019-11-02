/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:17:35 by akrache           #+#    #+#             */
/*   Updated: 2019/02/01 18:19:58 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract.h"

int	key_pressed_c1(t_fract *tab, int keycode)
{
	if (tab->colormode != 1)
	{
		tab->colormode = 1;
		ft_display_again(tab, keycode);
	}
	return (keycode);
}

int	key_pressed_c2(t_fract *tab, int keycode)
{
	if (tab->colormode != 2)
	{
		tab->colormode = 2;
		ft_display_again(tab, keycode);
	}
	return (keycode);
}

int	key_pressed_c3(t_fract *tab, int keycode)
{
	if (tab->colormode != 3)
	{
		tab->colormode = 3;
		tab->nbl = 1;
		ft_display_again(tab, keycode);
	}
	return (keycode);
}

int	key_pressed_c4(t_fract *tab, int keycode)
{
	if (tab->colormode != 4)
	{
		tab->colormode = 4;
		ft_display_again(tab, keycode);
	}
	return (keycode);
}

int	key_pressed_c5(t_fract *tab, int keycode)
{
	if (tab->colormode != 5)
	{
		tab->colormode = 5;
		ft_display_again(tab, keycode);
	}
	return (keycode);
}
