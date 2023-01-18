#include "../../incs/header3D.h"

void	init_ray_textures(t_game *game, t_ray *ray)
{
	if (ray->texture_type == WEST)
		ray->texture = game->textures->west;
	else if (ray->texture_type == EAST)
		ray->texture = game->textures->east;
	else if (ray->texture_type == NORTH)
		ray->texture = game->textures->north;
	else if (ray->texture_type == SOUTH)
		ray->texture = game->textures->south;
}

t_ray	*prepare_ray(t_game *game, double angle, int col)
{
	double	xstep;
	double	ystep;
	double	x;
	double	y;
	t_ray	*res;

	res = alloc(sizeof(t_ray));
	res->angle = angle;
	xstep = cos(angle);
	ystep = sin(angle);
	res->distance = where_ray_hit(game, res, xstep, ystep);
	init_ray_textures(game, res);
	res->x_origin = game->player.x;
	res->y_origin = game->player.y;
	res->col = col;
	return (res);
}

void	draw_ry(t_game *game, double angle, int col)
{
	t_ray	*ray;

	ray = prepare_ray(game, angle, col);
	ray->distance = roundf(ray->distance);
	if (ray->distance > 0.001)
		ray->wall_height = wallHeight((ray->distance));
	else
		ray->wall_height = 0;
	draw_3dwall(game, ray);
	free(ray);
}

void	shoot_rays(t_game *game)
{
	char	**map;
	double	start_angle;
	double	end_angle;
	double	step;
	int		col;

	start_angle = game->angle - (FOV / 2);
	end_angle = game->angle + (FOV / 2);
	step = FOV / WIDTH;
	col = 0;
	while (start_angle < end_angle)
	{
		draw_ry(game, start_angle, col);
		start_angle += step;
		col++;
	}
}
