#include "../../incs/header3D.h"

void    init_animations(t_game *game)
{
    int i;
    char    *num ;
    char    *keep ;
    const char    *PLAYER_PATH ;

    game->p = (t_anim *) malloc(sizeof(t_anim)) ;
    game->p->isdone = 1 ;
    game->p->frames = 147;
    game->p->current = 0 ;
    game->p->assets = (t_asset *) malloc(game->p->frames * sizeof(t_asset)) ;
    game->p->last = UNDEFINED ;
    i = -1 ;
    PLAYER_PATH = "assets/player/" ;
    while (++i < game->p->frames)
    {
        num = ft_itoa(i + 1) ;
        game->p->assets[i].relative_path = ft_strjoin(num, ".xpm") ;
        keep = game->p->assets[i].relative_path ;
        game->p->assets[i].relative_path = ft_strjoin(PLAYER_PATH, keep) ;
        free(keep) ;
        free(num) ;
        game->p->assets[i].img = mlx_xpm_file_to_image(game->mlx->init, game->p->assets[i].relative_path, \
        &game->p->assets[i].img_width, &game->p->assets[i].img_height) ;
        if (!game->p->assets[i].img)
            error("TEXTURE FILE ERROR\n") ;
        game->p->assets[i].addr = mlx_get_data_addr(game->p->assets[i].img, &game->p->assets->bits_per_pixel, &game->p->assets->line_length, &game->p->assets->endian) ;
    }
}

void    simplify_colors(t_game *game)
{
    unsigned char *byte ;

    if (!is_color_valid(game->floor->b) || !is_color_valid(game->floor->g) || !is_color_valid(game->floor->b) \
    || !is_color_valid(game->ceiling->r) || !is_color_valid(game->ceiling->g) || !is_color_valid(game->ceiling->b))
        error(COLOR_NOT_VALID_ERR) ;
    byte = (unsigned char *) &game->floor->color ;
    *(byte) = (unsigned char) game->floor->b ;
    *(byte + 1) = (unsigned char) game->floor->g ;
    *(byte + 2) = (unsigned char) game->floor->r ;
    *(byte + 3) = 0 ;
    byte = (unsigned char *) &game->ceiling->color ;
    *(byte) = (unsigned char ) game->ceiling->b ;
    *(byte + 1) = (unsigned char ) game->ceiling->g ;
    *(byte + 2) = (unsigned char ) game->ceiling->r ;
    *(byte + 3) = 0 ;
}

void    init_textures(t_game *game)
{
    game->textures->east->img = mlx_xpm_file_to_image(game->mlx->init, game->textures->east->relative_path, \
    &game->textures->east->img_width, &game->textures->east->img_height) ;
    game->textures->east->addr = mlx_get_data_addr(game->textures->east->img, &game->textures->east->bits_per_pixel, \
    &game->textures->east->line_length, &game->textures->east->endian) ;
    game->textures->west->img = mlx_xpm_file_to_image(game->mlx->init, game->textures->west->relative_path, \
    &game->textures->west->img_width, &game->textures->west->img_height) ;
    game->textures->west->addr = mlx_get_data_addr(game->textures->west->img, &game->textures->west->bits_per_pixel, \
    &game->textures->west->line_length, &game->textures->west->endian) ;
    game->textures->north->img = mlx_xpm_file_to_image(game->mlx->init, game->textures->north->relative_path, \
    &game->textures->north->img_width, &game->textures->north->img_height) ;
    game->textures->north->addr = mlx_get_data_addr(game->textures->north->img, &game->textures->north->bits_per_pixel, \
    &game->textures->north->line_length, &game->textures->north->endian) ;
    game->textures->south->img = mlx_xpm_file_to_image(game->mlx->init, game->textures->south->relative_path, \
    &game->textures->south->img_width, &game->textures->south->img_height) ;
    game->textures->south->addr = mlx_get_data_addr(game->textures->south->img, &game->textures->south->bits_per_pixel, \
    &game->textures->south->line_length, &game->textures->south->endian) ;
    simplify_colors(game) ;

}

t_game*    init_game(char *map_file)
{
    t_game *game;

    game = (t_game *) malloc (sizeof(t_game)) ;
    game->map_file = ft_strdup(map_file) ;
    game->fov = FOV ;
    game->angle = M_PI / 2 ;
    game->floor = (t_rgb *) malloc(sizeof(t_rgb)) ;
    game->ceiling = (t_rgb *) malloc(sizeof(t_rgb)) ;
    game->textures = (t_textures *) malloc (sizeof(t_textures)) ;
    game->textures->east = (t_asset *) malloc(sizeof(t_asset)) ;
    game->textures->north = (t_asset *) malloc(sizeof(t_asset)) ;
    game->textures->south = (t_asset *) malloc(sizeof(t_asset)) ;
    game->textures->west = (t_asset *) malloc(sizeof(t_asset)) ;
    return (game) ;
}

void    init_mlx(t_game *game)
{
    game->mlx = (t_mlx *) malloc (sizeof(t_mlx)) ;
    game->mlx->img = (t_data *) malloc(sizeof(t_data)) ;
    game->mlx->init = mlx_init() ;
    game->mlx->win = mlx_new_window(game->mlx->init, WIDTH, HEIGHT, "3D") ;
    game->mlx->img->img = mlx_new_image(game->mlx->init, WIDTH, HEIGHT) ;
    game->mlx->img->addr = mlx_get_data_addr(game->mlx->img->img, &game->mlx->img->bits_per_pixel, \
    &game->mlx->img->line_length, &game->mlx->img->endian);
    game->tilex = CUBE_SIZE ;
    game->tiley = CUBE_SIZE ;
}

int main(int ac, char **av)
{
    t_game *game ;

    if (ac != 2)
        error(ARGS_ERROR) ;
    game = init_game(av[1]) ;
    if (!parser(game))
        return (1) ;
    init_mlx(game) ;
    init_animations(game) ;
    init_textures(game) ;
    game->width_by_map = (double) WIDTH / game->width ;
    game->height_by_map = (double) HEIGHT / game->height ;
    game->movex = min(game->width_by_map, game->height_by_map) / 8 ;
    game->movey = game->movex ;
    game->player.x = game->player.x * game->width_by_map + game->width_by_map / 2;
    game->player.y = game->player.y * game->height_by_map + game->height_by_map / 2;
    mlx_hook(game->mlx->win, 2, 1L << 0, actions, game);
    mlx_hook(game->mlx->win, MOUSE_MOVE_EVENT, 0, mouse, game) ;
    actions(0, game) ;
	mlx_put_image_to_window(game->mlx->init, game->mlx->win, game->mlx->img->img, 0, 0);
    mlx_loop_hook(game->mlx->init, render_player, game) ;
    mlx_hook(game->mlx->win, 17, 0, exit_cub3d, game) ;
	mlx_loop(game->mlx->init) ;
 }