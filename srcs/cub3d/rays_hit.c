/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:31:28 by hazaouya          #+#    #+#             */
/*   Updated: 2023/01/16 13:55:04 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/header3D.h"

void	set_vars(t_game *game, double *xy, int *xpyp, int *oldxpyp)
{
	xy[0] = game->player.x;
	xy[1] = game->player.y;
	xpyp[0] = xy[0] / game->width_by_map;
	xpyp[1] = xy[1] / game->height_by_map;
}

int	is_hit(t_game *game, double *xy, int *xpyp, int *oldxpyp)
{
	if (inclusive(0, (game->height - 1), xpyp[1]) && \
		inclusive(0, (game->width - 1), oldxpyp[0]) && \
		game->map[xpyp[1]][oldxpyp[0]] == '1')
		return (1);
	else if (inclusive(0, (game->height - 1), oldxpyp[1]) && \
			inclusive(0, (game->width - 1), xpyp[0]) && \
			game->map[oldxpyp[1]][xpyp[0]] == '1')
		return (0);
	else if (inclusive(0, (game->height - 1), xpyp[1]) && \
			inclusive(0, (game->width - 1), xpyp[0]) && \
			game->map[xpyp[1]][xpyp[0]] == '1')
		return (0);
	else
		return (-1);
}

int	where_ray_hits1(t_game *game, t_ray *r, double xs, double ys)
{
	double	xy[2];
	int		xpyp[2];
	int		oldxpyp[2];

	set_vars(game, xy, xpyp, oldxpyp);
	while (inclusive(0, (game->height - 1), xpyp[1]) && \
			inclusive(0, (game->width - 1), xpyp[0]) && \
			game->map[xpyp[1]][xpyp[0]] != '1')
	{
		xpyp[0] = xy[0] / game->width_by_map;
		xpyp[1] = xy[1] / game->height_by_map;
		xy[0] += xs;
		xy[1] += ys;
		oldxpyp[0] = xpyp[0];
		oldxpyp[1] = xpyp[1];
		xpyp[0] = xy[0] / game->width_by_map;
		xpyp[1] = xy[1] / game->height_by_map;
		if (is_hit(game, xy, xpyp, oldxpyp) != -1)
			return (is_hit(game, xy, xpyp, oldxpyp));
	}
	return (0);
}

double	where_ray_hit(t_game *game, t_ray *r, double xs, double ys)
{
	r->distance = INT_MAX;
	r->x_end = game->player.x;
	r->y_end = game->player.y;
	if (where_ray_hits1(game, r, xs, ys))
	{
		if (isUp(r->angle))
			r->texture_type = NORTH;
		else
			r->texture_type = SOUTH;
		return (get_y_distance(game, r, xs, ys));
	}
	else
	{
		if (isRight(r->angle))
			r->texture_type = EAST;
		else
			r->texture_type = WEST;
		return (get_x_distance(game, r, xs, ys));
	}
	return (INT_MAX);
}
