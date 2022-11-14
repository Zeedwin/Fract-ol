/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juleng <juleng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:25:17 by juleng            #+#    #+#             */
/*   Updated: 2022/11/14 10:43:22 by juleng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			render(t_params *e)
{
	if (e->fractal == 0)
		multibrot(e);
	else if (e->fractal == 2)
		juliapow(e);
	else if (e->fractal == 3)
		burning_ship(e);
	else if (e->fractal == 4)
		celtic(e);
	else if (e->fractal == 5)
		mandeldrop(e);
	else
		error("Error, Incorrect fractal parameter");
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
