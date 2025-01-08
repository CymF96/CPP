NAME = Replace
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
CFILE = main.cpp
OFILE = $(CFILE:%.cpp=%.o)
TEXTNAME = NewText.txt
COLORS_DIR = ..
COLORS = $(COLORS_DIR)/Colors.hpp

all: $(NAME)

$(NAME): $(OFILE)
	@$(CXX) $(CXXFLAGS) -o $@ $^
	@rm -f $(OFILE)

$(OFILE): $(CFILE) $(COLORS)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean: 
	@rm -f $(OFILE)

fclean: clean
	@rm -f $(NAME) $(TEXTNAME)

re : fclean all

.PHONY: all clean fclean re