/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_parsed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:34:10 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/18 16:38:19 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	mlx_key_3(t_env *e)
{
	if (e->keys[K_R])
	{
		e->sca = 400;
		e->o_x = (float)e->cen_x;
		e->o_y = (float)e->cen_y;
	}
	if (e->keys[K_ESC])
	{
		quit(e);
	}
	if (e->keys[K_1])
	{
		e->mode = 1;
	}
	if (e->keys[K_2])
	{
		e->mode = 2;
	}
}

static void	mlx_key_1(t_env *e)
{
	if (e->keys[K_3])
	{
		e->mode = 3;
	}
	if (e->keys[K_4])
	{
		e->mode = 4;
	}
	if (e->keys[K_5])
	{
		e->mode = 5;
	}
	if (e->keys[K_6])
	{
		e->mode = 6;
	}
}

static void	mlx_key_2(t_env *e)
{
	if (e->keys[K_7])
	{
		e->mode = 7;
	}
	if (e->keys[K_8])
	{
		e->mode = 8;
	}
	if (e->keys[K_NPLU])
	{
		e->ite += 10;
	}
	if (e->keys[K_NMIN])
	{
		e->ite -= 10;
	}
}

void	mlx_keyboard_repeated(t_env *e)
{
	if (!e)
		exit(EXIT_FAILURE);
	mlx_key_1(e);
	mlx_key_2(e);
	mlx_key_3(e);
}
