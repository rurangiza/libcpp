### executable
BIN			=   runthis

### directories
SRC_DIR		=	src/
OBJ_DIR		=	obj/

### files
SOURCES		:= $(wildcard $(SRC_DIR)*.cpp)
OBJECTS		:= $(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SOURCES))

### variables
COMPILER	=   c++ -std=c++98 $(OPTIMIZE)
OPTIMIZE	=	-O2
INCLUDES	=	-I ./includes
FLAGS       =	-Wall -Wextra -Werror -Wconversion
# FLAGS		+=	-g -fsanitize=address

### rules
all:		$(BIN)

$(BIN): $(OBJECTS)
			@ $(COMPILER) $(OBJECTS) $(FLAGS) -o $(BIN)
			@echo "\n\033[0;32mCompilation done!\033[0m"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp
			@mkdir -p $(@D)
			@printf "\033[0;33mGenerating %-38.38s\r" $@
			@$(COMPILER) $(INCLUDES) $(FLAGS) -c $< -o $@

run: all
			@./$(BIN)

clean:
			@rm -rf $(OBJ_DIR)
			@printf "\033[0;31mDelete object files\n"

fclean:		clean
			rm -f $(BIN)

re:	fclean all

.PHONY:			all clean fclean run 