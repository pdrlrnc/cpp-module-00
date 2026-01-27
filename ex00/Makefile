NAME        = megaphone
SRC         = megaphone.cpp
OBJ         = $(SRC:.cpp=.o)

COMPILER    = c++
CFLAGS      = -Wall -Wextra -Werror -g -std=c++98
RM          = rm -rf

GRAY        = \033[38;5;244m
CURSIVE	   := \033[33;3m
INDIGO     := \033[38;5;057m
DEF_COLOUR  = \033[0m

all: $(NAME)
	@echo "$(GRAY)                    ^...^$(DEF_COLOUR)"
	@echo "$(GRAY)                   <_* *_>$(DEF_COLOUR)"
	@echo "$(GRAY)                     \_/  $(DEF_COLOUR)"
	@echo "$(CURSIVE)$(INDIGO)c++: shooting urself in the foot was never this fun! $(DEF_COLOUR)"

$(NAME): $(OBJ)
	@echo "Linking executable..."
	@$(COMPILER) $(OBJ) -o $@
	@echo "$(NAME) built!"

%.o: %.cpp
	@echo "Compiling $@..."
	@$(COMPILER) $(CFLAGS) -c $< -o $@

clean:
	@echo "Removing object files..."
	@$(RM) $(OBJ)

fclean: clean
	@echo "Removing executable..."
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
