NAME = ClapTrap
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
CFILES = main.cpp ClapTrap.cpp
OFILES = $(CFILES:%.cpp=%.o)
HFILE = ClapTrap.hpp
COLOR_DIR = ..
COLORS = $(COLOR_DIR)/Colors.hpp

all: $(NAME)

$(NAME): $(OFILES)
	@$(CXX) $(CXXFLAGS) $(OFILES) -o $(NAME)
	@rm -f $(OFILES)
	@echo "making Fixed program"

$(OFILE): $(CFILE) $(HFILE) $(COLORS)
	@$(CXX) $(CXXFLAGS) -c $^ -o $@

clean:
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME)
	@echo "cleaning object file and program file"

re: fclean all

.PHONY: clean fclean re all