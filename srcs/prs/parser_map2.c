/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:09:51 by hazaouya          #+#    #+#             */
/*   Updated: 2023/01/18 10:25:24 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_edges(char **map, int width, int height)
{
	int		i;
	int		j;
	int		len;
	char	*s;

	i = -1;
	while (map[++i])
	{
		j = -1 ;
		s = ft_strtrim(map[i]);
		if (s)
			len = (int) ft_strlen(s);
		while (s && s[++j])
		{
			if ((i == height - 1 || i == 0 || j == len - 1 \
					|| j == 0) && s[j] != '1')
			{
				free(s);
				return (0);
			}
		}
		if (s)
			free(s);
	}
	return (1);
}
