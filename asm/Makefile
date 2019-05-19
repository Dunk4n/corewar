##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

D_SRC	=	./src/
D_INC	=	./include/
D_LIB	=	./lib/my/

SRC	=	$(D_SRC)main.c			\
		$(D_SRC)op.c			\
		$(D_SRC)parse_head.c		\
		$(D_SRC)get_file.c		\
		$(D_SRC)bad_instruction.c	\
		$(D_SRC)check_arg.c		\
		$(D_SRC)is_label.c		\
		$(D_SRC)write_head.c		\
		$(D_SRC)write_instruction.c	\
		$(D_SRC)compile_instruction.c	\
		$(D_SRC)set_parameter.c		\
		$(D_SRC)is_arg.c		\
		$(D_SRC)check_label.c		\
		$(D_SRC)my_getnbr_long.c	\
		$(D_SRC)error.c				\

OBJ	=	$(SRC:%.c=%.o)

NAME	=	asm

CFLAGS	=	-W -Wall -Wextra -I$(D_INC)

LDFLAGS	=	-L$(D_LIB) -lmy

all: $(NAME)

libmy:
	@make -C $(D_LIB)

clean:
	@rm -f $(OBJ)

fclean:
	@$(MAKE) clean
	@$(MAKE) -C $(D_LIB) fclean
	@rm -f $(NAME)
	@rm -f *~

$(NAME): $(OBJ)
	@$(MAKE) -C lib/my
	@gcc -g -o $(NAME) $(OBJ) $(LDFLAGS)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
