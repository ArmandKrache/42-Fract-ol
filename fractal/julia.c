/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:32:25 by akrache           #+#    #+#             */
/*   Updated: 2019/02/07 20:30:57 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract.h"

static void	ft_juliainit(t_mandl *m, int c, int x, int y)
{
	if (c == 0)
	{
		m->x1 = -1.5;
		m->x2 = 1;
		m->y1 = -1.2;
		m->y2 = 1.2;
		m->ite = 45 + m->i + m->te;
	}
	else if (c == 1)
	{
		m->z_r = ((long double)x / HEIGHT * (m->x2 - m->x1)
			+ m->posx) / m->z + m->zx + m->x1;
		m->z_i = ((long double)y / HEIGHT * (m->y2 - m->y1)
			+ m->posy) / m->z + m->zy + m->y1;
	}
}

void		ft_julia(t_mandl *m, t_fract *tab)
{
	int		x;
	int		y;
	int		i;
	double	tmp;

	x = -1;
	ft_juliainit(m, 0, 0, 0);
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			i = -1;
			ft_juliainit(m, 1, x, y);
			while (m->z_r * m->z_r + m->z_i * m->z_i < 4 && ++i < m->ite)
			{
				tmp = m->z_r;
				m->z_r = ((m->z_r * m->z_r) - (m->z_i * m->z_i)) + m->jc_r;
				m->z_i = ((m->z_i + m->z_i) * tmp + m->jc_i);
			}
			ft_putpixel(tab, (long double)i / (long double)m->ite, x, y);
		}
	}
	mlx_put_image_to_window(tab->mlx_ptr, tab->win_ptr, tab->img_ptr, 0, 0);
}
