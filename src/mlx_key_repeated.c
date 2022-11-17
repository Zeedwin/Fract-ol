/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_repeated.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:34:10 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/17 19:25:04 by jgirard-         ###   ########.fr       */
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

void	mlx_keyboard_repeated(t_env *e)
{
	if (!e)
		exit(EXIT_FAILURE);
	mlx_key_3(e);
}
