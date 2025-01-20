NAME = Animal
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
INC_DIR = inc
SRC_DIR = src
OBJ_DIR = obj
SRC =	$(SRC_DIR)/Animal.cpp \
		$(SRC_DIR)/Cat.cpp \
		$(SRC_DIR)/Dog.cpp \
		$(SRC_DIR)/WrongAnimal.cpp \
		$(SRC_DIR)/WrongCat.cpp \
		$(SRC_DIR)/main.cpp
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
COLORS_DIR = ..
COLORS = $(COLORS_DIR)/Colors.hpp
INC =	$(INC_DIR)/Animal.hpp \
		$(INC_DIR)/Cat.hpp \
		$(INC_DIR)/Dog.hpp \
		$(INC_DIR)/WrongAnimal.hpp \
		$(INC_DIR)/WrongCat.hpp

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)
	@echo "Executable $(NAME) created!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -I $(INC_DIR) -c $< -o $@
	@echo "Compiled $< into $@"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Object files and directories removed."

fclean: clean
	@rm -f $(NAME)
	@echo "Executable $(NAME) removed."

re: fclean all

.PHONY: all clean fclean re