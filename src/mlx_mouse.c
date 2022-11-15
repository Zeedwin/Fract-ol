/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 23:25:57 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/15 23:26:00 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mlx_mouse_events(int btn, int x, int y, t_env *e)
{
	e->mouse_x = x;
	e->mouse_y = y;
	(btn ? e->refresh = 1 : 0);
	(btn == 1 ? mouse_zoom_in(e, x, y) : 0);
	(btn == 2 ? mouse_zoom_out(e, x, y) : 0);
	(btn == 4 ? mouse_zoom_in(e, x, y) : 0);
	(btn == 5 ? mouse_zoom_out(e, x, y) : 0);
	return (0);
}
