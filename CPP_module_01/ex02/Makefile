NAME = HI_THIS_IS_BRAIN
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

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
