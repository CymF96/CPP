NAME = Bureaucrat
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
INC_DIR = inc
SRC_DIR = src
OBJ_DIR = obj
SRC = $(SRC_DIR)/Bureaucrat.cpp \
      $(SRC_DIR)/AForm.cpp \
	  $(SRC_DIR)/Intern.cpp \
	  $(SRC_DIR)/PresidentialPardonForm.cpp \
	  $(SRC_DIR)/RobotomyRequestForm.cpp \
	  $(SRC_DIR)/ShrubberyCreationForm.cpp \
      $(SRC_DIR)/main.cpp
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
COLORS_DIR = ..
COLORS = $(COLORS_DIR)/Colors.hpp
INC = $(INC_DIR)/Bureaucrat.hpp \
	  $(INC_DIR)/PresidentialPardonForm.hpp \
	  $(INC_DIR)/RobotomyRequestForm.hpp \
	  $(INC_DIR)/ShrubberyCreationForm.hpp \
	  $(INC_DIR)/AForm.hpp \
	  $(INC_DIR)/Intern.hpp


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