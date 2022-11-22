CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = harlFilter
DIR = ./
SRC = main.cpp HarlFilter.cpp
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

re :
	make fclean 
	make all

.PHONY : all clean fclean re
