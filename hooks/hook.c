/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:10:43 by akrache           #+#    #+#             */
/*   Updated: 2019/11/02 16:53:39 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract.h"

static int	key_hook3(int keycode, t_fract *tab)
{
	if (keycode == 21)
		key_pressed_4(tab, keycode);
	else if (keycode == 23)
		key_pressed_5(tab, keycode);
	else if (keycode == 22)
		key_pressed_6(tab, keycode);
	else if (keycode == 47)
		key_pressed_iteplus(tab, keycode);
	else if (keycode == 43)
		key_pressed_iteminus(tab, keycode);
	else if (keycode == 44)
		key_pressed_itereset(tab, keycode);
	return (keycode);
}

static int	key_hook2(int keycode, t_fract *tab)
{
	if (keycode == 37)
		key_pressed_l(tab, keycode);
	else if (keycode == 123)
		key_pressed_al(tab, keycode);
	else if (keycode == 124)
		key_pressed_ar(tab, keycode);
	else if (keycode == 126)
		key_pressed_au(tab, keycode);
	else if (keycode == 125)
		key_pressed_ad(tab, keycode);
	else if (keycode == 49)
		key_pressed_space(tab, keycode);
	else if (keycode == 34)
		key_pressed_i(tab, keycode);
	else if (keycode == 31)
		key_pressed_o(tab, keycode);
	else if (keycode == 11)
		key_pressed_c5(tab, keycode);
	else if (keycode == 45)
		key_pressed_c6(tab, keycode);
	else if (keycode == 46)
		key_pressed_c7(tab, keycode);
	return (key_hook3(keycode, tab));
}

int			key_hook(int keycode, t_fract *tab)
{
	if (keycode == 53)
		key_pressed_esc(tab, keycode);
	else if (keycode == 12)
		key_pressed_q(tab, keycode);
	else if (keycode == 18)
		key_pressed_1(tab, keycode);
	else if (keycode == 19)
		key_pressed_2(tab, keycode);
	else if (keycode == 20)
		key_pressed_3(tab, keycode);
	else if (keycode == 6)
		key_pressed_c1(tab, keycode);
	else if (keycode == 7)
		key_pressed_c2(tab, keycode);
	else if (keycode == 8)
		key_pressed_c3(tab, keycode);
	else if (keycode == 9)
		key_pressed_c4(tab, keycode);
	else if (keycode == 69)
		key_pressed_plus(tab, keycode);
	else if (keycode == 78)
		key_pressed_minus(tab, keycode);
	return (key_hook2(keycode, tab));
}

int			ft_display_again(t_fract *tab, int keycode)
{
	key_pressed_q(tab, keycode);
	if (tab->act == 1)
		ft_mandelbrot(tab->m, tab);
	else if (tab->act == 2)
		ft_julia(tab->m, tab);
	else if (tab->act == 3)
		ft_burningship(tab->m, tab);
	else if (tab->act == 4)
		ft_tippetts(tab->m, tab);
	else if (tab->act == 5)
		ft_thorn(tab->m, tab);
	else if (tab->act == 6)
		ft_sativa(tab->m, tab);
	return (keycode);
}
