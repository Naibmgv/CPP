NAME = Sed_is_for_losers
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g3 -std=c++98

SRC = $(shell find $(SRC_DIR) -name '*.cpp')
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
