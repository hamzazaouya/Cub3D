/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:47:41 by hazaouya          #+#    #+#             */
/*   Updated: 2023/01/17 11:20:27 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_line_content(char *line, int i, int *player)
{
	if (line[i] != '1' && line[i] != '0' && \
		!is_space(line[i]) && line[i] != 'E' && \
		line[i] != 'W' && line[i] != 'N' && \
		line[i] != 'S')
	{
		free(line);
		error(PARSE_ERROR);
		return (0);
	}
	*player += (line[i] == 'E' || line[i] == 'W' || \
		line[i] == 'N' || line[i] == 'S');
	i++;
	return (1);
}

int	check_map(char *line, int *player, int *params, int fd)
{
	int		i;

	line = ft_strdup(line);
	while (line)
	{
		i = 0;
		while (line[i])
		{
			if (!check_line_content(line, i++, player))
				return (0);
		}
		if (line)
			free(line);
		line = NULL;
		line = get_next_line(fd);
		if (!line)
			break ;
		line = rm_newline_trim(line);
	}
	params[MAP - 1] = 1;
	return (1);
}

int	yes_valid(int *params, int p_len, int player)
{
	if (player == 0)
		error(MISSING_PLAYER_ERROR);
	else if (player > 1)
		error(MORE_THAN_ONE_PLAYER_ERROR);
	else if (!is_all_one(params, p_len))
		error(PARSE_ERROR);
	return (1);
}

int	is_map_valid_extension(int fd, int *player, int *params)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line = rm_newline_trim(line);
		if (line && line[0] && !is_line_valid(line, player, params, fd))
		{
			free(line);
			close(fd);
			return (0);
		}
		if (line)
			free(line);
	}
	return (1);
}

int	is_map_valid(char *map)
{
	int			fd;
	int			player;
	static int	params[7];
	char		*line;

	if (!is_extension_valid(map, ".cub"))
		error(CUBEXT_ERROR);
	fd = open_file(map);
	player = 0;
	if (!is_map_valid_extension(fd, &player, params))
		return (0);
	close(fd);
	return (yes_valid(params, 7, player));
}
