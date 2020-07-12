/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 12:40:08 by niduches          #+#    #+#             */
/*   Updated: 2020/07/10 12:56:42 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/libft.h"
# include "op.h"

# define ANSI_COLOR_RED		"\x1b[31m"
# define ANSI_COLOR_GREEN	"\x1b[32m"
# define ANSI_COLOR_YELLOW	"\x1b[33m"
# define ANSI_COLOR_BLUE	"\x1b[34m"
# define ANSI_COLOR_MAGENTA	"\x1b[35m"
# define ANSI_COLOR_CYAN	"\x1b[36m"
# define ANSI_COLOR_RESET	"\x1b[0m"

typedef union	u_data
{
	int		nb;
	char	data[4];
}				t_data;

typedef union	u_short
{
	short	nb;
	char	data[2];
}				t_short;

typedef struct	s_label
{
	char	*name;
	size_t	pos;
}				t_label;

typedef struct	s_compil
{
	t_header	head;
	char		**file;
	size_t		nb_label;
	t_label		*label;
	size_t		prog_size;
	char		*instr;
	size_t		pos;
}				t_compil;

char			**parse_head(char const *name, t_compil *compil);
char			**get_file(int fd, size_t nb, t_compil *compil,
int *head_or_comment);
int				bad_instruction(char *line, t_compil *compil, size_t nb);
int				good_name(char c);
int				check_arg(char *line, int code, t_header *head);
int				is_label(char *line, t_compil *compil);
int				is_an_instruction(char *line, t_header *head);
int				write_head(t_compil *compil, t_header *head, const char *name,
int	*fd);
int				write_instruction(t_compil *compil, int fd);
void			compile_instruction(t_compil *compil, char *line);
int				get_indice(char *line, size_t len);
int				is_reg(char *line);
int				is_ind(char *line);
int				is_dir(char *line);
void			set_parameter(t_compil *compil, char *line, int code, int pos);
int				little_endian(int nb);
int				check_label(char **file, t_compil *compil);
long long		ft_getnbr_long(char const *str);
int				error(char *line, size_t nb, char *err_msg);

#endif
