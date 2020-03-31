##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC	=	cc

D_SRC	=	./src/
D_INC	=	./include/
D_LIB	=	./lib/my/

SRC	=	$(D_SRC)canoe.c					\
		$(D_SRC)menu.c					\
		$(D_SRC)select.c				\
		$(D_SRC)main.c					\
		$(D_SRC)core/parsing.c					\
		$(D_SRC)core/parsing_two.c					\
		$(D_SRC)core/is_num.c					\
		$(D_SRC)core/init_core.c					\
		$(D_SRC)core/op.c				\
		$(D_SRC)core/charge_cor.c			\
		$(D_SRC)core/charge_all_cor.c			\
		$(D_SRC)core/put_prog.c				\
		$(D_SRC)core/corewar.c				\
		$(D_SRC)core/get_arg.c				\
		$(D_SRC)core/get_value_arg.c			\
		$(D_SRC)core/live.c				\
		$(D_SRC)core/ld.c				\
		$(D_SRC)core/st.c				\
		$(D_SRC)core/add.c				\
		$(D_SRC)core/sub.c				\
		$(D_SRC)core/and.c				\
		$(D_SRC)core/or.c				\
		$(D_SRC)core/xor.c				\
		$(D_SRC)core/zjmp.c				\
		$(D_SRC)core/ldi.c				\
		$(D_SRC)core/sti.c				\
		$(D_SRC)core/fork.c				\
		$(D_SRC)core/lld.c				\
		$(D_SRC)core/lldi.c				\
		$(D_SRC)core/lfork.c				\
		$(D_SRC)core/aff.c				\
		$(D_SRC)core/not.c				\
		$(D_SRC)core/rsht.c				\
		$(D_SRC)core/lsht.c				\
		$(D_SRC)core/mul.c				\
		$(D_SRC)core/div.c				\
		$(D_SRC)core/mod.c				\
		$(D_SRC)core/rand.c				\
		$(D_SRC)core/die.c				\
		$(D_SRC)core/kill.c				\
		$(D_SRC)core/dump.c				\
		$(D_SRC)core/display_all_corewar.c		\
		$(D_SRC)core/init.c				\
		$(D_SRC)core/display_text.c			\
		$(D_SRC)core/start.c

OBJ	=	$(SRC:%.c=$(BUILD_DIR)/%.o)

NAME	=	corewar

CFLAGS	=	-W -Wall -Wextra -I$(D_INC)

LDFLAGS	=	-L$(D_LIB) -lmy -l csfml-graphics -l csfml-system  -l csfml-window -l csfml-audio -lm
LDFLAGS_WAGNER += -L $(D_LIB) -lmy -lm -lc_graph_prog
BUILD_DIR = build

all:	$(NAME)

options:
	@echo "  CC       $(CC)"
	@echo "  CFLAGS   $(CFLAGS)"
	@echo "  LDFLAGS  $(LDFLAGS)"

$(BUILD_DIR)/%.o: %.c $(INC)
	@mkdir -p $(@D)
	@echo "  CC       $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "  RM       $(BUILD_DIR)"
	@rm -rf $(BUILD_DIR)

fclean: clean
	@$(MAKE) -C $(D_LIB) fclean --no-print-directory
	@echo "  RM       $(NAME)"
	@rm -f $(NAME) *~

libmy:
	@make -C $(D_LIB) --no-print-directory

$(NAME): libmy options $(OBJ)
	@echo "  BUILD    $@"
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)

wagner: libmy options $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS_WAGNER)

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory

.PHONY: all options clean fclean re
