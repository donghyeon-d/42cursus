CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philosopher
NAME_BONUS = philosopher_bonus
DIR = ./src/
SRC = $(DIR)philosopher.c $(DIR)monitoring.c $(DIR)pthread_main.c \
	$(DIR)pthread_act.c $(DIR)pthread_time.c $(DIR)pthread_print.c \
	$(DIR)pthread_die.c $(DIR)utils.c
DIR_BONUS = ./bonus/
SRC_BONUS = $(DIR_BONUS)philosopher_bonus.c $(DIR_BONUS)process_print_bonus.c \
	$(DIR_BONUS)process_time_bonus.c $(DIR_BONUS)process_die_bonus.c \
	$(DIR_BONUS)monitoring_bonus.c $(DIR_BONUS)process_main_bonus.c \
	$(DIR_BONUS)process_act_bonus.c $(DIR_BONUS)process_child_bonus.c \
	$(DIR_BONUS)utils_bonus.c
OBJECT = $(SRC:.c=.o)
OBJECT_BONUS = $(SRC_BONUS:.c=.o)
HEADER_DIR = $(DIR)
HEADER_DIR_BONUS = $(DIR_BONUS)

$(DIR)%.o : $(DIR)%.c
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
