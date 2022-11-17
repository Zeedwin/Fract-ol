/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_color_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 00:20:00 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/17 16:05:33 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	orbit_color_range(t_env *e, int x, int y, int i)
{
	int		a;
	int		r;
	int		g;
	int		b;

	a = 0;
	r = 0;
	g = 0;
	b = 0;
	e->t /= (long double)i;
	r = (int)((e->t) * e->dof_a * 255);
	g = (int)((e->t) * e->dof_b * 255);
	b = (int)((e->t) * e->dof_c * 255);
	e->hue = set_color(a, r, g, b);
	e->old_hue = e->hue;
	mlx_img_pix_put(e->sce, x, y, e->hue);
}

void	color_range_7(t_env *e, int x, int y, int i)
{
	int		a;
	int		r;
	int		g;
	int		b;
	float	hue_index;

	a = 0;
	r = 0;
	g = 0;
	b = 0;
	hue_index = (i + 1 - (log(2) / e->mod)) / log(2);
	e->hue = 0x00000000;
	if (e->mode == 7)
	{
		r = sin(e->dof_a * hue_index + 0.1) * 127 + 120;
		g = sin(e->dof_b * hue_index + 0.5) * 127 + 120;
		b = sin(e->dof_c * hue_index + 0.7) * 127 + 120;
	}
	e->hue = set_color(a, r, g, b);
	e->old_hue = e->hue;
	mlx_img_pix_put(e->sce, x, y, e->hue);
}

void	color_range_5_6(t_env *e, int x, int y, int i)
{
	int		a;
	int		r;
	int		g;
	int		b;

	a = 0;
	r = 0;
	g = 0;
	b = 0;
	if (e->mode == 5)
	{
		r = ((i * i + 30) * 125 / e->ite);
		g = ((i * i + 120) * 125 / e->ite);
		b = (i * i + 60) * 125 / e->ite;
	}
	else if (e->mode == 6)
	{
		r = ((i * i + 10) * 255 / e->ite);
		g = ((i * i + 20) * 255 / e->ite);
		b = (i * i + 30) * 255 / e->ite;
	}
	e->hue = set_color(a, r, g, b);
	e->old_hue = e->hue;
	mlx_img_pix_put(e->sce, x, y, e->hue);
}

void	color_range_1_4(t_env *e, int x, int y, int i)
{
	int		a;
	int		r;
	int		g;
	int		b;

	a = 0;
	r = 0;
	g = 0;
	b = 0;
	if (e->mode == 1)
	{
		r = ((i * i + 60) * 255 / e->ite);
		g = ((i * i + 80) * 255 / e->ite);
		b = (i * i + 120) * 255 / e->ite;
	}
	else if (e->mode == 2)
		r = ((i * 255) / e->ite);
	else if (e->mode == 3)
		g = ((i * 255) / e->ite);
	else if (e->mode == 4)
		b = (i * 255) / e->ite;
	e->hue = set_color(a, r, g, b);
	e->old_hue = e->hue;
	mlx_img_pix_put(e->sce, x, y, e->hue);
}
