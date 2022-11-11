/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:35:06 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/10 16:03:45 by jgirard-         ###   ########.fr       */
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

void zoom_out(t_params f)
{
	t_list 
}

void zoom_in(t_params f)
{
	t_params zoom;
	
	
}