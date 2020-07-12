/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corwar.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:01:35 by niduches          #+#    #+#             */
/*   Updated: 2020/07/12 21:00:59 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORWAR_H
# define CORWAR_H

# include "../libft/libft.h"
# include "op.h"

# define DEC "0123456789"
# define HEX "0123456789ABCDEF"

# define NB_INSTR 26

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

typedef struct	s_prog
{
	size_t	nb;
	size_t	nb_name;
	size_t	daron;
	size_t	size;
	size_t	start;
	int		tmp;
	int		reg[REG_NUMBER];
	int		carry;
	int		pc;
	int		live;
	int		to_exc;
	char	name[PROG_NAME_LENGTH + 1];
}				t_prog;

typedef struct	s_corewar
{
	t_prog	*prog;
	size_t	nb_prog;
	char	map[MEM_SIZE];
	int		who[MEM_SIZE];
	int		cycle_to_die;
	int		max_check;
	int		nb_live;
	int		last_live;
	size_t	nb_prog_live;
	int		dump;
	char	*order[MAX_ARGS_NUMBER + 1];
	int		adress[MAX_ARGS_NUMBER];
	int		number[MAX_ARGS_NUMBER];
	int		champions;
}				t_corewar;

char			*charge_cor(char *name, t_prog *prog);
char			**charge_all_cor(char **name, size_t size, t_prog **progs);
int				put_prog(t_corewar *core, char **instr);
int				corewar(t_corewar *core);
int				get_arg(char *map, int pc, int *tab);
int				get_value_arg(t_corewar *core, t_prog *prog, int value,
int type);
int				get_value_arg_long(t_corewar *core, t_prog *prog, int value,
int type);
int				get_nb(t_corewar *core);
void			put_fork_in_memory(t_corewar *core, int arg, t_prog *a,
t_prog *b);
void			dump(char *map);
int				parsing(int ac, char **av, t_corewar *core);
int				is_number(char *str);
int				put_champion(char **av, int *arg, t_corewar *core);
void			init_core(t_corewar *core);
void			sort_name(t_corewar *core);
int				count_cor(int ac, char **av, t_corewar *core);
int				option_dump(int ac, char **av, int *arg, t_corewar *core);
int				option_n(int ac, char **av, int *arg, t_corewar *core);
int				option_a(int ac, char **av, int *arg, t_corewar *core);
void			win(t_corewar *core);
void			check_live_prog(t_corewar *core);
int				reverse_int(int nb);
short			reverse_short(short nb);
int				modulo(int nb);

/*
** instruction
*/

int				live(t_corewar *core, t_prog *prog);
int				ld(t_corewar *core, t_prog *prog);
int				st(t_corewar *core, t_prog *prog);
int				add(t_corewar *core, t_prog *prog);
int				sub(t_corewar *core, t_prog *prog);
int				and(t_corewar *core, t_prog *prog);
int				or(t_corewar *core, t_prog *prog);
int				xor(t_corewar *core, t_prog *prog);
int				zjmp(t_corewar *core, t_prog *prog);
int				ldi(t_corewar *core, t_prog *prog);
int				sti(t_corewar *core, t_prog *prog);
int				my_fork(t_corewar *core, t_prog *prog);
int				lld(t_corewar *core, t_prog *prog);
int				lldi(t_corewar *core, t_prog *prog);
int				lfork(t_corewar *core, t_prog *prog);
int				aff(t_corewar *core, t_prog *prog);

/*
** bonus
*/

int				not(t_corewar *core, t_prog *prog);
int				rsht(t_corewar *core, t_prog *prog);
int				lsht(t_corewar *core, t_prog *prog);
int				mul(t_corewar *core, t_prog *prog);
int				my_div(t_corewar *core, t_prog *prog);
int				mod(t_corewar *core, t_prog *prog);
int				my_rand(t_corewar *core, t_prog *prog);
int				die(t_corewar *core, t_prog *prog);
int				kill(t_corewar *core, t_prog *prog);
int				stop(t_corewar *core, t_prog *prog);

#endif
