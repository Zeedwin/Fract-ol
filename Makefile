# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 22:55:17 by jgirard-          #+#    #+#              #
#    Updated: 2022/11/17 19:04:44 by jgirard-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = 					fractol

CC = 					clang
CFLAGS +=				-Wall -Wextra -Werror -fsanitize=address
OFLAGS := 				-O3
RM := 					rm -rf

INC = 					$(addprefix $(INC_PATH)/,$(INC_NAMES))
INC_PATH =				./includes

LIBFT :=				$(LIBFT_PATH)/libft.a
LIBFT_PATH :=			./libft
LIBFT_INC_PATH :=		./libft

LIBMATHFLAGS :=			-lm

INC_NAMES = 			fractol.h \
						mac_keys.h
MLXFLAGS =				-framework OpenGL -framework AppKit
KEYS =					-DMAC_KEYS
OS_NAME =				"OpenGL"
MLX_PATH =				./minilibx_opengl_20191021

MLX =					$(MLX_PATH)/libmlx.a


OBJ =					$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OBJ_PATH =				./obj
OBJ_NAME =				$(SRC_NAME:.c=.o)

SRC =					$(addprefix $(SRC_PATH)/,$(SRC_NAME))
SRC_PATH =				./src
SRC_NAME =  			burning_ship.c \
						color.c \
						fractal_color_init.c \
						guides.c \
						init.c \
						julia.c \
						mlx_main_loop.c \
						mlx_image_draw.c \
						mlx_key_press.c \
						mlx_key_release.c \
						mlx_key_repeated.c \
						mlx_mouse.c \
						mandelbrot.c \
					    ft_render.c \
						tools.c \
						main.c \
						utils.c \
						utils2.c \
						zoom_in_out.c
						
all: $(NAME)

$(NAME): libft mlx $(SRC) $(INC) $(OBJ_PATH) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -L$(LIBFT_PATH) $(LIBFTFLAGS) $(MLX) $(MLXFLAGS) $(LIBMATHFLAGS) $(GPU_L)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INCLUDES_PATH) $(INC)
	$(CC) $(CFLAGS) $(OFLAGS) -c $< -o $@ -I $(INC_PATH) -I $(LIBFT_INC_PATH) -I $(MLX_PATH) $(GPU_MACRO) $(KEYS) $(DEBUG_MACRO)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

CPU: all
cpu: CPU

GPU: gpu_flags all
gpu: GPU
gpu_flags:
	$(eval GPU_L = -framework OpenCL)
	$(eval GPU_MACRO = -DGPU)

debug: clean debug_flag
debug_flag:
	$(eval DEBUG_MACRO = -DDEBUG -g)

clean:
	@rm -rf $(OBJ_PATH)

fclean: fcleanlibft clean 
	@rm -rf $(NAME) ./config

libft:
	make -C $(LIBFT_PATH)/ all

cleanlibft:
	make -C $(LIBFT_PATH)/ clean

fcleanlibft: cleanlibft
	make -C $(LIBFT_PATH)/ fclean

mlx:
	make -C $(MLX_PATH)/ all

re: fclean all