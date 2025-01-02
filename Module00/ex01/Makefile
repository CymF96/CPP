CPP = g++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = phonebook
CFILE = phonebook.cpp
OFILE = ($(CFILE):.cpp=.o)
HFILE = phonebook.hpp

all: $(NAME)

$(NAME): $(OFILE)
	@$(CPP) $(CPPFLAGS) $(HFILE) -o $@ $^
	@rm -rf $(OFILE)

$(OFILE): $(CFILE)
	@$(CPP) $(CPPFLAGS) $(HFILE) -c $^ -o $@

fclean:
	@rm -rf $(NAME)

re: fclean all

.PHONY: all fclean re