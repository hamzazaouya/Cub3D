/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:00:49 by hazaouya          #+#    #+#             */
/*   Updated: 2023/01/18 10:38:29 by hazaouya         ###   ########.fr       */
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

void	drow_minimap_fov(t_game *game, double angle)
{
	double			xstep;
	double			ystep;
	double			i;
	double			j;
	unsigned int	*dst;

	xstep = cos(angle);
	ystep = sin(angle);
	i = RAY;
	j = RAY;
	while (1)
	{
		dst = (unsigned int *)(game->mlx->img->addr + \
			((int)j * game->mlx->img->line_length + (int)i * \
			(game->mlx->img->bits_per_pixel / 8)));
		if (*dst == 0xFF0000 || *dst == 0x0000FF)
			return ;
		my_mlx_pixel_put(game->mlx->img, i, j, 0x000000);
		i += xstep;
		j += ystep;
	}
}

void	minimap_fov(t_game *game)
{
	double	start_angle;
	double	end_angle;
	double	step;

	start_angle = game->angle - (FOV / 2);
	end_angle = game->angle + (FOV / 2);
	step = FOV / (WIDTH / 30);
	while (start_angle < end_angle)
	{
		drow_minimap_fov(game, start_angle);
		start_angle += step;
	}
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
				if (ft_pow(j - RAY) + ft_pow(i - RAY) \
						>= ft_pow(RAY) - RAY * 5 && \
					ft_pow(j - RAY) + ft_pow(i - RAY) <= ft_pow(RAY))
					my_mlx_pixel_put(game->mlx->img, j, i, 0x0000FF);
			}
			j++;
		}
		i++;
	}
	minimap_fov(game);
}
