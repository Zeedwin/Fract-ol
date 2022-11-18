/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 23:25:49 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/18 16:12:59 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mlx_main_loop(t_env *e)
{
	if (e)
	{
		mlx_keyboard_repeated(e);
		mlx_mouse_get_pos(e->win, &e->mouse_x, &e->mouse_y);
		refresh(e);
	}
	return (0);
}
