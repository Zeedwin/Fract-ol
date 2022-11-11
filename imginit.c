/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imginit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:44:00 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/11 20:49:54 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int render_img(t_params	f,int y, int x)
{
	while ()
	{
		mlx_get_data_addr
	}
}

int		destroy(t_params *e, int esc)
{
	if (esc == 53)
	{
	mlx_destroy_image(e->mlx, e->img);
	mlx_destroy_window(e->mlx, e->mlx_win);
	free(e->wintitle);
	free(e->fractal);
	free(e);
	ft_putendl_fd("", 2);
	exit(EXIT_SUCCESS);
	}
	mlx_destroy_image(e->mlx, e->img);
	mlx_destroy_window(e->mlx, e->mlx_win);
	free(e->wintitle);
	free(e->fractal);
	free(e);
	ft_putendl_fd("", 2);
	exit(EXIT_SUCCESS);
	return (0);
}

void	hook_init(t_params *h)
{
	mlx_hook(h->mlx_win, ON_DESTROY, ON_RELEASE, destroy, h);
	mlx_hook(h->mlx_win, ON_KEYDOWN, ON_RELEASE, destroy, h);
	mlx_get
}
