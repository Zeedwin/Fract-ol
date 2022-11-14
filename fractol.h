#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include "Libft/libft.h"
# define  MAX_ITERI 60
# define  HIGHT 600
# define  WIDTH 600
# define  ON_KEYDOWN 2
# define  ON_KEYUP 3
# define  ON_MOUSEUP 4
# define  ON_MOUSEDOWN 5
# define  ON_MOUSEMOVE 6
# define  ON_EXPOSE 12
# define  ON_DESTROY 17
# define  ON_RELEASE 1L<<0


typedef struct i_img 
{
	
};



typedef struct s_params {
void		*mlx;
void		*mlx_win;
void 		*img;
char		*fractal;
char		*wintitle;
double		x_x;
double		y_y;
double		z;
double		xtmp;
double		ytmp;
double		y_o;
double		x_o;
double		stop;
double		y;
double		x;
double		xx;
double		yy;
double		s_x;
double		s_y;
double		e_x;
double		e_y;
int			color;
int			zoom;
int 		index;
double		scale;
}				t_params; 

void mandelbrot(t_params *f);
int julia(double	zr, double zi);

char *exitprint =	"\033[91m     ##### ##                                                                        \n" \
					"  ######  /### /              #              #                                       \n" \
					" /#   /  / ###/              ###     #      ###                                      \n" \
					"/    /  /   ##                #     ##       #                                       \n" \
					"    /  /                            ##                                               \n" \
					"   ## ##        /##    ###  ###   ######## ###   ###  /###     /###                  \n" \
					"   ## ##       / ###  #### / ### ########   ###   ###/ #### / /  ###  /              \n" \
					"   ## ######      ### /###/   ##    ##       ##    ##   ###/ /    ###/               \n" \
					"   ## #####        ##/  ##    ##    ##       ##    ##    ## ##     ##                \n" \
					"   ## ##            /##       ##    ##       ##    ##    ## ##     ##                \n" \
					"   #  ##           / ###      ##    ##       ##    ##    ## ##     ##                \n" \
					"      /           /   ###     ##    ##       ##    ##    ## ##     ##                \n" \
					"  /##/         / /     ###    ##    ##       ##    ##    ## ##     ##   #    		  \n" \
					" /  ##########/ /       ### / ### / ##       ### / ###   ### ########  ###  		  \n" \
					"/     ######   /         ##/   ##/   ##       ##/   ###   ###  ### ###  #    		  \n" \
					"#                                                                   ###              \n" \
					" ##                                                           ####   ###             \n" \
					"                                                           /######  /#               \n" \
					"                                                          /     ###/                 \n";

char *exitprint2 =	"     ##### ##                                                                        \n" \
					"  ######  /### /              #              #                                       \n" \
					" /#   /  / ###/              ###     #      ###                                      \n" \
					"/    /  /   ##                #     ##       #                                       \n" \
					"    /  /                            ##                                               \n" \
					"   ## ##        /##    ###  ###   ######## ###   ###  /###     /###                  \n" \
					"   ## ##       / ###  #### / ### ########   ###   ###/ #### / /  ###  /              \n" \
					"   ## ######      ### /###/   ##    ##       ##    ##   ###/ /    ###/               \n" \
					"   ## #####        ##/  ##    ##    ##       ##    ##    ## ##     ##                \n" \
					"   ## ##            /##       ##    ##       ##    ##    ## ##     ##                \n" \
					"   #  ##           / ###      ##    ##       ##    ##    ## ##     ##                \n" \
					"      /           /   ###     ##    ##       ##    ##    ## ##     ##                \n" \
					"  /##/         / /     ###    ##    ##       ##    ##    ## ##     ##   #    #    	  \n" \
					" /  ##########/ /       ### / ### / ##       ### / ###   ### ########  ###  ###  	  \n" \
					"/     ######   /         ##/   ##/   ##       ##/   ###   ###  ### ###  #    #    	  \n" \
					"#                                                                   ###              \n" \
					" ##                                                           ####   ###             \n" \
					"                                                           /######  /#               \n" \
					"                                                          /     ###/                 \n";

char *exitprint3 =	"     ##### ##                                                                        \n" \
					"  ######  /### /              #              #                                       \n" \
					" /#   /  / ###/              ###     #      ###                                      \n" \
					"/    /  /   ##                #     ##       #                                       \n" \
					"    /  /                            ##                                               \n" \
					"   ## ##        /##    ###  ###   ######## ###   ###  /###     /###                  \n" \
					"   ## ##       / ###  #### / ### ########   ###   ###/ #### / /  ###  /              \n" \
					"   ## ######      ### /###/   ##    ##       ##    ##   ###/ /    ###/               \n" \
					"   ## #####        ##/  ##    ##    ##       ##    ##    ## ##     ##                \n" \
					"   ## ##            /##       ##    ##       ##    ##    ## ##     ##                \n" \
					"   #  ##           / ###      ##    ##       ##    ##    ## ##     ##                \n" \
					"      /           /   ###     ##    ##       ##    ##    ## ##     ##                \n" \
					"  /##/         / /     ###    ##    ##       ##    ##    ## ##     ##   #    #    #  \n" \
					" /  ##########/ /       ### / ### / ##       ### / ###   ### ########  ###  ###  ### \n" \
					"/     ######   /         ##/   ##/   ##       ##/   ###   ###  ### ###  #    #    #  \n" \
					"#                                                                   ###              \n" \
					" ##                                                           ####   ###             \n" \
					"                                                           /######  /#               \n" \
					"                                                          /     ###/                 \n\033[0m";

#endif