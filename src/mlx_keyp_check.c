/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keyp_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 23:23:46 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/18 21:10:04 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>

int	mlx_key_press(int key, t_env *e)
{
	if (key == K_SPC && e->keys[K_SPC])
		e->keys[K_SPC] = 0;
	else if (key == K_SPC)
		e->keys[K_SPC] = 1;
	else
		e->keys[key] = 1;
	return (0);
}
