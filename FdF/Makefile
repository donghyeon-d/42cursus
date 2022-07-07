CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
MLXFLAGS = -L ./minilibx_mms_20210621/ -lmlx -framework OpenGL -framework AppKit
# MLXFLAGS = -L ./minilibx -lmlx -framework OpenGL -framework AppKit
MLXLIB = libmlx.dylib
MLXLIB_DIR = ./minilibx_mms_20210621/
NAME = fdf
NAME_BONUS = fdf_bonus
SRC = fdf.c draw.c keypress.c parse.c rotate.c
SRC_BONUS = fdf_bonus.c draw_bonus.c handle_bonus.c init_bonus.c \
keypress_bonus.c map_adjust_bonus.c \
map_offset_bonus.c map_parse_bonus.c map_rotate_bonus.c map_zoom_bonus.c \
map_edge.c color_bonus.c map_altitude_bonus.c
SRC_OBJECT = $(SRC:.c=.o)
SRC_OBJECT_BONUS = $(SRC_BONUS:.c=.o)
HEADER_DIR = .
LIBFT = libft.a
LIBFT_DIR = ./ft_libft/
GNL = get_next_line.a
GNL_DIR = ./get_next_line/

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(HEADER_DIR)

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME) : $(SRC_OBJECT) $(GNL) $(LIBFT) $(MLXLIB)
	$(CC) $(CFLAGS) $(MLXFLAGS) -o $@ $^

$(NAME_BONUS) : $(SRC_OBJECT_BONUS) $(GNL) $(LIBFT)
	$(CC) $(CFLAGS) $(MLXFLAGS) -o $@ $^

$(LIBFT) :
	make -C $(LIBFT_DIR) bonus
	cp $(LIBFT_DIR)$(LIBFT) .

$(GNL) :
	make -C $(GNL_DIR) all
	cp $(GNL_DIR)$(GNL) .

$(MLXLIB) :
	make -C $(MLXLIB_DIR) all
	cp $(MLXLIB_DIR)$(MLXLIB) .

clean :
	rm -rf $(SRC_OBJECT) $(SRC_OBJECT_BONUS) $(GNL) $(LIBFT)
	make -C $(LIBFT_DIR) clean
	make -C $(GNL_DIR) clean
	make -C $(MLXLIB_DIR) clean

fclean : clean
	rm -rf $(NAME) $(NAME_BONUS)
	make -C $(LIBFT_DIR) fclean
	make -C $(GNL_DIR) fclean
	rm -rf $(MLXLIB)

re : fclean all

.PHONY : all clean fclean re bonus