CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = a.out
DIR = ./
SRC = main.cpp Fixed.cpp
OBJECT = $(SRC:.cpp=.o)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -I $(DIR)

all : $(NAME)

$(NAME) : $(OBJECT)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean :
	rm -rf $(OBJECT)

fclean : clean
	rm -rf $(NAME)

re : 
	make fclean
	make all

.PHONY : all clean fclean re
