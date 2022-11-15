/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guides.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 23:22:24 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/15 23:22:27 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

void			mid_guides(t_env *e)
{
	t_ldpt		pta;
	t_ldpt		ptb;
	t_ldpt		ptc;
	t_ldpt		ptd;

	pta.r = e->s_w / 2;
	pta.i = 0;
	ptb.r = e->s_w / 2;
	ptb.i = e->s_h;
	ptc.r = 0;
	ptc.i = e->s_h / 2;
	ptd.r = e->s_w;
	ptd.i = e->s_h / 2;
	mlx_img_line(e->sce, pta, ptb, 0x0000FF00);
	mlx_img_line(e->sce, ptc, ptd, 0x0000FF00);
}
