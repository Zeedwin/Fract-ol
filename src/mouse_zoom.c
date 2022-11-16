/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_zoom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 23:26:04 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/16 14:58:00 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fractol.h"

void	mouse_zoom_in(t_env *e, int m_x, int m_y)
{
	e->off_x = m_x - (m_x - e->off_x) * 1.1;
	e->off_y = m_y - (m_y - e->off_y) * 1.1;
	e->sca *= 1.1;
}

void	mouse_zoom_out(t_env *e, int m_x, int m_y)
{
	e->off_x = m_x - (m_x - e->off_x) / 1.1;
	e->off_y = m_y - (m_y - e->off_y) / 1.1;
	e->sca /= 1.1;
}
