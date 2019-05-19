/*
** EPITECH PROJECT, 2018
** src/get_file
** File description:
** csfml is the best thing ever
*/

#include <stdlib.h>
#include "asm.h"

static  int     if_end_of_line_is_corect(char *line, size_t i)
{
    if (line[i] != '\"')
        return (0);
    while (line[i + 1] == ' ' || line[i + 1] == '\t')
        i++;
    if (line[i + 1] && line[i + 1] != COMMENT_CHAR)
        return (0);
    return (1);
}

static  int     get_name(header_t *head, char *line, size_t nb)
{
    size_t i = 0;
    size_t j = 0;

    while (line[i] == ' ' || line[i] == '\t')
        i++;
    if (line[i] == COMMENT_CHAR || !line[i])
        return (0);
    if (line[i] != '.' || my_strncmp(line + i, NAME_CMD_STRING,
my_strlen(NAME_CMD_STRING)) || (line[i + my_strlen(NAME_CMD_STRING)] != ' ' &&
line[i + my_strlen(NAME_CMD_STRING)] != '\t'))
        return (error(line, nb, "syntax error") -1);
    i += my_strlen(NAME_CMD_STRING);
    while (line[i] == ' ' || line[i] == '\t')
        i++;
    if (line[i++] != '\"')
        return (error(line, nb, "syntax error") -1);
    while (line[i] && line[i] != '\"' && j < PROG_NAME_LENGTH)
        head->prog_name[j++] = line[i++];
    if (!if_end_of_line_is_corect(line, i))
        return (error(line, nb, "syntax error") -1);
    return (1);
}

static  int     get_comment(header_t *head, char *line, size_t nb)
{
    size_t i = 0;
    size_t j = 0;

    while (line[i] == ' ' || line[i] == '\t')
        i++;
    if (line[i] == COMMENT_CHAR || !line[i])
        return (0);
    if (line[i] != '.' || my_strncmp(line + i, COMMENT_CMD_STRING,
my_strlen(COMMENT_CMD_STRING)) || (line[i + my_strlen(COMMENT_CMD_STRING)] !=
' ' && line[i + my_strlen(COMMENT_CMD_STRING)] != '\t'))
        return (error(line, nb, "syntax error") -1);
    i += my_strlen(COMMENT_CMD_STRING);
    while (line[i] == ' ' || line[i] == '\t')
        i++;
    if (line[i++] != '\"')
        return (error(line, nb, "syntax error") -1);
    while (line[i] && line[i] != '\"' && j < COMMENT_LENGTH)
        head->comment[j++] = line[i++];
    if (!if_end_of_line_is_corect(line, i))
        return (error(line, nb, "syntax error") -1);
    return (2);
}

char    **get_file(int fd, size_t nb, compil_t *compil, int *head_or_comment)
{
    char    **file;
    char    *line = get_next_line(fd);

    if (*head_or_comment >= 2 && line && bad_instruction(line, compil, nb))
        *head_or_comment = -1;
    if (*head_or_comment < 2 && *head_or_comment != -1 && line)
        *head_or_comment = (*head_or_comment < 1) ? get_name(&(compil->head),
line, nb) : get_comment(&(compil->head), line, nb);
    if (!line || *head_or_comment == -1) {
        if (!(file = malloc(sizeof(char*) * (nb + 1))))
            return (NULL);
        file[nb] = NULL;
        return (file);
    }
    if (!(file = get_file(fd, nb + 1, compil, head_or_comment))) {
        free(line);
        return (NULL);
    }
    file[nb] = line;
    return (file);
}
