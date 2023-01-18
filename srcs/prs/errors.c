/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:30:57 by hazaouya          #+#    #+#             */
/*   Updated: 2023/01/17 11:32:45 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ft_putstr_fd(int fd, const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	open_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("%s\n", filename);
		error(OPEN_ERROR);
	}
	return (fd);
}

void	*alloc(size_t size)
{
	void	*p;

	p = malloc(size);
	if (!p)
		error(MALLOC_ERROR);
	return (p);
}

void	error(const char *s)
{
	ft_putstr_fd(2, s);
	exit(EXIT_FAILURE);
}
