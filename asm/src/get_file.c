/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 13:15:49 by niduches          #+#    #+#             */
/*   Updated: 2020/07/10 15:41:53 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "asm.h"

static int	if_end_of_line_is_corect(char *line, size_t i)
{
	if (line[i] != '\"')
		return (0);
	while (line[i + 1] == ' ' || line[i + 1] == '\t')
		i++;
	if (line[i + 1] && line[i + 1] != COMMENT_CHAR)
		return (0);
	return (1);
}

static int	get_name(t_header *head, char *line, size_t nb)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == COMMENT_CHAR || !line[i])
		return (0);
	if (line[i] != '.' || ft_strncmp(line + i, NAME_CMD_STRING,
ft_strlen(NAME_CMD_STRING)) || (line[i + ft_strlen(NAME_CMD_STRING)] != ' ' &&
line[i + ft_strlen(NAME_CMD_STRING)] != '\t'))
		return (error(line, nb, "syntax error") - 1);
	i += ft_strlen(NAME_CMD_STRING);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i++] != '\"')
		return (error(line, nb, "syntax error") - 1);
	while (line[i] && line[i] != '\"' && j < PROG_NAME_LENGTH)
		head->prog_name[j++] = line[i++];
	head->prog_name[j] = '\0';
	if (!if_end_of_line_is_corect(line, i))
		return (error(line, nb, "syntax error") - 1);
	return (1);
}

static int	get_comment(t_header *head, char *line, size_t nb)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == COMMENT_CHAR || !line[i])
		return (0);
	if (line[i] != '.' || ft_strncmp(line + i, COMMENT_CMD_STRING,
ft_strlen(COMMENT_CMD_STRING)) || (line[i + ft_strlen(COMMENT_CMD_STRING)] !=
' ' && line[i + ft_strlen(COMMENT_CMD_STRING)] != '\t'))
		return (error(line, nb, "syntax error") - 1);
	i += ft_strlen(COMMENT_CMD_STRING);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i++] != '\"')
		return (error(line, nb, "syntax error") - 1);
	while (line[i] && line[i] != '\"' && j < COMMENT_LENGTH)
		head->comment[j++] = line[i++];
	head->comment[j] = '\0';
	if (!if_end_of_line_is_corect(line, i))
		return (error(line, nb, "syntax error") - 1);
	return (2);
}

static char	*get_safe_line(int fd)
{
	char	*line;

	if (get_next_line(fd, &line) == 0 && !*line)
	{
		free(line);
		line = NULL;
	}
	return (line);
}

char		**get_file(int fd, size_t nb, t_compil *compil,
int *head_or_comment)
{
	char	**file;
	char	*line;

	line = get_safe_line(fd);
	if (*head_or_comment >= 2 && line && bad_instruction(line, compil, nb))
		*head_or_comment = -1;
	if (*head_or_comment < 2 && *head_or_comment != -1 && line)
		*head_or_comment = (*head_or_comment < 1) ? get_name(&(compil->head),
line, nb) : get_comment(&(compil->head), line, nb);
	if (!line || *head_or_comment == -1)
	{
		if (!(file = malloc(sizeof(char*) * (nb + 1))))
			return (NULL);
		file[nb] = NULL;
		return (file);
	}
	if (!(file = get_file(fd, nb + 1, compil, head_or_comment)))
	{
		free(line);
		return (NULL);
	}
	file[nb] = line;
	return (file);
}
