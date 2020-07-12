# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niduches <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/19 16:00:17 by niduches          #+#    #+#              #
#    Updated: 2020/07/12 20:50:04 by niduches         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc

D_SRC		=	./src/
D_INC		=	./include/

BUILD_DIR	=	build

SRC_PATH	=	op.c				\
				charge_cor.c		\
				charge_all_cor.c	\
				put_prog.c			\
				corewar.c			\
				get_arg.c			\
				get_value_arg.c		\
				live.c				\
				ld.c				\
				st.c				\
				add.c				\
				sub.c				\
				and.c				\
				or.c				\
				xor.c				\
				zjmp.c				\
				ldi.c				\
				sti.c				\
				fork.c				\
				lld.c				\
				lldi.c				\
				lfork.c				\
				aff.c				\
				not.c				\
				rsht.c				\
				lsht.c				\
				mul.c				\
				div.c				\
				mod.c				\
				rand.c				\
				die.c				\
				kill.c				\
				stop.c				\
				dump.c				\
				parsing.c			\
				parsing_two.c		\
				is_num.c			\
				init_core.c			\
				main.c				\
				option.c			\
				corewar_live.c		\
				utils.c				\

SRC			=	$(addprefix $(D_SRC),$(SRC_PATH))

NAME		=	corewar

OBJ			=	$(SRC:%.c=$(BUILD_DIR)/%.o)

CFLAGS		=	-I$(D_INC) -Wall -Wextra -g#-Werror

LDFLAGS		=	-L./libft/ -lft

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
	@make -C libft/ clean
	@echo "  RM       $(BUILD_DIR)"
	@rm -rf $(BUILD_DIR)

fclean: clean
	@make -C libft/ fclean
	@echo "  RM       $(NAME)"
	@rm -f $(NAME) *~

$(NAME): options $(OBJ)
	@make -C libft/
	@echo "  BUILD    $@"
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS) ./libft/libft.a

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory

.PHONY: all options clean fclean re
