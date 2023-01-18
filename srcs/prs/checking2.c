/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:47:41 by hazaouya          #+#    #+#             */
/*   Updated: 2023/01/17 11:30:40 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_floor(const char *line, int *params)
{
	char	**split;
	int		len;
	int		is_valid;

	if (line[0] != 'F')
		return (0);
	line++;
	split = split_by_lim(line, ",");
	len = get_split_len(split);
	is_valid = (len == 3 && count_char(line, ',') == 2 && check_colors(split));
	if (!is_valid)
		error(PARSE_ERROR);
	free_split(split);
	free(split);
	params[F - 1] += 1;
	if (params[F - 1] > 1)
		error(PARSE_ERROR);
	return (is_valid);
}

int	check_ceiling(const char *line, int *params)
{
	char	**split;
	int		len;
	int		is_valid;

	if (line[0] != 'C')
		return (0);
	line++;
	split = split_by_lim(line, ",");
	len = get_split_len(split);
	is_valid = (len == 3 && count_char(line, ',') == 2 && check_colors(split));
	if (!is_valid)
		error(PARSE_ERROR);
	free_split(split);
	free(split);
	params[C - 1] += 1;
	if (params[C - 1] > 1)
		error(PARSE_ERROR);
	return (is_valid);
}
