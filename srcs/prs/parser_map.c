/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:09:51 by hazaouya          #+#    #+#             */
/*   Updated: 2023/01/18 09:54:00 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_player_path(char **map, int width, int height, int px, int py)
{
	if (is_space(map[py][px]))
		return (0);
	if ((py >= height || py < 0 || px >= ft_strlen(map[py]) \
		|| px < 0) || map[py][px] == '1')
		return (1);
	if (map[py][px] == '2')
		return (1);
	if (map[py][px] == '0')
		map[py][px] = '2';
	return (check_player_path(map, width, height, px + 1, py) \
		&& check_player_path(map, width, height, px - 1, py) \
		&& check_player_path(map, width, height, px, py + 1) \
		&& check_player_path(map, width, height, px, py - 1));
}

int	is_map_correct(char **map)
{
	int	x;
	int	y;
	int	height;
	int	width;

	x = get_player_x(map);
	y = get_player_y(map);
	if (x == -1 || y == -1)
		return (0);
	height = get_map_height(map);
	width = ft_strlen(map[y]);
	if (inclusive(0, (width - 1), x + 1) && is_space(map[y][x + 1]))
		return (0);
	else if (inclusive(0, (width - 1), x - 1) && is_space(map[y][x - 1]))
		return (0);
	else if (inclusive(0, (height - 1), y - 1) && x < ft_strlen(map[y - 1]) \
			&& is_space(map[y - 1][x]))
		return (0);
	else if (inclusive(0, (height - 1), y + 1) && x < ft_strlen(map[y + 1]) \
			&& is_space(map[y + 1][x]))
		return (0);
	return (1);
}

void	replace_spots(char **map, char c1, char c2)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == c1)
				map[i][j] = c2;
		}
	}
}

int	is_map_works_fine(t_game *c, t_mq *head)
{
	c->map = get_map(head);
	if (!is_map_correct(c->map))
		error(MAP_NOT_VALID_ERROR);
	if (!check_edges(c->map, get_map_width(c->map), get_map_height(c->map)))
		error(MAP_NOT_VALID_ERROR);
	if (!check_player_path(c->map, get_map_width(c->map), \
	get_map_height(c->map), get_player_x(c->map), get_player_y(c->map)))
		error(PLAYER_HAS_PATH_TO_SPACE);
	replace_spots(c->map, '2', '0');
	rm_spaces_from_map(c->map);
	normalize_map_width(c->map, get_map_width(c->map));
	c->width = get_map_width(c->map);
	c->height = get_map_height(c->map);
	return (1);
}

void	parse_map(t_game *c, char *firstline, int fd)
{
	char	*line;
	char	*keep;
	char	*map_line;
	t_mq	*head;

	line = firstline;
	head = NULL;
	while (line)
	{
		line = rm_newline_trim(line);
		if (!line || !line[0])
			error(MAP_NOT_VALID_ERROR);
		map_line = get_map_line(line);
		push(&head, new_mq(map_line));
		if (map_line)
			free(map_line);
		if (line)
			free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	if (is_map_works_fine(c, head))
		free_mq(&head);
}
