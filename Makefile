### executable
NAME		=	Harl
BIN			=   bin/$(NAME)

### directories
SRC_DIR		=	src/
OBJ_DIR		=	obj/
BIN_DIR		=	bin/

### files
FILES		=	Harl main UserInterface
SOURCES		=	$(addsuffix .cpp, $(FILES))
OBJECTS		=	$(addprefix $(OBJ_DIR), $(SOURCES:.cpp=.o))

### variables
COMPILER	=   c++ -std=c++98 $(OPTIMIZE)
OPTIMIZE	=	-O2
INCLUDES	=	-I ./includes
FLAGS       =	-Wall -Wextra -Werror
DFLAGS		=	-Wconversion -g -fsanitize=address

### rules
all:		$(BIN)

$(BIN): $(OBJECTS) | $(BIN_DIR)
			$(COMPILER) $(OBJECTS) -o $(BIN)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp
			mkdir -p $(@D)
			$(COMPILER) $(INCLUDES) $(FLAGS) -c $< -o $@

clean:
			rm -rf $(OBJ_DIR)

fclean:		clean
			rm -rf $(BIN_DIR)

re:			fclean all

.PHONY:		all clean fclean re run