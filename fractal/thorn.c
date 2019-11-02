/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thorn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:51:21 by akrache           #+#    #+#             */
/*   Updated: 2019/02/07 19:44:42 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract.h"

static void	ft_thorninit(t_mandl *m, int c, int x, int y)
{
	if (c == 0)
	{
		m->x1 = -1.2;
		m->x2 = 0.8;
		m->y1 = -1.0;
		m->y2 = 1.0;
		m->ite = 45 + m->i;
	}
	else if (c == 1)
	{
		m->z_r = ((long double)x / HEIGHT * (m->x2 - m->x1)
			+ m->posx) / m->z + m->zx + m->x1;
		m->z_i = ((long double)y / HEIGHT * (m->y2 - m->y1)
			+ m->posy) / m->z + m->zy + m->y1;
	}
}

void		ft_thorn(t_mandl *m, t_fract *tab)
{
	int		x;
	int		y;
	int		i;
	double	tmp;

	x = -1;
	ft_thorninit(m, 0, 0, 0);
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			i = -1;
			ft_thorninit(m, 1, x, y);
			while ((m->z_r * m->z_r + m->z_i * m->z_i < 1000) && ++i < m->ite)
			{
				tmp = m->z_r;
				m->z_r = m->z_r / cos(m->z_i) + m->tc_r;
				m->z_i = m->z_i / sin(tmp) + m->tc_i;
			}
			ft_putpixel(tab, (long double)i / (long double)m->ite, x, y);
		}
	}
	mlx_put_image_to_window(tab->mlx_ptr, tab->win_ptr, tab->img_ptr, 0, 0);
}
