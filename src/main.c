/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 23:23:18 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/15 23:23:22 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		fractal_select(char *av)
{
	if (ft_strcmp("mandelbrot", av) == 0)
		return (0);
	else if (ft_strcmp("tricorn", av) == 0)
		return (1);
	else if (ft_strcmp("julia", av) == 0)
		return (2);
	else if (ft_strcmp("burningship", av) == 0)
		return (3);
	else if (ft_strcmp("celtic", av) == 0)
		return (4);
	else if (ft_strcmp("mandeldrop", av) == 0)
		return (5);
	else if (ft_strcmp("test", av) == 0)
		return (9);
	else
		return (-1);
}

void			set_hooks(t_env *e)
{
	mlx_hook(e->win, DESTROYNOTIFY, KEYRELEASEMASK, quit, e);
	mlx_hook(e->win, KEYPRESS, KEYPRESSMASK, mlx_key_press, e);
	mlx_hook(e->win, KEYRELEASE, KEYRELEASEMASK, mlx_key_release, e);
	mlx_mouse_hook(e->win, mlx_mouse_events, e);
	mlx_loop_hook(e->mlx, mlx_main_loop, e);
	mlx_loop(e->mlx);
}

static void		launch(t_env **e, char **av, int i)
{
	if (!(e[i] = malloc(sizeof(t_env))))
		error("\x1b[2;31mCan't initialize Fractol environment\x1b[0m");
	e[i]->select = fractal_select(av[i]);
	if (e[i]->select == -1)
	{
		usage();
		error("\x1b[2;31mBad param error\x1b[0m");
	}
	init(e[i]);
	set_hooks(e[i]);
	render(e[i]);
}

static void		fork_launch(int ac, char **av)
{
	pid_t		*childs;
	char		*arg[3];
	int			i;

	i = 1;
	if (!(childs = malloc((ac - 1) * (sizeof(pid_t)))))
		error("\x1b[2;31mCan't allocate PIDS array\x1b[0m");
	while (i < ac)
	{
		arg[0] = "./fractol";
		arg[1] = av[i];
		arg[2] = NULL;
		childs[i] = fork();
		if (childs[i] == 0)
			execv("./fractol", arg);
		i++;
	}
	while (i < ac)
	{
		wait(childs + i);
		i++;
	}
}

int				main(int ac, char **av)
{
	t_env		**e;

	if (!(e = malloc(sizeof(t_env) * ac)))
		error("\x1b[2;31mCan't initialize Fractol environment array\x1b[0m");
	(ac < 2 || ac > 7 ? usage() : 0);
	if (ac > 2)
		fork_launch(ac, av);
	else
		launch(e, av, 1);
	return (0);
}
