/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:24:06 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/16 11:08:05 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			render(t_env *e)
{
	if (e->select == 0)
		multibrot(e);
	else if (e->select == 2)
		juliapow(e);
	else if (e->select == 3)
		burning_ship(e);
	else if
		error("\x1b[2;31mUnknown fractal parameter given, exiting :/\x1b[0m");
	(e->guides > 0 ? mid_guides(e) : 0);
}

void			refresh(t_env *e)
{
	ft_bzero(e->sce->img, (e->m_w * e->m_h));
	if (e->refresh == 1 || e->select == 2)
	{
		render(e);
		e->refresh = 0;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->sce->p_img, e->s_x, e->s_y);
	hud(e);
}
