/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_repeated.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 23:25:41 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/15 23:25:43 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		mlx_key_3(t_env *e)
{
	(KP_N0 ? e->select = 0 : 0);
	(KP_N1 ? e->select = 1 : 0);
	(KP_N2 ? e->select = 2 : 0);
	(KP_N3 ? e->select = 3 : 0);
	(KP_N4 ? e->select = 4 : 0);
	(KP_N5 ? e->select = 5 : 0);
	if (KP_R)
	{
		e->sca = 400;
		e->off_x = (float)e->cen_x;
		e->off_y = (float)e->cen_y;
	}
	if (KP_T)
	{
		e->dof_a = 1;
		e->dof_b = 2;
		e->dof_c = 3;
	}
}

static void		mlx_key_2(t_env *e)
{
	(KP_UA ? e->off_y += 5 : 0);
	(KP_DA ? e->off_y -= 5 : 0);
	(KP_LA ? e->off_x += 5 : 0);
	(KP_RA ? e->off_x -= 5 : 0);
	(KP_NPLU ? e->sca *= 1.1 : 0);
	(KP_NMIN && e->sca > 1 ? e->sca /= 1.1 : 0);
	(KP_HOME ? e->ite-- : 0);
	(KP_PGU ? e->ite++ : 0);
	(KP_F13 ? e->dof_a += 0.1 : 0);
	(KP_DEL ? e->dof_a -= 0.1 : 0);
	(KP_F14 ? e->dof_b += 0.1 : 0);
	(KP_END ? e->dof_b -= 0.1 : 0);
	(KP_F15 ? e->dof_c += 0.1 : 0);
	(KP_PGD ? e->dof_c -= 0.1 : 0);
	(KP_F16 ? e->dof_s -= 0.1 : 0);
	(KP_F17 ? e->dof_s += 0.1 : 0);
	(KP_NSLA && e->p > 0.1 ? e->p -= 0.1 : 0);
	(KP_NSTR ? e->p += 0.1 : 0);
}

static void		mlx_key_1(t_env *e)
{
	(KP_1 ? e->mode = 1 : 0);
	(KP_2 ? e->mode = 2 : 0);
	(KP_3 ? e->mode = 3 : 0);
	(KP_4 ? e->mode = 4 : 0);
	(KP_5 ? e->mode = 5 : 0);
	(KP_6 ? e->mode = 6 : 0);
	(KP_7 ? e->mode = 7 : 0);
	(KP_8 ? e->mode = 8 : 0);
	(KP_ESC ? quit(e) : 0);
	(KP_Q ? quit(e) : 0);
}

void			mlx_keyboard_repeated(t_env *e)
{
	if (!e)
		exit(EXIT_FAILURE);
	mlx_key_1(e);
	mlx_key_2(e);
	mlx_key_3(e);
}
