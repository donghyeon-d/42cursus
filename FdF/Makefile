CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L ./minilibx -lmlx -framework OpenGL -framework AppKit
NAME = fdf
NAME_BONUS = fdf_bonus
SRC = fdf.c draw.c keypress.c parse.c rotate.c
SRC_BONUS = fdf_bonus.c draw_bonus.c keypress_bonus.c parse_bonus.c rotate_bonus.c
SRC_OBJECT = $(SRC:.c=.o)
SRC_OBJECT_BONUS = $(SRC_BONUS:.c=.o)
HEADER_DIR = .
LIBFT = libft.a
LIBFT_DIR = ./ft_libft/
GNL = get_next_line.a
GNL_DIR = ./get_next_line/

%.o : %.c
	$(CC) $(CFLAGS) -g3 -fsanitize=address -c $< -o $(<:.c=.o) -I $(HEADER_DIR)

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME) : $(SRC_OBJECT) $(GNL) $(LIBFT)
	$(CC) $(CFLAGS) $(MLXFLAGS) -o $@ $^

$(NAME_BONUS) : $(SRC_OBJECT_BONUS) $(GNL) $(LIBFT)
	$(CC) $(CFLAGS) -g3 -fsanitize=address $(MLXFLAGS) -o $@ $^

$(LIBFT) :
	make -C $(LIBFT_DIR) bonus
	cp $(LIBFT_DIR)$(LIBFT) .

$(GNL) :
	make -C $(GNL_DIR) all
	cp $(GNL_DIR)$(GNL) .

clean :
	rm -rf $(SRC_OBJECT) $(SRC_OBJECT_BONUS) $(GNL) $(LIBFT)
	make -C $(LIBFT_DIR) clean
	make -C $(GNL_DIR) clean

fclean : clean
	rm -rf $(NAME) $(NAME_BONUS)
	make -C $(LIBFT_DIR) fclean
	make -C $(GNL_DIR) fclean

re : fclean all

.PHONY : all clean fclean re bonus