CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -pthread
NAME = philosopher
SRC = 
OBJECT = $(SRC:.c=.o)
c`:q

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(HEADER_DIR)

$(DIR_BONUS)%.o : $(DIR_BONUS)%.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(HEADER_DIR_BONUS)

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME) : $(OBJECT)
	$(CC) $(CFLAGS) -o $@ $^

$(NAME_BONUS) : $(OBJECT_BONUS)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	rm -rf $(OBJECT) $(OBJECT_BONUS)

fclean : clean
	rm -rf $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY : all clean fclean re bonus
