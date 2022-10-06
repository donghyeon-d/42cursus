CC = cc
CFLAGS = -g
MLXLIB_DIR = ./minilibx_mms_20210621/
MLXFLAGS = -L $(MLXLIB_DIR) -lmlx -framework OpenGL -framework AppKit
MLXLIB = libmlx.dylib
NAME = cub3d
# NAME_BONUS = cub3d_bonus
# SRC = c.c key.c
SRC = cub3d.c color.c draw.c init.c key.c wall_dist.c wall_height.c
# SRC_BONUS = check_filename_bonus.c color_bonus.c draw_bonus.c fdf_bonus.c \
init_bonus.c keypress_bonus.c keypress_utils_bonus.c map_adjust_bonus.c \
map_altitude_bonus.c map_find_minmax_bonus.c map_offset_bonus.c \
map_parse_bonus.c map_rotate_bonus.c map_zoom_bonus.c string_bonus.c
SRC_OBJECT = $(SRC:.c=.o)
# BONUS_OBJECT = $(SRC_BONUS:.c=.o)
HEADER_DIR = .
LIBFT = libft.a
LIBFT_DIR = ./ft_libft/
GNL = get_next_line.a
GNL_DIR = ./get_next_line/

# ifdef WITH_BONUS
# OFILES = $(BONUS_OBJECT)
# else
OFILES = $(SRC_OBJECT)
# endif

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(HEADER_DIR)

all : $(NAME)

# bonus : 
# make WITH_BONUS=1 all

$(NAME) : $(OFILES) $(MLXLIB)
	$(CC) $(CFLAGS) $(MLXFLAGS) -o $@ $^

fsan : $(OFILES) $(MLXLIB)
	$(CC) $(CFLAGS) $(MLXFLAGS) -o fsan $^ -g3 -fsanitize=address

ldb : $(OFILES) $(MLXLIB)
	$(CC) $(CFLAGS) $(MLXFLAGS) -o ldb $^ -g
# $(NAME_BONUS) : $(OFILES) $(GNL) $(LIBFT) $(MLXLIB)
# 	$(CC) $(CFLAGS) $(MLXFLAGS) -o $@ $^

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
	rm -rf $(SRC_OBJECT) $(BONUS_OBJECT) $(GNL) $(LIBFT) $(MLXLIB)
	make -C $(MLXLIB_DIR) clean
	make -C $(LIBFT_DIR) fclean
	make -C $(GNL_DIR) fclean

fclean : clean
	rm -rf $(NAME) $(NAME)

re : 
	make fclean
	make all

.PHONY : all clean fclean re