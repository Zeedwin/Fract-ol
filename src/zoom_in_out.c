/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_in_out.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 23:26:04 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/18 19:53:08 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mouse_zoom_in(t_env *e, int m_x, int m_y)
{
	e->mouse_x = m_x - (m_x - e->mouse_x) * 1.1;
	e->mouse_y = m_y - (m_y - e->mouse_y) * 1.1;
	e->o_x = m_x - (m_x - e->o_x) * 1.1;
	e->o_y = m_y - (m_y - e->o_y) * 1.1;
	e->sca *= 1.1;
}

void	mouse_zoom_out(t_env *e, int m_x, int m_y)
{
	e->mouse_x = m_x - (m_x - e->mouse_x) / 1.1;
	e->mouse_y = m_y - (m_y - e->mouse_y) / 1.1;
	e->o_x = m_x - (m_x - e->o_x) / 1.1;
	e->o_y = m_y - (m_y - e->o_y) / 1.1;
	e->sca /= 1.1;
}
