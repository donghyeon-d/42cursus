CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g3 -pthread -fsanitize=address
NAME = philo
SRC = ./src/DiningRule.cpp ./src/Fork.cpp ./src/Main.cpp ./src/Monitor.cpp \
./src/Parser.cpp ./src/Philo.cpp ./src/Printer.cpp ./src/Timer.cpp ./src/PhiloThread.cpp

OBJECT = $(SRC:.cpp=.o)
HEADER_DIR = ./include

# %.o : %.cpp
# 	$(CXX) $(CXXFLAGS) -c -I $(HEADER_DIR) $<

all : $(NAME)

$(NAME) : $(OBJECT)
	$(CXX) $(CXXFLAGS) $(OBJECT) -o $(NAME)

clean :
	rm -rf $(OBJECT)

fclean : clean
	rm -rf $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY : all clean fclean re bonus
