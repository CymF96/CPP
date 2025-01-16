CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = megaphone
CFILE = megaphone.cpp
OFILE = megaphone.o

all: $(NAME)

$(NAME): $(OFILE)
	@echo "Making ./Megaphone"
	@$(CPP) $(CPPFLAGS) -o $@ $^

$(OFILE): $(CFILE)
	@$(CPP) $(CPPFLAGS) -c $^ -o $@

clean:
	@rm -rf $(OFILE)

fclean: clean
	@echo "Cleaning Megaphone"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all fclean re