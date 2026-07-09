CXX = c++

FLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98

SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongCat.cpp WrongAnimal.cpp

OBJ = $(SRC:.cpp=.o)

NAME = polymorphism

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re