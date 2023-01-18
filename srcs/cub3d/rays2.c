#include "../../incs/header3D.h"

double	length(t_ray *ray)
{
	double	len;
	double	xsize;
	double	ysize;

	xsize = pow2((ray->x_end - ray->x_origin));
	ysize = pow2((ray->y_end - ray->y_origin));
	len = sqrt(xsize + ysize);
	return (len);
}

double	magnitude(double x, double y, double endx, double endy)
{
	double	len;
	double	xsize;
	double	ysize;

	xsize = pow2((endx - x));
	ysize = pow2((endy - y));
	len = sqrt(xsize + ysize);
	return (len);
}

double	get_y_distance(t_game *game, t_ray *r, double xs, double ys)
{
	double	x;
	double	y;
	int		xp;
	int		yp;

	x = game->player.x;
	y = game->player.y;
	xp = x / game->width_by_map;
	yp = y / game->height_by_map;
	while (inclusive(0, (game->height - 1), yp) && \
			inclusive(0, (game->width - 1), xp) && \
			game->map[yp][xp] != '1')
	{
		y += ys;
		yp = y / game->height_by_map;
		if (game->map[yp][xp] == '1')
			break ;
		x += xs;
		xp = x / game->width_by_map;
	}
	r->x_end = roundf(x);
	r->y_end = roundf(y);
	return (magnitude(game->player.x, game->player.y, x, y));
}

double	get_x_distance(t_game *game, t_ray *r, double xs, double ys)
{
	double	x;
	double	y;
	int		xp;
	int		yp;

	x = game->player.x;
	y = game->player.y ;
	xp = x / game->width_by_map;
	yp = y / game->height_by_map;
	while (inclusive(0, (game->height - 1), yp) && \
			inclusive(0, (game->width - 1), xp) && \
			game->map[yp][xp] != '1')
	{
		x += xs;
		xp = x / game->width_by_map;
		if (game->map[yp][xp] == '1')
			break ;
		y += ys ;
		yp = y / game->height_by_map;
	}
	r->x_end = roundf(x);
	r->y_end = roundf(y);
	return (magnitude(game->player.x, game->player.y, x, y));
}
