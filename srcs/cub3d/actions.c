#include "../../incs/header3D.h"

void    do_pressed_key_action(int key, t_game *game)
{
    if (key == RIGHT_KEY)
        move_right(game) ;
    else if (key == LEFT_KEY)
        move_left(game) ;
    else if (key == UP_KEY || key == W_KEY)
        movve(game) ;
    else if (key == DOWN_KEY || key == S_KEY)
        move_down(game) ;
    else if (key == R_ANGLE)
    {
        game->angle += 0.08 ;
        normalize_angle1(game) ;
    }
    else if (key == L_ANGLE)
    {
        game->angle -= 0.08 ;
        normalize_angle1(game) ;
    }
    // else if (key == EXIT_KEY)
    // {
    //     ft_putstr_fd(1, "Thank u for playing our Cub3D\n") ;
    //     exit(EXIT_SUCCESS) ;
    // }
}

int    exit_cub3d(t_game *game)
{
    ft_putstr_fd(1, "Cub3D has been closed successfully!\n") ;
    exit(EXIT_SUCCESS) ; 
}


int actions(int key, t_game *game)
{
    int x = game->player.x ;
    int y = game->player.y ;

    do_pressed_key_action(key, game) ;
    mlx_destroy_image(game->mlx->init, game->mlx->img->img) ;
    game->mlx->img->img = mlx_new_image(game->mlx->init, WIDTH, HEIGHT) ;
    game->mlx->img->addr = mlx_get_data_addr(game->mlx->img->img, &game->mlx->img->bits_per_pixel, \
    &game->mlx->img->line_length, &game->mlx->img->endian);
    render_player(game) ;
    return (0) ;
}