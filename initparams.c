/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initparams.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juleng <juleng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:35:14 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/14 11:01:55 by juleng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "fractol.h"

int				imginit(t_params *f)
{
	int			bpp;
	int			s_l;
	int			endian;

	if (!(f->sce = malloc(sizeof(t_img))))
		error("\x1b[2;31mCan't initialize the scene\x1b[0m");
	f->s_w = f->w_w;
	f->s_h = f->w_h;
	f->sce->p_img = mlx_new_image(e->mlx, e->s_w, e->s_h);
	f->sce->img = mlx_get_data_addr(e->sce->p_img, &(bpp), &(s_l), &(endian));
	f->sce->bpp = bpp;
	f->sce->s_l = s_l;
	f->sce->w = f->s_w;
	f->sce->h = f->s_h;
	f->sce->endian = endian;
	f->cen_x = f->s_w / 2;
	f->cen_y = f->s_h / 2;
	f->off_x = (float)f->cen_x;
	f->off_y = (float)f->cen_y;
	return (0);
}

static void		options_init(t_params *f)
{
	f->w_w = 1440;
	f->w_h = 900;
	f->sca = 400;
	f->ite = 50;
	f->bud_min_ite = 50;
	f->bud_max_ite = 10000;
	f->mod = 0;
	f->hue = 0x00000000;
	f->old_hue = 0x00000000;
	f->dof_a = 11.0;
	f->dof_b = 12.0;
	f->dof_c = 13.0;
	f->dof_s = 2.0;
	f->mode = 1;
	f->mouse_x = 0;
	f->mouse_y = 0;
	f->guides = -1;
	f->hud = -1;
	f->refresh = 1;
	f->p = 2.0;
	f->t = 0;
	if (DBUG == 1)
		f->debug = 1;
}

void			init(t_params *f)
{
	options_init(f);
	if (!(f->mlx = mlx_init()))
		error("\x1b[2;31mError can't initialize minilibx\x1b[0m");
	if (!(f->win = mlx_new_window(f->mlx, f->w_w, f->w_h, "Fract'ol")))
		error("\x1b[2;31mError minilibx window creation failed\x1b[0m");
	scene_init(f);
}
