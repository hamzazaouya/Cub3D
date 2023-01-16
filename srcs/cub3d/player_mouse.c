/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:13:41 by hazaouya          #+#    #+#             */
/*   Updated: 2023/01/16 12:51:52 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/header3D.h"

void	mouse_check_one(t_game *game, int x)
{
	game->mouse_rot = R_ANGLE;
	if (inclusive(800, 900, x))
		game->k = 0.02;
	else if (inclusive(900, 1000, x))
		game->k = 0.03;
	else if (inclusive(1000, 1100, x))
		game->k = 0.04;
	else
		game->k = 0.05;
	game->mouse = 1;
}

void	mouse_check(t_game *game, int x, int y)
{
	if (inclusive(0, WIDTH - 1, x) && inclusive(0, HEIGHT - 1, y) && \
				!inclusive(400, 800, x))
	{
		if (x >= 800 && !game->mouse)
			mouse_check_one(game, x);
		else if (!game->mouse)
		{
			if (inclusive(300, 400, x))
				game->k = -0.02;
			else if (inclusive(200, 300, x))
				game->k = -0.03;
			else if (inclusive(100, 200, x))
				game->k = -0.04;
			else
				game->k = -0.05;
			game->mouse_rot = L_ANGLE ;
			game->mouse = 1;
		}
	}
	else
	{
		game->mouse_rot = -1;
		game->k = 0;
		game->mouse = 0;
	}
}

int	mouse(int x, int y, t_game *game)
{
	if (window_valid(x, y))
	{
		game->mouse_x = x;
		game->mouse_y = y;
	}
	if (!game->mouse_flag)
	{
		game->k = 0;
		game->mouse = 0;
		game->mouse_x = x;
		game->mouse_y = y;
		game->mouse_flag = 1;
	}
	else
		mouse_check(game, x, y);
	return (0);
}

void	rotate_mouse(t_game *game)
{
	if (game->mouse_rot == R_ANGLE || game->mouse_rot == L_ANGLE)
	{
		game->angle += game->k;
		normalize_angle1(game);
	}
}
