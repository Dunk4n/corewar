/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 12:24:22 by niduches          #+#    #+#             */
/*   Updated: 2020/07/10 12:55:06 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# include <unistd.h>

/*
** 6 * 1024
*/
# define MEM_SIZE 6144
# define IDX_MOD 512
# define MAX_ARGS_NUMBER 4

# define COMMENT_CHAR '#'
# define LABEL_CHAR ':'
# define DIRECT_CHAR '%'
# define SEPARATOR_CHAR ','

# define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING ".name"
# define COMMENT_CMD_STRING ".comment"

# define REG_NUMBER 16

typedef char			t_args_type;

# define T_REG 1
# define T_DIR 2
# define T_IND 4

# define T_LAB 8

struct					s_op
{
	char		*mnemonique;
	char		nbr_args;
	t_args_type type[MAX_ARGS_NUMBER];
	char		code;
	int			nbr_cycles;
	char		*comment;
	int			oct_parametre;
	int			dir_size;
};

typedef struct s_op		t_op;

# define IND_SIZE 2
# define DIR_SIZE 4
# define REG_SIZE DIR_SIZE

const t_op				g_op_tab[27];

# define PROG_NAME_LENGTH 128
# define COMMENT_LENGTH 2048

# define COREWAR_EXEC_MAGIC 0xea83f3

struct					s_header
{
	int		magic;
	char	prog_name[PROG_NAME_LENGTH + 1];
	int		prog_size;
	char	comment[COMMENT_LENGTH + 1];
};

typedef struct s_header	t_header;

# define CYCLE_TO_DIE 1536
# define CYCLE_DELTA 5
# define NBR_LIVE 40

#endif
