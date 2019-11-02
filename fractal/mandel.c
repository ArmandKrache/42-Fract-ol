/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:47:17 by akrache           #+#    #+#             */
/*   Updated: 2019/02/07 19:48:31 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract.h"

static void	ft_melinit(t_mandl *m, int c, int x, int y)
{
	if (c == 0)
	{
		m->x1 = -2.1;
		m->x2 = 0.6;
		m->y1 = -1.2;
		m->y2 = 1.2;
		m->ite = 75 + m->i + m->te * 2;
	}
	else if (c == 1)
	{
		m->c_r = (((long double)x / HEIGHT) * (m->x2 - m->x1)
			+ m->posx) / m->z + m->x1 + m->zx;
		m->c_i = (((long double)y / HEIGHT) * (m->y2 - m->y1)
			+ m->posy) / m->z + m->y1 + m->zy;
		m->z_r = 0;
		m->z_i = 0;
	}
}

void		ft_mandelbrot(t_mandl *m, t_fract *tab)
{
	int		x;
	int		y;
	int		i;
	double	tmp;

	x = -1;
	ft_melinit(m, 0, 0, 0);
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			i = -1;
			ft_melinit(m, 1, x, y);
			while (m->z_r * m->z_r + m->z_i * m->z_i < 4 && ++i < m->ite)
			{
				tmp = m->z_r;
				m->z_r = ((m->z_r * m->z_r) - (m->z_i * m->z_i)) + m->c_r;
				m->z_i = ((m->z_i + m->z_i) * tmp + m->c_i);
			}
			ft_putpixel(tab, (long double)i / (m->ite), x, y);
		}
	}
	mlx_put_image_to_window(tab->mlx_ptr, tab->win_ptr, tab->img_ptr, 0, 0);
}
