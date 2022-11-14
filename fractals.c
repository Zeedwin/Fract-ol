/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juleng <juleng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:35:06 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/14 10:52:50 by juleng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_dim_map(t_params *f)
{
	f->x = f->x_x / (WIDTH / (f->e_x - f->s_x)) + f->s_x;
	f->y = f->y_y / (HIGHT / (f->e_y - f->s_y)) + f->s_y;
	f->x_o = f->x;
	f->y_o = f->y;
}

void mandelbrot(t_params *f)
{
	t_params	*mb;
	
	set_dim_map(f);
	while (mb->index <= MAX_ITERI)
	{
		mlx_clear_window(mb->mlx, mb->mlx_win);
		mb->xtmp = mb->x * mb->x - mb->y * mb->y;
		mb->ytmp = 2 * mb->x * mb->y;
		mb->x = mb->xtmp + mb->x_o;
		mb->y = mb->ytmp + mb->y_o;
		if (mb->x * mb->x + mb->y * mb->y > 4)
			break ;
		mb->index++;
	}
}

void	mouse_zoom_in(t_params *f, int m_x, int m_y)
{
	f->x_o = m_x - (m_x - f->x_o) * 1.1;
	f->y_o = m_y - (m_y - f->y_o) * 1.1;
	f->scale *= 1.1;
}

void	mouse_zoom_out(t_params *f, int m_x, int m_y)
{
	f->x_o = m_x - (m_x - f->x_o) / 1.1;
	f->y_o = m_y - (m_y - f->y_o) / 1.1;
	f->scale /= 1.1;
}
