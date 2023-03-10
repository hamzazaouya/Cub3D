/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:37:17 by hazaouya          #+#    #+#             */
/*   Updated: 2023/01/17 11:38:35 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*slice(const char *s, int start, int end)
{
	int		len;
	int		i;
	char	*res;

	if (end <= start)
		return (NULL);
	len = end - start;
	res = (char *) alloc((len + 1) * sizeof(char));
	res[len] = 0;
	i = 0;
	while (start < end)
		res[i++] = s[start++];
	return (res);
}
