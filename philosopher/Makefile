CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = philosopher
NAME_BONUS = philosopher_bonus
DIR = ./src/
SRC = $(DIR)philosopher.c $(DIR)monitoring.c $(DIR)pthread_main.c $(DIR)utils.c
DIR_BONUS = ./bonus/
SRC_BONUS = $(DIR_BONUS)philosopher_bonus.c $(DIR_BONUS)monitoring_bonus.c $(DIR_BONUS)pthread_main_bonus.c $(DIR_BONUS)utils_bonus.c
OBJECT = $(SRC:.c=.o)
OBJECT_BONUS = $(SRC_BONUS:.c=.o)
HEADER_DIR = $(DIR)
HEADER_DIR_BONUS = $(DIR_BONUS)

ifdef WITH_BONUS
OFILES = $(BONUS_OBJECT)
else
OFILES = $(SRC_OBJECT)
endif

$(DIR)%.o : $(DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(HEADER_DIR)

$(DIR_BONUS)%.o : $(DIR_BONUS)%.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(HEADER_DIR_BONUS)

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME) : $(OBJECT)
	$(CC) $(CFLAGS) -o $@ $^

ldb : $(OFILES)
	$(CC) $(CFLAGS) -g $^ -o lbd

fsan : $(OFILES)
	$(CC) $(CFLAGS) -g3 -fsanitize=address $^ -o fsan -pthread

$(NAME_BONUS) : $(OBJECT_BONUS)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	rm -rf $(OBJECT) $(OBJECT_BONUS)

fclean : clean
	rm -rf $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY : all clean fclean re bonus