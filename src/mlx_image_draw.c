/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:34:10 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/16 15:44:27 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/libft.h"

int				mlx_img_pix_put(t_img *sce, int x, int y, int color)
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

void			mlx_img_line_hor(t_img *sce, t_ldpt p1, t_ldpt p2, int c)
{
	int			i;
	int			accum;
	t_ldpt		p;

	i = 1;
	p.r = p1.r;
	p.i = p1.i;
	mlx_img_pix_put(sce, p.r, p.i, c);
	accum = ft_abs(p2.r - p1.r) / 2;
	while (i <= ft_abs(p2.r - p1.r))
	{
		i++;
		p.r += ((p2.r - p1.r) > 0) ? 1 : -1;
		accum += ft_abs(p2.i - p1.i);
		if (accum >= ft_abs(p2.r - p1.r))
		{
			accum -= ft_abs(p2.r - p1.r);
			p.i += ((p2.i - p1.i) > 0) ? 1 : -1;
		}
		mlx_img_pix_put(sce, p.r, p.i, c);
	}
}

void			mlx_img_line_ver(t_img *sce, t_ldpt p1, t_ldpt p2, int c)
{
	int			i;
	int			accum;
	t_ldpt		p;

	i = 1;
	p.r = p1.r;
	p.i = p1.i;
	mlx_img_pix_put(sce, p.r, p.i, c);
	accum = ft_abs(p2.i - p1.i) / 2;
	while (i <= ft_abs(p2.i - p1.i))
	{
		i++;
		p.i += ((p2.i - p1.i) > 0) ? 1 : -1;
		accum += ft_abs(p2.r - p1.r);
		if (accum >= ft_abs(p2.i - p1.i))
		{
			accum -= ft_abs(p2.i - p1.i);
			p.r += ((p2.r - p1.r) > 0) ? 1 : -1;
		}
		mlx_img_pix_put(sce, p.r, p.i, c);
	}
}

void			mlx_img_line(t_img *sce, t_ldpt p1, t_ldpt p2, int c)
{
	if (ft_abs(p2.r - p1.r) > ft_abs(p2.i - p1.i))
		mlx_img_line_hor(sce, p1, p2, c);
	else
		mlx_img_line_ver(sce, p1, p2, c);
}
