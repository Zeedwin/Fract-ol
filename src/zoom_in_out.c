/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_in_out.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 23:26:04 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/17 16:24:29 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mouse_zoom_in(t_env *e, int m_x, int m_y)
{
	e->o_x = m_x - (m_x - e->o_x) * 1.1;
	e->o_y = m_y - (m_y - e->o_y) * 1.1;
	e->sca *= 1.1;
}

void	mouse_zoom_out(t_env *e, int m_x, int m_y)
{
	e->o_x = m_x - (m_x - e->o_x) / 1.1;
	e->o_y = m_y - (m_y - e->o_y) / 1.1;
	e->sca /= 1.1;
}
