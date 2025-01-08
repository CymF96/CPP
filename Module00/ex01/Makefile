CPP = g++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = Phonebook
CFILE = Phonebook.cpp main.cpp
OFILE = $(CFILE:.cpp=.o)
HFILE = Phonebook.hpp

all: $(NAME)

$(NAME): $(OFILE)
	@$(CPP) $(CPPFLAGS) $(HFILE) -o $@ $^
	@rm -rf $(OFILE)

$(OFILE): $(CFILE)
	@$(CPP) $(CPPFLAGS) -c $^ -o $@

fclean:
	@rm -rf $(NAME)

re: fclean all

.PHONY: all fclean re