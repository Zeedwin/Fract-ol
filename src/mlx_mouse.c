/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 23:25:57 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/17 16:41:30 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mlx_mouse_events(int btn, int x, int y, t_env *e)
{
	e->mouse_x = x;
	e->mouse_y = y;
	if (btn)
	{
		e->refresh = 1;
	}
	if (btn == 1 || btn == 4)
	{
		mouse_zoom_in(e, x, y);
	}
	if (btn == 2 || btn == 5)
	{
		mouse_zoom_out(e, x, y);
	}
	return (0);
}
