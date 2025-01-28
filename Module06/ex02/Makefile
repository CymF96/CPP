NAME = Identity
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
INC_DIR = inc
SRC_DIR = src
OBJ_DIR = obj
SRC = $(SRC_DIR)/Base.cpp \
      $(SRC_DIR)/Utility.cpp \
      $(SRC_DIR)/main.cpp
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
COLORS_DIR = ..
COLORS = $(COLORS_DIR)/Colors.hpp
INC = $(INC_DIR)/Base.hpp \
      $(INC_DIR)/A.hpp \
	  $(INC_DIR)/B.hpp \
	  $(INC_DIR)/C.hpp \
	  $(INC_DIR)/Utility.hpp 

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
