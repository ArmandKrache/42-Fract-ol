/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:12:22 by akrache           #+#    #+#             */
/*   Updated: 2019/02/05 17:30:19 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract.h"

int	key_pressed_q(t_fract *tab, int keycode)
{
	mlx_clear_window(tab->mlx_ptr, tab->win_ptr);
	ft_bzero(tab->img_adr, WIDTH * HEIGHT * (tab->bpp / 8));
	return (keycode);
}

int	key_pressed_esc(t_fract *tab, int keycode)
{
	key_pressed_q(tab, keycode);
	mlx_destroy_image(tab->mlx_ptr, tab->img_ptr);
	mlx_destroy_window(tab->mlx_ptr, tab->win_ptr);
	free(tab->mlx_ptr);
	free(tab->m);
	free(tab->pal2);
	free(tab->pal);
	free(tab);
	ft_putstr("Exiting program\n");
	exit(0);
	return (keycode);
}

int	key_pressed_1(t_fract *tab, int keycode)
{
	tab->act = 1;
	key_pressed_space(tab, keycode);
	return (keycode);
}

int	key_pressed_2(t_fract *tab, int keycode)
{
	tab->act = 2;
	tab->lock = 0;
	key_pressed_space(tab, keycode);
	return (keycode);
}

int	key_pressed_3(t_fract *tab, int keycode)
{
	tab->act = 3;
	key_pressed_space(tab, keycode);
	return (keycode);
}
