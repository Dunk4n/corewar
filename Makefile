##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

ASM_DIR	=	./asm/

all:
	@make -C $(ASM_DIR)

clean:
	@make clean -C $(ASM_DIR)

fclean:
	@make fclean -C $(ASM_DIR)

re:	fclean all

.PHONY: all clean fclean re
