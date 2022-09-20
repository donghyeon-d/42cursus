CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFLAG = -lreadline -L${HOME}/.brew/opt/readline/lib -I${HOME}/.brew/opt/readline/include -lncurses -I . -g
SAN = -g3 -fsanitize=address
NAME = minishell
DIR = ./
SRC = cmd_heredoc.c cmd_init.c cmd_path.c cmd_set1.c cmd_set2.c\
	  del.c \
	  env_list.c \
	  error.c \
	  execute.c execute_fork.c execute_built_in.c \
	  expand_env.c expand_env_utils.c expand_quotes.c expand_tilde.c \
	  expand_wildcard.c expand_wildcard_utils.c expand.c \
	  ft_cd.c ft_echo.c ft_env.c ft_exit.c ft_export.c ft_pwd.c ft_unset.c \
	  ft_atoi.c ft_split.c utils_1.c utils_2.c utils_3.c \
	  grammar_check.c paircheck.c type_check.c syntax.c\
	  main.c \
	  rdr_set.c rdr_set_heredoc.c \
	  signal.c \
	  split_input.c split_token_tree.c \
	  syntax.c \
	  token_list.c token_to_tree.c token.c \
	  tree.c tree_insert.c tree_traversal.c \
	  execute_and_or.c execute_parenthesis.c execute_pipe.c execute_set.c execute_single.c

OBJECT = $(SRC:.c=.o)

HEADER_DIR = $(DIR)

$(DIR)%.o : $(DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(HEADER_DIR)

all : $(NAME)

$(NAME) : $(OBJECT)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFLAG)


clean :
	rm -rf $(OBJECT)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re bonus
