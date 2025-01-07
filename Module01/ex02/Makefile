NAME = MemAddress
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
CFILE = main.cpp
OFILE = $(CFILE:%.cpp=%.o)

all : $(NAME)

$(NAME): $(OFILE)
	@$(CXX) $(CXXFLAGS) $(OFILE) -o $(NAME)

$(OFILE): $(CFILE)
	@$(CXX) $(CXXFLAGS) -c $(CFILE) -o $(OFILE)

clean:
	@rm -f $(OFILE)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all