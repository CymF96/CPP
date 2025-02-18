NAME = RPN
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
OBJ = OBJ
CFILES = main.cpp RPN.cpp
OFILES = $(patsubst %.cpp, $(OBJ)/%.o, $(CFILES))
COLOR_DIR = ..
HFILES = RPN.hpp $(COLOR_DIR)/Colors.hpp


all: $(NAME)

$(NAME): $(OFILES)
	@$(CXX) $(CXXFLAGS) $(OFILES) -o $(NAME)
	@echo "making $@ program"

$(OBJ)/%.o: %.cpp $(HFILES)
	@mkdir -p $(OBJ)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@echo "cleaning object file and program file"

re: fclean all

.PHONY: clean fclean re all