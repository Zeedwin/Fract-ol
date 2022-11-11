/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:35:16 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/11 16:24:34 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "Libft/libft.h"
#include "string.h"





/*void initparams(t_params *fract)
{
	
}

void error(t_params *param)
{
	ft_putstr_fd("Right params: ./fractol M or J", 1);
}

int main (int argc, char **argv)
{
	t_params	fract;

	if (argc < 2 || strcmp(*argv, "Julia") == 0)
		error(&fract);
	
	initparams(&fract);
	parse_args(&fract, argc, argv);
	imgrend(&fract);
}
*/

int main ()
{
	printf("%s", exitprint);
	usleep(500000);
	printf("%s", exitprint2);
	usleep(500000);
	printf("%s", exitprint3);
}