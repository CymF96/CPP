NAME = Bureaucrat
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
CFILES = main.cpp Bureaucrat.cpp
OFILES = $(CFILES:%.cpp=%.o)
HFILE = Bureaucrat.hpp
COLOR_DIR = ..
COLORS = $(COLOR_DIR)/Colors.hpp

all: $(NAME)

$(NAME): $(OFILES)
	@$(CXX) $(CXXFLAGS) $(OFILES) -o $(NAME)
	@echo "making Bureaucrat program"

$(OFILE): $(CFILE) $(HFILE) $(COLORS)
	@$(CXX) $(CXXFLAGS) -c $^ -o $@

clean:
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME)
	@echo "cleaning object file and program file"

re: fclean all

.PHONY: clean fclean re all