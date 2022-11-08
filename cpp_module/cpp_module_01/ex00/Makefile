CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g
NAME = BraiiiiiiinnnzzzZ
DIR = ./
SRC = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJECT = $(SRC:.cpp=.o)

%.o : %.cpp
	$(CXX) $(CPPFLAGS) -c $< -I $(DIR)

all : $(NAME)

$(NAME) : $(OBJECT)
	$(CXX) $(CPPFLAGS) -o $@ $^

clean :
	rm -rf $(OBJECT)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
