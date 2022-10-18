# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 14:13:52 by jaewchoi          #+#    #+#              #
#    Updated: 2022/10/17 11:33:08 by dongchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXLIB_DIR = ./minilibx_mms_20210621/
MLXFLAGS = -L $(MLXLIB_DIR) -lmlx -framework OpenGL -framework AppKit
MLXLIB = libmlx.dylib
NAME = cub3D
NAME_BONUS = cub3D_bonus
SRC = $(addprefix ./src/, \
	cub3d.c \
	error_exit.c \
	file_check_type.c \
	file_check.c \
	ft_malloc.c \
	get_map_color.c \
	get_map_info.c \
	get_map_texture.c \
	get_map.c \
	get_next_line.c \
	get_player.c \
	map_valid_check.c \
	parse.c \
	draw_line.c \
	ft_raycasting.c \
	init_images.c \
	init_ray.c \
	start_dda.c \
	take_wall_point.c \
	ft_key_press.c \
	ft_close_win.c \
	ft_key_move.c \
	ft_mouse_ctl.c \
	ft_mouse_loop.c \
	ft_minimap.c \
	create_door.c \
	ft_door_control.c \
	ft_door_new.c \
	get_draw_texture.c \
	get_texture_point_x.c \
	ft_key_rotate.c)
SRC_OBJECT = $(SRC:.c=.o)
BONUS = $(addprefix ./src_bonus/, \
	cub3d_bonus.c \
	error_exit_bonus.c \
	file_check_type_bonus.c \
	file_check_bonus.c \
	ft_malloc_bonus.c \
	get_map_color_bonus.c \
	get_map_info_bonus.c \
	get_map_texture_bonus.c \
	get_map_bonus.c \
	get_next_line_bonus.c \
	get_player_bonus.c \
	map_valid_check_bonus.c \
	parse_bonus.c \
	draw_line_bonus.c \
	ft_raycasting_bonus.c \
	init_images_bonus.c \
	init_ray_bonus.c \
	start_dda_bonus.c \
	take_wall_point_bonus.c \
	ft_key_press_bonus.c \
	ft_close_win_bonus.c \
	ft_key_move_bonus.c \
	ft_mouse_ctl_bonus.c \
	ft_mouse_loop_bonus.c \
	ft_minimap_bonus.c \
	create_door_bonus.c \
	ft_door_control_bonus.c \
	ft_door_new_bonus.c \
	get_draw_texture_bonus.c \
	get_texture_point_x_bonus.c \
	ft_key_rotate_bonus.c)
BONUS_OBJECT = $(BONUS:.c=.o)
HEADER_DIR = ./include/
LIBFT = libft.a
LIBFT_DIR = ./libft/
OFILES = $(SRC_OBJECT)
OFILES_BONUS = $(BONUS_OBJECT)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(HEADER_DIR)

$(NAME) : $(OFILES) $(MLXLIB) $(LIBFT)
	$(CC) $(CFLAGS) $(MLXFLAGS) -o $@ $^ $(LIBFT) $(MLXLIB)

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR) bonus
	cp $(LIBFT_DIR)$(LIBFT) .

$(MLXLIB) :
	$(MAKE) -C $(MLXLIB_DIR) all
	cp $(MLXLIB_DIR)$(MLXLIB) .

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OFILES_BONUS) $(MLXLIB) $(LIBFT)
	$(CC) $(CFLAGS) $(MLXFLAGS) -o $@ $^ $(LIBFT) $(MLXLIB)

clean :
	$(RM) $(SRC_OBJECT) $(BONUS_OBJECT) $(GNL) $(LIBFT) $(MLXLIB)
	$(MAKE) -C $(MLXLIB_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) fclean

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS)

re : 
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re bonus