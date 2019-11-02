/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 13:14:43 by akrache           #+#    #+#             */
/*   Updated: 2019/11/02 16:57:23 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int				fract_usage(int r)
{
	ft_putendl("usage: ./fract <Valid_fractal>");
	ft_putendl("Valid fractals:");
	ft_putendl("               Mandelbrot");
	ft_putendl("               Julia");
	ft_putendl("               Ship");
	ft_putendl("               Tippetts");
	ft_putendl("               Thorn");
	ft_putendl("               Sativa");
	return (r);
}

static void		fract_tab_init(t_fract *tab, int act)
{
	tab->bpp = 32;
	tab->sl = 4 * WIDTH;
	tab->endian = 1;
	tab->mlx_ptr = mlx_init();
	tab->win_ptr = mlx_new_window(tab->mlx_ptr, WIDTH, HEIGHT, "Fract'ol");
	tab->img_ptr = mlx_new_image(tab->mlx_ptr, WIDTH, HEIGHT);
	tab->img_adr = mlx_get_data_addr(tab->img_ptr,
	&(tab->bpp), &(tab->sl), &(tab->endian));
	tab->color = 0xFFFFFF;
	tab->colormode = 6;
	tab->nbl = 64;
	tab->lock = 0;
	tab->act = act;
	tab->m->posx = 0.0;
	tab->m->posy = 0.0;
	tab->m->z = 1.0;
	if (!ft_init_pal(tab))
		tab->act = 0;
	if (!ft_init_pal4(tab))
	{
		free(tab->pal);
		tab->act = 0;
	}
}

static int		display_fract(t_fract *tab, char *param)
{
	tab->act = 0;
	tab->m->jc_r = 0.333333;
	tab->m->jc_i = -0.031200;
	tab->m->tc_r = 0.0;
	tab->m->tc_i = 0.0;
	tab->m->i = 0;
	tab->m->te = 0;
	tab->act = 0;
	if (!ft_strcmp(param, "Mandelbrot") || !ft_strcmp(param, "mandelbrot"))
		fract_tab_init(tab, 1);
	else if (!ft_strcmp(param, "Julia") || !ft_strcmp(param, "julia"))
		fract_tab_init(tab, 2);
	else if (!ft_strcmp(param, "Ship") || !ft_strcmp(param, "ship"))
		fract_tab_init(tab, 3);
	else if (!ft_strcmp(param, "Tippetts") || !ft_strcmp(param, "tippetts"))
		fract_tab_init(tab, 4);
	else if (!ft_strcmp(param, "Thorn") || !ft_strcmp(param, "thorn"))
		fract_tab_init(tab, 5);
	else if (!ft_strcmp(param, "Sativa") || !ft_strcmp(param, "sativa"))
		fract_tab_init(tab, 6);
	return (tab->act ? ft_display_again(tab, -1) : fract_usage(0));
}

static void		hooks(t_fract *tab)
{
	mlx_hook(tab->win_ptr, 2, 0, key_hook, tab);
	mlx_hook(tab->win_ptr, 4, 0, mouse_press, tab);
	mlx_hook(tab->win_ptr, 6, 0, mouse_move, tab);
	mlx_hook(tab->win_ptr, 17, 0, key_pressed_esc, tab);
}

int				main(int argc, char *argv[])
{
	t_fract *tab;

	if (argc != 2)
		return (fract_usage(0));
	if (!(tab = (t_fract *)malloc(sizeof(t_fract))))
	{
		return (0);
	}
	if (!(tab->m = (t_mandl *)malloc(sizeof(t_mandl))))
	{
		free(tab);
		return (0);
	}
	if (!display_fract(tab, argv[1]))
	{
		free(tab->m);
		free(tab);
		return (0);
	}
	hooks(tab);
	mlx_loop(tab->mlx_ptr);
	return (0);
}
