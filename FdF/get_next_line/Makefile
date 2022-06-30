CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = get_next_line.a
SRC = get_next_line.c get_next_line_utils.c
HEADER_DIR = .
SRC_OBJECT = $(SRC:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(HEADER_DIR)

all : $(NAME)

$(NAME) : $(SRC_OBJECT)
	ar rc $@ $^

clean :
	rm -f $(SRC_OBJECT)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
