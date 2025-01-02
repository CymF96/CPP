CPP = g++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = megaphone
CFILE = megaphone.cpp
OFILE = megaphone.o

all: $(NAME)

$(NAME): $(OFILE)
	@$(CPP) $(CPPFLAGS) -o $@ $^
	@rm -rf $(OFILE)

$(OFILE): $(CFILE)
	@$(CPP) $(CPPFLAGS) -c $^ -o $@

fclean:
	@rm -rf $(NAME)

re: fclean all

.PHONY: all fclean re