/*
** EPITECH PROJECT, 2018
** asm
** File description:
** no, real programmers use cat
*/

#ifndef ASM_H
#define ASM_H

#include "my.h"
#include "op.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

typedef union   data_u
{
    int     nb;
    char    data[4];
}               data_t;

typedef union   short_u
{
    short   nb;
    char    data[2];
}               short_t;

typedef struct  label_s
{
    char    *name;
    size_t  pos;
}               label_t;

typedef struct  compil_s
{
    header_t    head;
    char        **file;
    size_t      nb_label;
    label_t     *label;
    size_t      prog_size;
    char        *instr;
    size_t      pos;
}               compil_t;

char    **parse_head(char const *name, compil_t *compil);
char    **get_file(int fd, size_t nb, compil_t *compil, int *head_or_comment);
int     bad_instruction(char *line, compil_t *compil, size_t nb);
int     good_name(char c);
int     check_arg(char *line, int code, header_t *head);
int     is_label(char *line, compil_t *compil);
int     is_an_instruction(char *line, header_t *head);
int     write_head(compil_t *compil, header_t *head, const char *name, int *fd);
int     write_instruction(compil_t *compil, int fd);
void    compile_instruction(compil_t *compil, char *line);
int     get_indice(char *line, size_t len);
int     is_reg(char *line);
int     is_ind(char *line);
int     is_dir(char *line);
void    set_parameter(compil_t *compil, char *line, int code, int pos);
int     little_endian(int nb);
int     check_label(char **file, compil_t *compil);
long    long    my_getnbr_long(char const *str);
int     error(char *line, size_t nb, char *err_msg);

#endif
