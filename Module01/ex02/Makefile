NAME = MemAddress
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
CFILE = main.cpp
OFILE = $(CFILE:%.cpp=%.o)
COLORS_DIR = ..
COLORS = $(COLORS_DIR)/Colors.hpp

all : $(NAME)

$(NAME): $(OFILE)
	@$(CXX) $(CXXFLAGS) $(OFILE) -o $(NAME)

$(OFILE): $(CFILE) $(COLORS)
	@$(CXX) $(CXXFLAGS) -c $(CFILE) -o $(OFILE)

clean:
	@rm -f $(OFILE)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all