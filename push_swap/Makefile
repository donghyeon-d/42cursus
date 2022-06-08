CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
RM = rm -rf
NAME = push_swap
SRC = stack.c utils.c operator_p.c operator_r.c operator_rr.c operator_s.c \
ft_split.c list.c makearray.c quicksort.c sort.c  quicksort_util.c smallsort.c
ARCHIVE = pushswap.a
MAIN = pushswap.c
DIR = ./
OBJS = $(SRC:.c=.o)

BONUS_NAME = checker
BONUS_SRC = $(BONUS_DIR)get_next_line.c \
$(BONUS_DIR)get_next_line_utils.c
BONUS_ARCHIVE = checker.a
BONUS_MAIN = $(BONUS_DIR)checker.c
BONUS_DIR = ./bonus/
BONUS_OBJS = $(BONUS_SRC:.c=.o)
# $(BONUS_DIR)ft_strncmp.c
all : $(NAME)

$(DIR)%.o : $(DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(DIR)

$(ARCHIVE) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $?

$(NAME) : $(ARCHIVE)
	$(CC) $(CFLAGS) -o $@ $(MAIN) $(ARCHIVE)

bonus : $(BONUS_NAME)

$(BONUS_DIR)%.o : $(BONUS_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(BONUS_DIR)

$(BONUS_ARCHIVE) : $(BONUS_OBJS)
	$(AR) $(ARFLAGS) $@ $?

$(BONUS_NAME) : $(BONUS_ARCHIVE) $(ARCHIVE)
	$(CC) $(CFLAGS) -o $@ $(BONUS_MAIN) $(BONUS_ARCHIVE) $(ARCHIVE)

clean :
	$(RM) $(OBJS) $(ARCHIVE) $(BONUS_OBJS) $(BONUS_ARCHIVE)

fclean : clean
	$(RM) $(NAME) $(BONUS_NAME)

re : fclean all

.PHONY : all clean fclean re bonus
