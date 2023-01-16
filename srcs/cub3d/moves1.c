/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:49:50 by hazaouya          #+#    #+#             */
/*   Updated: 2023/01/16 17:18:08 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/header3D.h"

void	init_moves_right(t_game *game, t_moves *data)
{
	data->angle = game->angle + M_PI_2;
	data->angle = get_normalized_angle(data->angle);
	data->after_move_x = game->player.x + (game->movex * cos(data->angle));
	data->after_move_y = game->player.y + (game->movey * sin(data->angle));
	data->ay = data->after_move_y / game->height_by_map;
	data->ax = data->after_move_x / game->width_by_map;
}

void	init_moves_left(t_game *game, t_moves *data)
{
	data->angle = game->angle - M_PI_2;
	data->angle = get_normalized_angle(data->angle);
	data->after_move_x = game->player.x + (game->movex * cos(data->angle));
	data->after_move_y = game->player.y + (game->movey * sin(data->angle));
	data->ay = data->after_move_y / game->height_by_map;
	data->ax = data->after_move_x / game->width_by_map;
}

void	init_moves_down(t_game *game, t_moves *data)
{
	data->angle = game->angle + M_PI;
	data->angle = get_normalized_angle(data->angle);
	data->after_move_x = game->player.x + (game->movex * cos(data->angle));
	data->after_move_y = game->player.y + (game->movey * sin(data->angle));
	data->ay = data->after_move_y / game->height_by_map;
	data->ax = data->after_move_x / game->width_by_map;
}
