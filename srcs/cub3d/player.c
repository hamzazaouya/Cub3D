#include "../../incs/header3D.h"

void	player_put_image(t_game *game, int i)
{
	if (i)
	{
		mlx_put_image_to_window(game->mlx->init, \
			game->mlx->win, game->mlx->img->img, 0, 0);
	}
	else
	{
		mlx_put_image_to_window(game->mlx->init, game->mlx->win, \
		game->p->assets[game->p->current].img, WIDTH / 2 - \
		game->p->assets[game->p->current].img_width / 2, HEIGHT - \
		game->p->assets[game->p->current].img_height + 250);
	}
}

int	render_player(t_game *game)
{
	int	last ;

	rotate_mouse(game);
	shoot_rays(game);
	last = game->p->last;
	minimap(game);
	player_put_image(game, 1);
	if (game->p->last != UNDEFINED)
	{
		mlx_destroy_image(game->mlx->init, game->p->assets[last].img);
		game->p->assets[last].img = mlx_xpm_file_to_image(game->mlx->init, \
		game->p->assets[last].relative_path, &game->p->assets[last].img_width, \
		&game->p->assets[last].img_height);
		game->p->assets[last].addr = \
		mlx_get_data_addr(game->p->assets[last].img, \
		&game->p->assets->bits_per_pixel, \
		&game->p->assets[last].line_length, &game->p->assets[last].endian);
	}
	game->p->last = game->p->current;
	player_put_image(game, 0);
	game->p->current++;
	usleep(10000);
	game->p->current %= game->p->frames;
	return (0);
}
