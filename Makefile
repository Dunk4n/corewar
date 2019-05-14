##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

ASM_DIR		=	./asm/
COREWAR_DIR	=	./corewar/

all:
	@make -C $(ASM_DIR)
	@make -C $(COREWAR_DIR)

clean:
	@make clean -C $(ASM_DIR)
	@make clean -C $(COREWAR_DIR)

fclean:
	@make fclean -C $(ASM_DIR)
	@make fclean -C $(COREWAR_DIR)

re:	fclean all

.PHONY: all clean fclean re
