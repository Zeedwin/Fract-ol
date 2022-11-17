/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:34:10 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/17 12:25:58 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void					multibrot_test(t_env *e, int x, int y)
{
	long double _Complex	c;
	long double _Complex	z;
	int						i;

	i = 0;
	c = ((x - e->o_x) / e->sca) + (((y - e->o_y) / e->sca) * I);
	z = 0 + (0 * I);
	while (e->mod < 4 && i < e->ite)
	{
		z = cpowf(z, e->p) + c;
		e->mod = crealf(z) * crealf(z) + cimagf(z) * cimagf(z);
		if (e->mode == 8)
			e->t += 0.5 * sinf(e->dof_s * carg(z)) + 0.5;
		i++;
	}
	if (i == e->ite)
		mlx_img_pix_put(e->sce, x, y, 0x00000000);
	else
		put_color(e, x, y, i);
}

static void					mandelbrot_test(t_env *e, int x, int y)
{
	t_ldpt					c;
	t_ldpt					z;
	long double				tmp;
	int						i;

	i = 0;
	c.r = ((long double)x - e->o_x) / e->sca;
	c.i = ((long double)y - e->o_y) / e->sca;
	z.r = 0;
	z.i = 0;
	while (i < e->ite && e->mod < 4)
	{
		tmp = z.r;
		z.r = (tmp * tmp) - (z.i * z.i) + c.r;
		z.i = (2 * z.i * tmp) + c.i;
		e->mod = (z.r * z.r) + (z.i * z.i);
		if (e->mode == 8)
			e->t += 0.5 * sinf(e->dof_s * CMPLXF(z.r, z.i)) + 0.5;
		i++;
	}
	if (i == e->ite)
		mlx_img_pix_put(e->sce, x, y, 0x00000000);
	else
		put_color(e, x, y, i);
}

void						mandelbrot(t_env *e)
{
	int						i;
	int						j;

	i = 0;
	j = 0;
	while (j < e->s_h)
	{
		while (i < e->s_w)
		{
			e->mod = 0;
			e->t = 0;
			if (e->p == 2)
				mandelbrot_test(e, i, j);
			else
				multibrot_test(e, i, j);
			i++;
		}
		i = 0;
		j++;
	}
}
