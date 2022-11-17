/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 00:20:00 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/17 16:08:14 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	scene_init(t_env *e)
{
	int			bpp;
	int			s_l;
	int			endian;

	e->sce = malloc(sizeof(t_img));
	e->s_w = e->w_w;
	e->s_h = e->w_h;
	e->sce->p_img = mlx_new_image(e->mlx, e->s_w, e->s_h);
	e->sce->img = mlx_get_data_addr(e->sce->p_img, &(bpp), &(s_l), &(endian));
	e->sce->bpp = bpp;
	e->sce->s_l = s_l;
	e->sce->w = e->s_w;
	e->sce->h = e->s_h;
	e->sce->endian = endian;
	e->cen_x = e->s_w / 2;
	e->cen_y = e->s_h / 2;
	e->o_x = (float)e->cen_x;
	e->o_y = (float)e->cen_y;
	return (0);
}

static void	options_init(t_env *e)
{
	e->w_w = 1540;
	e->w_h = 1000;
	e->sca = 400;
	e->ite = 150;
	e->bud_min_ite = 150;
	e->bud_max_ite = 10000;
	e->mod = 0;
	e->hue = 0x00000000;
	e->old_hue = 0x00000000;
	e->dof_a = 11.0;
	e->dof_b = 12.0;
	e->dof_c = 13.0;
	e->dof_s = 2.0;
	e->mode = 1;
	e->mouse_x = 0;
	e->mouse_y = 0;
	e->guides = -1;
	e->hud = -1;
	e->refresh = 1;
	e->p = 2.0;
	e->t = 0;
	if (DBUG == 1)
		e->debug = 1;
}

void	init(t_env *e)
{
	options_init(e);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->w_w, e->w_h, "Fract'ol");
	scene_init(e);
}
