/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sativa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:48:18 by akrache           #+#    #+#             */
/*   Updated: 2019/11/02 16:42:40 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract.h"

static void	ft_sativainit(t_mandl *m, int c, int x, int y)
{
	if (c == 0)
	{
		m->x1 = -1.1;
		m->x2 = 0.6;
		m->y1 = -1.2;
		m->y2 = 1.2;
		m->ite = 75 + m->i + m->te * 2;
	}
	else if (c == 1)
	{
		m->c_i = (((long double)x / HEIGHT) * (m->x2 - m->x1)
			+ m->posx) / m->z + m->x1 + m->zx;
		m->c_r = (((long double)y / HEIGHT) * (m->y2 - m->y1)
			+ m->posy) / m->z + m->y1 + m->zy;
		m->z_r = 0;
		m->z_i = 0;
	}
}

void		ft_sativa(t_mandl *m, t_fract *tab)
{
	int		x;
	int		y;
	int		i;
	double	z;
	double	z2;
	double	tmp;
	double	tmp2;

	x = -1;
	ft_sativainit(m, 0, 0, 0);
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			i = -1;
			ft_sativainit(m, 1, x, y);
			z = 0;
			z2 = 0;
			while (m->z_r * m->z_r + m->z_i * m->z_i < 4 && ++i < m->ite)
			{
				tmp = m->z_i;
				tmp2 = m->z_r;
				m->z_i = ((m->z_i * m->z_i) - (m->z_r * m->z_r)) + m->c_r + z;
				m->z_r = ((m->z_r + m->z_r) * tmp + m->c_i + z2);
				z = tmp;
				z2 = tmp2;
			}
			ft_putpixel(tab, (long double)i / (m->ite), x, y);
		}
	}
	mlx_put_image_to_window(tab->mlx_ptr, tab->win_ptr, tab->img_ptr, 0, 0);
}
