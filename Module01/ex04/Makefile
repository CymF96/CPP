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
	@echo "Making ./Replace"
	@$(CXX) $(CXXFLAGS) -o $@ $^

$(OFILE): $(CFILE) $(COLORS)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean: 
	@rm -f $(OFILE)

fclean: clean
	@echo "Cleaning ./Replace"
	@rm -f $(NAME) $(TEXTNAME)

re : fclean all

.PHONY: all clean fclean re