/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_release.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 23:23:55 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/17 19:26:06 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mlx_key_release(int key, t_env *e)
{
	//if (key < sizeof(e->keys))
		e->keys[key] = 0;
	return (0);
}
