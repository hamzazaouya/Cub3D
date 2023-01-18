/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:57:38 by hazaouya          #+#    #+#             */
/*   Updated: 2023/01/17 12:00:57 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_extension_valid(const char *file, char *ext)
{
	int	fi;
	int	ei;

	fi = ft_strlen(file) - 1;
	ei = ft_strlen(ext) - 1;
	while (fi >= 0 && ei >= 0)
	{
		if (file[fi] != ext[ei])
			return (0);
		fi--;
		ei--;
	}
	return (1);
}

char	**get_map(t_mq *head)
{
	int		q_size;
	int		i;
	char	**map ;

	q_size = mq_size(head);
	map = (char **) alloc((q_size + 1) * sizeof(char *));
	map[q_size] = NULL;
	i = 0;
	while (head && i < q_size)
	{
		map[i] = ft_strdup(head->line);
		i++;
		head = head->next;
	}
	return (map);
}

int	get_map_width(char **map)
{
	int	i;
	int	width;
	int	len ;

	width = INT_MIN;
	i = -1;
	while (map[++i])
	{
		len = ft_strlen(map[i]);
		width = max(width, len);
	}
	return (width);
}

int	get_map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	normalize_map_width(char **map, int width)
{
	char	*k;
	int		i;
	int		j;

	i = -1;
	while (map[++i])
	{
		k = alloc((width + 1) * sizeof(char));
		k[width] = 0;
		j = -1;
		while (map[i][++j] && j < width)
			k[j] = map[i][j];
		while (j < width)
			k[j++] = '1';
		free(map[i]);
		map[i] = k;
	}
}
