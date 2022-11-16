/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:24:06 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/16 11:08:32 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# ifdef MAC_KEYS
#  include "mac_keys.h"

# include <stdlib.h>
# include <unistd.h>
# include <complex.h>
# include <math.h>
# include <fcntl.h>
# include <limits.h>
# include "libft.h"
# include "mlx.h"
# include "get_next_line.h"

# ifdef DEBUG
#  define DBUG					1
# else
#  define DBUG					0
# endif

# define DESTROYNOTIFY			17
# define KEYPRESSMASK			(1L<<0)
# define KEYRELEASEMASK			(1L<<1)
# define KEYPRESS				2
# define KEYRELEASE				3

typedef	struct		s_ldpt
{
	long double		r;
	long double		i;
}					t_ldpt;

typedef struct		s_img
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

typedef	struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			*sce;
	t_key			keys;
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
	long double		sca;
	long double		off_x;
	long double		off_y;
	int				mouse_x;
	int				mouse_y;
	int				select;
	int				debug;
	int				guides;
	int				hud;
	int				hue;
	int				old_hue;
	double			dof_a;
	double			dof_b;
	double			dof_c;
	double			dof_s;
	long double		mod;
	int				mode;
	int				refresh;
	long double		p;
	long double		t;
}					t_env;

/*
*****		comment template		*****
*/

void				init(t_env *e);
int					scene_init(t_env *e);

int					quit(t_env *e);
void				error(char *str);
char				*get_fractal(t_env *e);

int					mlx_mouse_events(int btn, int x, int y, t_env *e);

int					mlx_main_loop(t_env *e);

void				mlx_keyboard_repeated(t_env *e);
int					mlx_key_release(int key, t_env *e);
int					mlx_key_press(int key, t_env *e);
int					mlx_key_simple(int key, t_env *e);

void				color_range_1_4(t_env *e, int x, int y, int i);
void				color_range_5_6(t_env *e, int x, int y, int i);
void				color_range_7(t_env *e, int x, int y, int i);
void				orbit_color_range(t_env *e, int x, int y, int i);
void				put_color(t_env *e, int x, int y, int i);
int					get_color(t_env *e, int x, int y);
int					set_color(int a, int r, int g, int b);

int					mlx_img_pix_put(t_img *sce, int x, int y, int color);
void				mlx_img_line(t_img *sce, t_ldpt p1, t_ldpt p2, int c);

void				mouse_zoom_in(t_env *e, int m_x, int m_y);
void				mouse_zoom_out(t_env *e, int m_x, int m_y);

void				burning_ship(t_env *e);
void				celtic(t_env *e);
void				juliapow(t_env *e);
void				mandeldrop(t_env *e);
void				multibrot(t_env *e);
void				tricornpow(t_env *e);
void				test(t_env *e);

void				refresh(t_env *e);
void				render(t_env *e);

void				hud(t_env *e);

int					usage(void);

void				mid_guides(t_env *e);

#endif
