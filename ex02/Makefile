NAME		=	canon

CC			=	c++

CFLAGS		=	-Wall -Werror -Wextra -std=c++98 -g3

SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR		=	includes/

RESET = \033[0m
BOLD = \033[1m
GREEN = \033[32m
CYAN = \033[36m
MAGENTA = \033[35m
RED = \033[31m

LINE = "------------------------------------"
HACKMSG = "[ SYSTEM BOOTING... ]"
SUCCESS = "[ OK ]"


SRC_FILES	=	main.cpp \
				Fixed.cpp

OBJ_FILES	=	$(SRC_FILES:.cpp=.o)


SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

all: $(NAME)

all: $(NAME)
	@printf "\n"
	@printf "$(MAGENTA)            ___ ___        ___    _____    _     _   \n$(RESET)"
	@printf "$(MAGENTA) ___ _ _   |   |_  |   ___|  _|  |    _| _| |_ _| |_ \n$(RESET)"
	@printf "$(MAGENTA)| -_|_'_|  | | |  _|  | . |  _|  |   |_ |_   _|_   _|\n$(RESET)"
	@printf "$(MAGENTA)|___|_,_|  |___|___|  |___|_|    |_____|  |_|   |_|  \n$(RESET)"
	@printf "$(MAGENTA)                                                     \n$(RESET)"
	@printf "\n"

$(NAME): $(OBJ)
	@echo "$(GREEN)>> COMPILING SYSTEM MODULES <<$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(CYAN)$(SUCCESS) SYSTEM READY.$(RESET)"

$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp 
	@mkdir -p $(dir $@)
	@echo "$(MAGENTA)> Processing: $(notdir $<)...$(RESET)"
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
	rm -rf $(OBJ_DIR); \
	echo "$(BLUE)Deleting all objects from /ex00...$(RESET)"; else \
	echo "No objects to remove from /ex00."; \
	fi;

fclean: clean
	@echo "$(RED)🧹 Wiping full system...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)$(SUCCESS) Full system wipe complete.$(RESET)"

re: fclean all

-include $(OBJ:.o=.d)

.PHONY: all clean fclean re