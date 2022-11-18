/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:01:23 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/18 19:11:11 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_render(t_env *e)
{
	if (e->select == 0)
		mandelbrot(e);
	else if (e->select == 2)
		julia(e);
	else if (e->select == 3)
		burning_ship(e);
	else
		error("\x1b[2;31mBad Fractal params\x1b[0m");
}

void	refresh(t_env *e)
{
	ft_bzero(e->sce->img, (e->m_w * e->m_h));
	if (e->refresh == 1 || e->select == 2)
	{
		ft_render(e);
		e->refresh = 0;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->sce->p_img, e->s_x, e->s_y);
}

int	mlx_img_pix_put(t_img *sce, int x, int y, int color)
{
	int			i;

	if (x < sce->w && y < sce->h && x >= 0 && y >= 0)
	{
		i = ((x * (sce->bpp / 8)) + (y * sce->s_l));
		if (sce->endian == 0)
		{
			sce->img[i] = (color & 0x000000FF);
			sce->img[i + 1] = (color & 0x0000FF00) >> 8;
			sce->img[i + 2] = (color & 0x00FF0000) >> 16;
			sce->img[i + 3] = (color & 0xFF000000) >> 24;
		}
		else
		{
			sce->img[i] = (color & 0x000000FF) >> 24;
			sce->img[i + 1] = (color & 0x0000FF00) >> 16;
			sce->img[i + 2] = (color & 0x00FF0000) >> 8;
			sce->img[i + 3] = (color & 0xFF000000);
		}
	}
	return (0);
}
