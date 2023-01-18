/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:01:59 by hazaouya          #+#    #+#             */
/*   Updated: 2023/01/17 12:05:31 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <math.h>

void	set_player_data(t_game *game, char **map)
{
	int		i;
	int		j;
	int		isfound;
	t_pos	*p;

	p = &game->player;
	isfound = 0;
	i = -1;
	while (map[++i] && !isfound)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'W' || map[i][j] == 'E' \
					|| map[i][j] == 'S' || map[i][j] == 'N')
			{
				p->x = j;
				p->y = i;
				isfound = 1;
				if (map[i][j] == 'W')
					game->angle = -M_PI_2;
				else if (map[i][j] == 'S')
					game->angle = M_PI_2;
				else if (map[i][j] == 'W')
					game->angle = -M_PI;
				else
					game->angle = 0;
				break ;
			}
			j++;
		}
	}
}

int	valid_map(t_game *c)
{
	int		i;
	int		j;
	char	**map;

	map = c->map;
	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (((i == 0 || i == c->width - 1) || \
				(j == c->width - 1) || (j == 0)) && map[i][j] != '1')
			{
				return (0);
			}
			j++;
		}
	}
	return (1);
}
