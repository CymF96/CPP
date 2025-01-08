CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = Accounts
CFILE = Account.cpp tests.cpp
OFILES = $(CFILE:%.cpp=%.o)
HFILE = Account.hpp

all : $(NAME)

$(NAME): $(OFILES)
	@$(CXX) $(CXXFLAGS) -o $@ $^
	
%.o: %.cpp $(HFILE)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OFILES)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all fclean re