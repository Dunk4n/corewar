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
		$(D_SRC)charge_cor.c		\
		$(D_SRC)charge_all_cor.c	\
		$(D_SRC)put_prog.c		\
		$(D_SRC)core_war.c		\
		$(D_SRC)get_arg.c		\
		$(D_SRC)live.c			\
		$(D_SRC)ld.c			\
		$(D_SRC)st.c			\
		$(D_SRC)add.c			\
		$(D_SRC)sub.c			\
		$(D_SRC)and.c			\
		$(D_SRC)or.c			\
		$(D_SRC)xor.c			\
		$(D_SRC)zjmp.c			\

OBJ	=	$(SRC:%.c=%.o)

NAME	=	corwar

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
