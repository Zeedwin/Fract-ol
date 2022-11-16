/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 00:20:00 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/16 11:01:20 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	hud_flush(t_env *e)
{
	if (e->hud == 1)
	{
		(e->n_ite ? free(e->n_ite) : 0);
		(e->zoom ? free(e->zoom) : 0);
		(e->m_x ? free(e->m_x) : 0);
		(e->m_y ? free(e->m_y) : 0);
		(e->palette ? free(e->palette) : 0);
		(e->hue_a ? free(e->hue_a) : 0);
		(e->hue_b ? free(e->hue_b) : 0);
		(e->hue_c ? free(e->hue_c) : 0);
		(e->hue_s ? free(e->hue_s) : 0);
		(e->power ? free(e->power) : 0);
	}
}

static void	hud_bottom(t_env *e)
{
	e->hue_a = ft_strjoin_frs2("DOF A = ", ft_dtoa(e->dof_a, 2));
	e->hue_b = ft_strjoin_frs2("DOF B = ", ft_dtoa(e->dof_b, 2));
	e->hue_c = ft_strjoin_frs2("DOF C = ", ft_dtoa(e->dof_c, 2));
	e->hue_s = ft_strjoin_frs2("DOF S = ", ft_dtoa(e->dof_s, 2));
	if (e->mode == 8 || e->mode == 7)
	{
		mlx_string_put(e->mlx, e->win, 11, 811, 0x00000000, e->hue_a);
		mlx_string_put(e->mlx, e->win, 10, 810, 0x00FF0000, e->hue_a);
		mlx_string_put(e->mlx, e->win, 11, 831, 0x00000000, e->hue_b);
		mlx_string_put(e->mlx, e->win, 10, 830, 0x00FF0000, e->hue_b);
		mlx_string_put(e->mlx, e->win, 11, 851, 0x00000000, e->hue_c);
		mlx_string_put(e->mlx, e->win, 10, 850, 0x00FF0000, e->hue_c);
	}
	if (e->mode == 8)
	{
		mlx_string_put(e->mlx, e->win, 11, 871, 0x00000000, e->hue_s);
		mlx_string_put(e->mlx, e->win, 10, 870, 0x00FF0000, e->hue_s);
	}
}

static void	hud_top(t_env *e)
{
	e->n_ite = ft_strjoin_frs2("Iterations = ", ft_itoa(e->ite));
	mlx_string_put(e->mlx, e->win, 11, 31, 0x00000000, e->n_ite);
	mlx_string_put(e->mlx, e->win, 10, 30, 0x00FF0000, e->n_ite);
	e->zoom = ft_strjoin_frs2("Zoom = ", ft_dtoa(e->sca, 4));
	mlx_string_put(e->mlx, e->win, 11, 51, 0x00000000, e->zoom);
	mlx_string_put(e->mlx, e->win, 10, 50, 0x00FF0000, e->zoom);
	e->m_x = ft_strjoin_frs2("Mouse X = ", ft_itoa(e->mouse_x));
	e->m_x = ft_strjoin_frs1(e->m_x, " / ");
	e->m_x = ft_strjoin_free(e->m_x, \
							ft_dtoa((e->mouse_x - e->off_x) / e->sca, 3));
	mlx_string_put(e->mlx, e->win, 11, 71, 0x00000000, e->m_x);
	mlx_string_put(e->mlx, e->win, 10, 70, 0x00FF0000, e->m_x);
	e->m_y = ft_strjoin_frs2("Mouse Y = ", ft_itoa(e->mouse_y));
	e->m_y = ft_strjoin_frs1(e->m_y, " / ");
	e->m_y = ft_strjoin_free(e->m_y, \
							ft_dtoa(-(e->mouse_y - e->off_y) / e->sca, 3));
	mlx_string_put(e->mlx, e->win, 11, 91, 0x00000000, e->m_y);
	mlx_string_put(e->mlx, e->win, 10, 90, 0x00FF0000, e->m_y);
	e->palette = ft_strjoin_frs2("Palette = ", ft_itoa(e->mode));
	mlx_string_put(e->mlx, e->win, 11, 111, 0x00000000, e->palette);
	mlx_string_put(e->mlx, e->win, 10, 110, 0x00FF0000, e->palette);
	e->power = ft_strjoin_frs2("Power = ", ft_dtoa(e->p, 2));
	mlx_string_put(e->mlx, e->win, 11, 131, 0x00000000, e->power);
	mlx_string_put(e->mlx, e->win, 11, 130, 0x00FF0000, e->power);
}

void		hud(t_env *e)
{
	if (e->hud == 1)
	{
		mlx_string_put(e->mlx, e->win, 11, 11, 0x00000000, get_fractal(e));
		mlx_string_put(e->mlx, e->win, 10, 10, 0x00FF0000, get_fractal(e));
		hud_top(e);
		hud_bottom(e);
		hud_flush(e);
	}
}
