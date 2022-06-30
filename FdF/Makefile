CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L ./minilibx -lmlx -framework OpenGL -framework AppKit
NAME = fdf
SRC = fdf.c draw.c keypress.c parse.c rotate.c
HEADER_DIR = .
SRC_OBJECT = $(SRC:.c=.o)
LIBFT = libft.a
LIBFT_DIR = ./ft_libft/
GNL = get_next_line.a
GNL_DIR = ./get_next_line/

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(HEADER_DIR)

all : $(NAME)

$(NAME) : $(SRC_OBJECT) $(GNL) $(LIBFT)
	$(CC) $(CFLAGS) $(MLXFLAGS) -o $@ $^

$(LIBFT) :
	make -C $(LIBFT_DIR) bonus
	cp $(LIBFT_DIR)$(LIBFT) .

$(GNL) :
	make -C $(GNL_DIR) all
	cp $(GNL_DIR)$(GNL) .

clean :
	rm -rf $(SRC_OBJECT) $(GNL) $(LIBFT)
	make -C $(LIBFT_DIR) clean
	make -C $(GNL_DIR) clean

fclean : clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(GNL_DIR) fclean

re : fclean all

.PHONY : all clean fclean re bonus