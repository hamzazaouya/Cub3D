/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_queue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:38:56 by hazaouya          #+#    #+#             */
/*   Updated: 2023/01/17 11:41:18 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	mq_size(t_mq *head)
{
	if (!head)
		return (0);
	return (1 + mq_size(head->next));
}

t_mq	*new_mq(char *line)
{
	t_mq	*new;

	new = (t_mq *) alloc(sizeof(t_mq));
	new->line = ft_strdup(line);
	new->next = NULL;
	return (new);
}

void	push(t_mq **head, t_mq *new)
{
	t_mq	*node;

	if (!(*head))
	{
		*head = new;
		return ;
	}
	node = *head;
	while (node && node->next)
		node = node->next;
	node->next = new;
}

void	free_mq(t_mq **head)
{
	t_mq	*node;
	t_mq	*prev;

	node = *head;
	while (node)
	{
		prev = node;
		node = node->next;
		free(prev->line);
		free(prev);
	}
	*head = NULL;
}
