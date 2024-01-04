NAME 		=	gnl
CFLAGS 		=	-Wall -Wextra -Werror
#DEBUG 	= -g -fsanitize=address

SRC			=	get_next_line.c \
				get_next_line_utils.c \
				main.c

OBJ			=	$(SRC:%.c=%.o)

GREEN		:=	\033[0;32m
DEFAULT		:=	\033[0m

.SILENT: $(OBJ)
.PHONY: all clean fclean re

all: 			$(NAME)

$(NAME):		$(OBJ)
				cc $(CFLAGS) $(OBJ) -o $(NAME)
				@echo "$(GREEN)Compiled executable <$(NAME)>.$(DEFAULT)"

clean:
				rm -f $(OBJ)
				@echo "$(GREEN)Object files removed.$(DEFAULT)"

fclean: 		clean
				rm -rf $(NAME)
				@echo "$(GREEN)Removed executable.$(DEFAULT)"

re: 			fclean $(NAME)
