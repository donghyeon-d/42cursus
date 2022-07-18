CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -g
NAME = philosopher
NAME_BONUS = philosopher_bonus
SRC = philosopher.c
# SRC_BONUS = 
SRC_OBJECT = $(SRC:.c=.o)
# BONUS_OBJECT = $(SRC_BONUS:.c=.o)
HEADER_DIR = .
LIBFT = libft.a
LIBFT_DIR = ../ft_libft/

ifdef WITH_BONUS
OFILES = $(BONUS_OBJECT)
else
OFILES = $(SRC_OBJECT)
endif

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(HEADER_DIR)

all : $(NAME)

bonus : 
        make WITH_BONUS=1 all

$(NAME) : $(OFILES)# $(GNL) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

$(NAME_BONUS) : $(OFILES) $(GNL) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

$(LIBFT) :
	make -C $(LIBFT_DIR) bonus
	cp $(LIBFT_DIR)$(LIBFT) .

$(GNL) :
	make -C $(GNL_DIR) all
	cp $(GNL_DIR)$(GNL) .

clean :
	rm -rf $(SRC_OBJECT) #$(BONUS_OBJECT) $(GNL) $(LIBFT)
	# make -C $(LIBFT_DIR) clean
	# make -C $(GNL_DIR) clean
	# make -C $(MLXLIB_DIR) clean

fclean : clean
	rm -rf $(NAME) $(NAME_BONUS)
	# make -C $(LIBFT_DIR) fclean
	# make -C $(GNL_DIR) fclean
	# rm -rf $(MLXLIB)

re : fclean all

.PHONY : all clean fclean re bonus