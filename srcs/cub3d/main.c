#include "../../incs/header3D.h"

void	init_mlx(t_game *game)
{
	game->mlx = (t_mlx *) malloc (sizeof(t_mlx));
	game->mlx->img = (t_data *) malloc(sizeof(t_data));
	game->mlx->init = mlx_init();
	game->mlx->win = mlx_new_window(game->mlx->init, WIDTH, HEIGHT, "3D");
	game->mlx->img->img = mlx_new_image(game->mlx->init, WIDTH, HEIGHT);
	game->mlx->img->addr = mlx_get_data_addr(game->mlx->img->img, \
		&game->mlx->img->bits_per_pixel, \
		&game->mlx->img->line_length, &game->mlx->img->endian);
	game->tilex = CUBE_SIZE;
	game->tiley = CUBE_SIZE;
	game->width_by_map = (double) WIDTH / game->width;
	game->height_by_map = (double) HEIGHT / game->height;
	game->movex = min(game->width_by_map, game->height_by_map) / 8;
	game->movey = game->movex;
	game->player.x = game->player.x * game->width_by_map \
		+ game->width_by_map / 2;
	game->player.y = game->player.y * game->height_by_map + \
		game->height_by_map / 2;
}

void	cub3d(t_game *game)
{
	init_mlx(game);
	init_animations(game);
	init_textures(game);
	mlx_hook(game->mlx->win, 2, 1L << 0, actions, game);
	mlx_hook(game->mlx->win, MOUSE_MOVE_EVENT, 0, mouse, game);
	actions(0, game);
	mlx_put_image_to_window(game->mlx->init, \
		game->mlx->win, game->mlx->img->img, 0, 0);
	mlx_loop_hook(game->mlx->init, render_player, game);
	mlx_hook(game->mlx->win, 17, 0, exit_cub3d, game);
	mlx_loop(game->mlx->init);
}

int	main(int ac, char **av)
{
	t_game	*game ;

	if (ac != 2)
		error(ARGS_ERROR);
	game = init_game(av[1]);
	if (!parser(game))
		return (1);
	cub3d(game);
}
