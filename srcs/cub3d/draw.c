#include "../../incs/header3D.h"

void	draw_ceiling(t_game *game, int ceil, int col)
{
	int	y;

	y = 0;
	while (y < ceil)
	{
		if (window_valid(col, y))
			my_mlx_pixel_put(game->mlx->img, col, y, game->ceiling->color);
		y++;
	}
}

void	draw_scene_wall(t_game *game, t_ray *ray, int y, int rdist, double k)
{
	double	yto;

	yto = 0;
	while (rdist >= 0)
	{
		if (window_valid(ray->col, y))
		{
			if (ray->texture_type == NORTH || ray->texture_type == SOUTH)
				my_mlx_pixel_put(game->mlx->img, ray->col, y, \
				get_color_from_texture(game, ray, (int)(roundf(yto)) \
				% CUBE_SIZE, (int)(ray->x_end) % CUBE_SIZE));
			else
				my_mlx_pixel_put(game->mlx->img, ray->col, y, \
				get_color_from_texture(game, ray, (int)(roundf(yto)) \
				% CUBE_SIZE, (int)(ray->y_end) % CUBE_SIZE));
		}
		yto += k;
		y++;
		rdist--;
	}
}

void	draw_floor(t_game *game, t_ray *ray, int y)
{
	while (y < HEIGHT)
	{
		if (window_valid(ray->col, y))
			my_mlx_pixel_put(game->mlx->img, ray->col, y, game->floor->color);
		y++;
	}
}

void	draw_3dline(t_game *game, t_ray *ray)
{
	int		rdist;
	double	k;
	double	c;

	rdist = fabs(roundf(ray->wall_height)) - 4;
	k = (((double)CUBE_SIZE / rdist));
	c = (int)roundf((HEIGHT - rdist) / 2) + 4;
	if (ray->distance > 0.001)
	{
		draw_ceiling(game, (int)c, ray->col);
		draw_scene_wall(game, ray, c, rdist, k);
		draw_floor(game, ray, c + rdist - 4);
	}
}

void	draw_3dwall(t_game *game, t_ray *ray)
{
	draw_3dline(game, ray);
}
