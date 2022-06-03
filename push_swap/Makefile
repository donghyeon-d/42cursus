CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
RM = rm -rf
NAME = push_swap
SRC = stack.c utils.c operator_p.c operator_r.c operator_rr.c operator_s.c ft_split.c list.c makearray.c quicksort.c sort.c 
ARCHIVE = pushswap.a
MAIN = pushswap.c
DIR = ./
OBJS = $(SRC:.c=.o)

all : $(NAME)

$(DIR)%.o : $(DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(DIR)

$(ARCHIVE) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $?

$(NAME) : $(ARCHIVE)
	$(CC) $(CFLAGS) -o $@ $(MAIN) $(ARCHIVE)


bonus : $(NAME)

fsan : $(ARCHIVE) $(MAIN)
	$(CC) $(CFLAGS) -g3 -fsanitize=address -o fsan $(ARCHIVE) $(MAIN)

ldb : $(ARCHIVE) $(MAIN)
	$(CC) $(CFLAGS) -g -o ldb $(ARCHIVE) $(MAIN)

clean :
	$(RM) $(OBJS) $(ARCHIVE)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
