NAME = Zombie
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
SRC_DIR = src
OBJ_DIR = obj
INC_DIR	= inc
HEADER = Zombie.hpp
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -I $(INC_DIR) -o $@ -c $<

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all