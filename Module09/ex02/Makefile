NAME = PmergeMe
DEBUG = PmergeMe_debug
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
OBJ = OBJ
CFILES = main.cpp PmergeMe.cpp
OFILES = $(patsubst %.cpp, $(OBJ)/%.o, $(CFILES))
CFILES_DEBUG = debugging/main_Debugging.cpp debugging/PmergeMe_Debugging.cpp
OFILES_DEBUG = $(patsubst debugging/%.cpp, $(OBJ)/debugging/%.o, $(CFILES_DEBUG))
COLOR_DIR = ..
HFILES = PmergeMe.hpp $(COLOR_DIR)/Colors.hpp
HFILES_DEBUG = debugging/PmergeMe_Debugging.hpp $(COLOR_DIR)/Colors.hpp

all: $(NAME)
debug: $(DEBUG)

$(NAME): $(OFILES)
	@$(CXX) $(CXXFLAGS) $(OFILES) -o $(NAME)
	@echo "Making $@ program"

$(DEBUG): $(OFILES_DEBUG)
	@$(CXX) $(CXXFLAGS) $(OFILES_DEBUG) -o $(DEBUG)
	@echo "Making $@ debugging program"

$(OBJ)/%.o: %.cpp $(HFILES)
	@mkdir -p $(OBJ)
	@$(CXX) $(CXXFLAGS) -c $< -o $@


$(OBJ)/debugging/%.o: debugging/%.cpp $(HFILES_DEBUG)
	@mkdir -p $(OBJ)/debugging 
	@$(CXX) $(CXXFLAGS) -c $< -o $@ 

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME) $(DEBUG)
	@echo "Cleaning object files and program files"

re: fclean all

re_debug: fclean debug

.PHONY: clean fclean re all debug
