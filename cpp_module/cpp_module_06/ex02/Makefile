CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = a.out
SRC = main.cpp Base.cpp A.cpp B.cpp C.cpp
OBJECT = $(SRC:.cpp=.o)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $<

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
