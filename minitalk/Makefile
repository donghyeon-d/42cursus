# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 15:29:33 by dongchoi          #+#    #+#              #
#    Updated: 2022/06/21 15:38:11 by dongchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = minitalk
SERVER_SRC = server.c server_signal.c server_transmit.c utils.c
SERVER_OBJECT = $(SERVER_SRC:.c=.o)
SERVER_NAME = server
CLIENT_SRC = client.c client_signal.c utils.c
CLIENT_OBJECT = $(CLIENT_SRC:.c=.o)
CLIENT_NAME = client
BONUS_SERVER_SRC = server_bonus.c server_signal_bonus.c \
server_transmit_bonus.c utils_bonus.c
BONUS_SERVER_OBJECT = $(BONUS_SERVER_SRC:.c=.o)
BONUS_CLIENT_SRC = client_bonus.c client_signal_bonus.c utils_bonus.c
BONUS_CLIENT_OBJECT = $(BONUS_CLIENT_SRC:.c=.o)
HEADER_DIR = .

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(HEADER_DIR)

ifdef WITH_BONUS
SERVER_OFILES = $(BONUS_SERVER_OBJECT)
CLIENT_OFILES = $(BONUS_CLIENT_OBJECT)
else
SERVER_OFILES = $(SERVER_OBJECT)
CLIENT_OFILES = $(CLIENT_OBJECT)
endif

all : $(NAME)

$(NAME) : $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME) : $(SERVER_OFILES)
	$(CC) $(CFLAGS) -o $(SERVER_NAME) $(SERVER_OFILES)

$(CLIENT_NAME) : $(CLIENT_OFILES)
	$(CC) $(CFLAGS) -o $(CLIENT_NAME) $(CLIENT_OFILES)

bonus : 
		make WITH_BONUS=1 all

clean :
	rm -f $(SERVER_OBJECT) $(CLIENT_OBJECT) $(BONUS_SERVER_OBJECT) \
	$(BONUS_CLIENT_OBJECT)

fclean : clean
	rm -f $(SERVER_NAME) $(CLIENT_NAME)

re : fclean all

.PHONY : all clean fclean re bonus
