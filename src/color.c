/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 00:20:00 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/16 11:01:01 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "fractol.h"

int		get_color(t_env *e, int x, int y)
{
	int			i;
	int			result;

	result = 0;
	if (x < e->sce->w && y < e->sce->h && x >= 0 && y >= 0)
	{
		i = ((x * (e->sce->bpp / 8)) + (y * e->sce->s_l));
		result += e->sce->img[i] & 0x000000FF;
		result += (e->sce->img[i + 1] & 0x0000FF00) << 8;
		result += (e->sce->img[i + 2] & 0x00FF0000) << 16;
		result += (e->sce->img[i + 3] & 0xFF000000) << 24;
		return (result);
	}
	return (0);
}

int		set_color(int a, int r, int g, int b)
{
	int color;

	color = 0x00000000;
	while (a > 255 || r > 255 || g > 255 || b > 255)
	{
		a = (a > 255) ? a - 255 : a;
		r = (r > 255) ? r - 255 : r;
		g = (g > 255) ? g - 255 : g;
		b = (b > 255) ? b - 255 : b;
	}
	while (a < 0 || r < 0 || g < 0 || b < 0)
	{
		a = (a < 0) ? a + 255 : a;
		r = (r < 0) ? r + 255 : r;
		g = (g < 0) ? g + 255 : g;
		b = (b < 0) ? b + 255 : b;
	}
	color = (a * 256 * 256 * 256) + (r * 256 * 256) + (g * 256) + b;
	return (color);
}

void	put_color(t_env *e, int x, int y, int i)
{
	if (e->mode >= 1 && e->mode <= 4)
		color_range_1_4(e, x, y, i);
	else if (e->mode == 5 || e->mode == 6)
		color_range_5_6(e, x, y, i);
	else if (e->mode == 7)
		color_range_7(e, x, y, i);
	else if (e->mode == 8)
		orbit_color_range(e, x, y, i);
}
