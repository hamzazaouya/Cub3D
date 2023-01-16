/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:00:49 by hazaouya          #+#    #+#             */
/*   Updated: 2023/01/16 15:14:47 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/header3D.h"

void	drow_minimap(t_game *game, int i, int j)
{
	float	x;
	float	y;

	y = game->player.y - (RAY * ZOOM) + i;
	x = game->player.x - (RAY * ZOOM) + j;
	x = x / game->width_by_map;
	y = y / game->height_by_map;
	if (window_valid(j / ZOOM, i / ZOOM))
	{
		if ((inclusive(0, game->width - 1, (int) x) && \
			inclusive(0, game->height - 1, (int) y) && \
			game->map[(int) y][(int) x] == '1'))
			my_mlx_pixel_put(game->mlx->img, j / ZOOM, i / ZOOM, 0xFF0000);
		else if ((inclusive(0, game->width - 1, (int) x) \
			&& inclusive(0, game->height - 1, (int) y) && \
			game->map[(int) y][(int) x] == '0'))
			my_mlx_pixel_put(game->mlx->img, j / ZOOM, i / ZOOM, 0xFFFFFF);
		else if ((inclusive(0, game->width - 1, (int) x) \
			&& inclusive(0, game->height - 1, (int) y) && \
			is_player(game->map[(int) y][(int) x])))
			my_mlx_pixel_put(game->mlx->img, j / ZOOM, i / ZOOM, 0xFFFFFF);
		else
			my_mlx_pixel_put(game->mlx->img, j / ZOOM, i / ZOOM, 0x808080);
	}
}

int	ft_pow(int x)
{
	return (x * x);
}

void	minimap(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < DIAMETRE)
	{
		j = 0;
		while (j < DIAMETRE)
		{
			if (window_valid(i, j))
			{
				if (ft_pow(j - RAY) + ft_pow(i - RAY) <= ft_pow(RAY))
					drow_minimap(game, i * ZOOM, j * ZOOM);
				if (i == RAY || j == RAY)
					my_mlx_pixel_put(game->mlx->img, j, i, 0x00FF7F);
				if (ft_pow(j - RAY) + ft_pow(i - RAY) >= ft_pow(RAY) - 1000 && \
					ft_pow(j - RAY) + ft_pow(i - RAY) <= ft_pow(RAY))
					my_mlx_pixel_put(game->mlx->img, j, i, 0x000000);
			}
			j++;
		}
		i++;
	}
}
