/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:34:10 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/17 16:22:33 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/libft.h"

int	usage(void)
{
	ft_putendl("\x1b[1;32mInput:\x1b[0m ./fractol \x1b[1;32m[fractal]\x1b[0m");
	ft_putendl("\x1b[1;32mFractals:\x1b[0m");
	ft_putendl("mandelbrot");
	ft_putendl("julia");
	ft_putendl("burningship");
	ft_putendl("\x1b[1;32mInput a space to launch multiple fractals at once");
	exit(EXIT_FAILURE);
}

void	error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

int	quit(t_env *e)
{
	mlx_destroy_image(e->mlx, e->sce->p_img);
	mlx_destroy_window(e->mlx, e->win);
	free(e->title);
	free(e->fractal);
	free(e);
	ft_putendl_fd("Exiting", 2);
	exit(EXIT_SUCCESS);
	return (0);
}

char	*get_fractal(t_env *e)
{
	if (e->select == 0)
		return ("Mandelbrot");
	else if (e->select == 2)
		return ("Julia");
	else if (e->select == 3)
		return ("Burning Ship");
	else
		return ("ERROR");
}
