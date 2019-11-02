/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key6.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:57:31 by akrache           #+#    #+#             */
/*   Updated: 2019/11/02 16:44:32 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract.h"

int	key_pressed_4(t_fract *tab, int keycode)
{
	tab->act = 4;
	key_pressed_space(tab, keycode);
	return (keycode);
}

int	key_pressed_5(t_fract *tab, int keycode)
{
	tab->act = 5;
	tab->lock = 0;
	key_pressed_space(tab, keycode);
	return (keycode);
}

int	key_pressed_6(t_fract *tab, int keycode)
{
	tab->act = 6;
	tab->lock = 0;
	key_pressed_space(tab, keycode);
	return (keycode);
}

int	key_pressed_iteplus(t_fract *tab, int keycode)
{
	if (tab->m->i + tab->m->te < 5000)
		tab->m->i += 2;
	ft_display_again(tab, keycode);
	return (keycode);
}

int	key_pressed_iteminus(t_fract *tab, int keycode)
{
	tab->m->i -= 2;
	ft_display_again(tab, keycode);
	return (keycode);
}

int	key_pressed_itereset(t_fract *tab, int keycode)
{
	tab->m->i = 0;
	ft_display_again(tab, keycode);
	return (keycode);
}
