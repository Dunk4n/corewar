# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niduches <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/19 16:00:17 by niduches          #+#    #+#              #
#    Updated: 2020/07/11 20:16:56 by niduches         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc

D_SRC		=	./src/
D_INC		=	./include/

BUILD_DIR	=	build

SRC_PATH	=	main.c					\
				op.c					\
				parse_head.c			\
				get_file.c				\
				bad_instruction.c		\
				check_arg.c				\
				is_label.c				\
				write_head.c			\
				write_instruction.c		\
				compile_instruction.c	\
				set_parameter.c			\
				is_arg.c				\
				check_label.c			\
				my_getnbr_long.c		\
				error.c					\

SRC			=	$(addprefix $(D_SRC),$(SRC_PATH))

NAME		=	asm

OBJ			=	$(SRC:%.c=$(BUILD_DIR)/%.o)

CFLAGS		=	-I$(D_INC) -Wall -Wextra -Werror

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
