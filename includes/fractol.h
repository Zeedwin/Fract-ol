/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:24:06 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/18 15:26:11 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <complex.h>
# include <limits.h>
# include <math.h>
# include "../minilibx_opengl_20191021/mlx.h"
# include "mac_keys.h"
# define DESTROYNOTIFY			17
# define KEYPRESS				2
# define KEYRELEASE				3

typedef struct s_ini
{
	long double		r;
	long double		i;
}					t_ini;

typedef struct s_img
{
	void			*p_img;
	char			*img;
	int				x;
	int				y;
	int				w;
	int				h;
	int				s_l;
	int				bpp;
	int				endian;
}					t_img;

typedef struct s_env
{
	void			*mlx;
	void			*win;
	t_img			*sce;
	char			keys[1024];
	char			*title;
	char			*fractal;
	char			*n_ite;
	char			*zoom;
	char			*m_x;
	char			*m_y;
	char			*palette;
	char			*hue_a;
	char			*hue_b;
	char			*hue_c;
	char			*hue_s;
	char			*power;
	int				m_w;
	int				m_h;
	int				w_w;
	int				w_h;
	int				s_w;
	int				s_h;
	int				s_x;
	int				s_y;
	int				cen_x;
	int				cen_y;
	int				ite;
	int				bud_min_ite;
	int				bud_max_ite;
	int				mouse_x;
	int				mouse_y;
	int				select;
	int				debug;
	int				guides;
	int				hud;
	int				hue;
	int				old_hue;
	int				mode;
	int				refresh;
	double			dof_a;
	double			dof_b;
	double			dof_c;
	double			dof_s;
	long double		sca;
	long double		o_x;
	long double		o_y;
	long double		mod;
	long double		p;
	long double		t;
}					t_env;

/*
*****		comment template		*****
*/

void				init(t_env *e);
void				ft_putendl(char *s);
void				error(char *str);
void				mlx_keyboard_repeated(t_env *e);
void				color_range_1_4(t_env *e, int x, int y, int i);
void				color_range_5_6(t_env *e, int x, int y, int i);
void				color_range_7(t_env *e, int x, int y, int i);
void				orbit_color_range(t_env *e, int x, int y, int i);
void				put_color(t_env *e, int x, int y, int i);
void				mouse_zoom_in(t_env *e, int m_x, int m_y);
void				mouse_zoom_out(t_env *e, int m_x, int m_y);
void				burning_ship(t_env *e);
void				julia(t_env *e);
void				mandelbrot(t_env *e);
void				refresh(t_env *e);
void				ft_render(t_env *e);
void				hud(t_env *e);
int					fractal_init(t_env *e);
int					quit(t_env *e);
int					mlx_mouse_events(int btn, int x, int y, t_env *e);
int					mlx_main_loop(t_env *e);
int					mlx_key_release(int key, t_env *e);
int					mlx_key_press(int key, t_env *e);
int					mlx_key_simple(int key, t_env *e);
int					get_color(t_env *e, int x, int y);
int					set_color(int a, int r, int g, int b);
int					mlx_img_pix_put(t_img *sce, int x, int y, int color);
int					usage(void);
int					ft_abs(int i);
char				*get_fractal(t_env *e);

#endif
