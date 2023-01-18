/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:46:51 by hazaouya          #+#    #+#             */
/*   Updated: 2023/01/17 11:57:26 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_directions(char *line, char **file, int *fd)
{
	char	**split;
	char	*filename;

	split = split_by_space(line);
	filename = split[1];
	if (!is_extension_valid(filename, ".xpm"))
		error(XPMEXT_ERROR);
	*file = ft_strdup(filename);
	*fd = open_file(filename);
	free_split(split);
	free(split);
}

void	parse_fc(char *line, t_rgb *colors)
{
	char	**split;

	split = split_by_lim(line + 1, " \t\n\v\f\r,");
	colors->r = ft_atoi(split[0]);
	colors->g = ft_atoi(split[1]);
	colors->b = ft_atoi(split[2]);
	free_split(split);
	free(split);
}

void	parse_line(t_game *c, int *phase, char *line)
{
	if (line && (!ft_strncmp(line, "NO", 2) || \
		!ft_strncmp(line, "SO", 2) || !ft_strncmp(line, "WE", 2) \
		|| !ft_strncmp(line, "EA", 2)))
	{
		if (!ft_strncmp(line, "NO", 2))
			parse_directions(line, &c->textures->north->relative_path, \
					&c->textures->north->fd);
		else if (!ft_strncmp(line, "SO", 2))
			parse_directions(line, &c->textures->south->relative_path, \
					&c->textures->south->fd);
		else if (!ft_strncmp(line, "WE", 2))
			parse_directions(line, &c->textures->west->relative_path, \
					&c->textures->west->fd);
		else if (!ft_strncmp(line, "EA", 2))
			parse_directions(line, &c->textures->east->relative_path, \
					&c->textures->east->fd);
	}
	else if (line && line[0] == 'F')
		parse_fc(line, c->floor);
	else if (line && line[0] == 'C')
		parse_fc(line, c->ceiling);
	else
		*phase = MAP;
}

void	parser_ex(t_game *game, char *line, int fd, int *phase)
{
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line = rm_newline_trim(line);
		if (line && line[0])
			parse_line(game, phase, line);
		if (*phase == MAP)
		{
			parse_map(game, line, fd);
			break ;
		}
		if (line)
			free(line);
	}
}

int	parser(t_game *game)
{
	char	*line;
	char	*keep;
	int		fd;
	char	*map_name;
	int		phase;

	phase = -1;
	map_name = game->map_file;
	fd = open_file(map_name);
	if (!is_map_valid(map_name))
		return (0);
	parser_ex(game, line, fd, &phase);
	close(fd);
	set_player_data(game, game->map);
	return (1);
}
