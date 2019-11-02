/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 11:56:20 by akrache           #+#    #+#             */
/*   Updated: 2019/11/02 16:53:39 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# include "libft/libft.h"
# include <math.h>
# include "mlx.h"

# define WIDTH 1200
# define HEIGHT 1000

typedef struct	s_mandl
{
	long double	x1;
	long double	x2;
	long double	y1;
	long double	y2;
	long double	zoom;
	int			ite;
	int			i;
	int			te;
	long double	c_r;
	long double	c_i;
	long double	z_r;
	long double	z_i;
	long double	jc_r;
	long double	jc_i;
	long double	tc_r;
	long double	tc_i;
	long double	posx;
	long double	posy;
	long double	zx;
	long double	zy;
	long double	z;
}				t_mandl;

typedef struct	s_fract
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img_adr;
	t_mandl		*m;
	int			bpp;
	int			sl;
	int			endian;
	int			color;
	int			colormode;
	int			act;
	int			nbl;
	int			lock;
	long double	x;
	long double	y;
	int			*pal;
	int			*pal2;
}				t_fract;

void			ft_mandelbrot(t_mandl *m, t_fract *tab);
void			ft_julia(t_mandl *m, t_fract *tab);
void			ft_burningship(t_mandl *m, t_fract *tab);
void			ft_tippetts(t_mandl *m, t_fract *tab);
void			ft_thorn(t_mandl *m, t_fract *tab);
void			ft_sativa(t_mandl *m, t_fract *tab);

void			ft_putpixel(t_fract *tab, long double max, int x, int y);
void			img_pixel_put(t_fract *tab, int x, int y, int clr);
int				ft_getcolor(t_fract *tab, long double max);
int				ft_colormode1(long double max);
int				ft_colormode2(long double max);
int				ft_colormode3(t_fract *tab, long double max);
int				ft_colormode4(long double max);
int				ft_colormode6(t_fract *tab, long double max);
int				ft_colormode7(t_fract *tab, long double max);
int				ft_init_pal(t_fract *tab);
int				ft_init_pal4(t_fract *tab);

int				key_hook(int keycode, t_fract *tab);
int				mouse_move(int x, int y, t_fract *tab);
int				mouse_press(int button, int x, int y, t_fract *tab);
int				mouse_julia(t_fract *tab, int x, int y);
int				ft_display_again(t_fract *tab, int keycode);
int				key_pressed_esc(t_fract *tab, int keycode);
int				key_pressed_q(t_fract *tab, int keycode);
int				key_pressed_1(t_fract *tab, int keycode);
int				key_pressed_2(t_fract *tab, int keycode);
int				key_pressed_3(t_fract *tab, int keycode);
int				key_pressed_4(t_fract *tab, int keycode);
int				key_pressed_5(t_fract *tab, int keycode);
int				key_pressed_6(t_fract *tab, int keycode);
int				key_pressed_c1(t_fract *tab, int keycode);
int				key_pressed_c2(t_fract *tab, int keycode);
int				key_pressed_c3(t_fract *tab, int keycode);
int				key_pressed_c4(t_fract *tab, int keycode);
int				key_pressed_c5(t_fract *tab, int keycode);
int				key_pressed_c6(t_fract *tab, int keycode);
int				key_pressed_c7(t_fract *tab, int keycode);
int				key_pressed_plus(t_fract *tab, int keycode);
int				key_pressed_minus(t_fract *tab, int keycode);
int				key_pressed_l(t_fract *tab, int keycode);
int				key_pressed_space(t_fract *tab, int keycode);
int				key_pressed_ad(t_fract *tab, int keycode);
int				key_pressed_au(t_fract *tab, int keycode);
int				key_pressed_al(t_fract *tab, int keycode);
int				key_pressed_ar(t_fract *tab, int keycode);
int				key_pressed_i(t_fract *tab, int keycode);
int				key_pressed_o(t_fract *tab, int keycode);
int				key_pressed_iteplus(t_fract *tab, int keycode);
int				key_pressed_iteminus(t_fract *tab, int keycode);
int				key_pressed_itereset(t_fract *tab, int keycode);

#endif
