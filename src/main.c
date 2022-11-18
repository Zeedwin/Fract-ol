/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 23:23:18 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/18 21:12:34 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	fractal_select(char *av)
{
	if (ft_strncmp("mandelbrot", av, 11) == 0 || ft_strncmp("m", av, 2) == 0)
		return (0);
	else if (ft_strncmp("julia", av, 6) == 0 || ft_strncmp("j", av, 2) == 0)
		return (2);
	else if (ft_strncmp("burningship", av, 12) == 0
		|| ft_strncmp("b", av, 2) == 0)
		return (3);
	else
		return (-1);
}

void	set_hooks(t_env *e)
{
	mlx_hook(e->win, DESTROYNOTIFY, 1L << 1, quit, e);
	mlx_hook(e->win, KEYPRESS, 1, mlx_key_press, e);
	mlx_hook(e->win, KEYRELEASE, 2, mlx_key_release, e);
	mlx_mouse_hook(e->win, mlx_mouse_events, e);
	mlx_loop_hook(e->mlx, mlx_main_loop, e);
	mlx_loop(e->mlx);
}

static void	launch(t_env **e, char **av, int i)
{
	e[i] = calloc(1, sizeof(t_env));
	e[i]->select = fractal_select(av[i]);
	if (e[i]->select == -1)
	{
		usage();
		error("\x1b[2;31mBad param error\x1b[0m");
	}
	init(e[i]);
	set_hooks(e[i]);
	ft_render(e[i]);
}

static void	fork_launch(int ac, char **av)
{
	pid_t		*childs;
	char		*arg[3];
	int			i;

	i = 1;
	childs = malloc((ac - 1) * (sizeof(pid_t)));
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

int	main(int ac, char **av)
{
	t_env		**e;

	e = calloc(ac, sizeof(t_env));
	if (ac < 2 || ac > 7)
	{
		usage();
	}
	if (ac > 2)
		fork_launch(ac, av);
	else
		launch(e, av, 1);
	return (0);
}
