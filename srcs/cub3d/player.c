#include "../../incs/header3D.h"

int mouse(int x, int y, t_game *game)
{
    if (window_valid(x, y))
    {
        game->mouse_x = x ;
        game->mouse_y = y ;
    }
    if (!game->mouse_flag)
    {
        game->k = 0 ;
        game->mouse = 0 ;
        game->mouse_x = x ;
        game->mouse_y = y ;
        game->mouse_flag = 1 ;
    }
    else
    {
        if (inclusive(0, WIDTH-1, x) && inclusive(0, HEIGHT-1, y) && !inclusive(400, 800, x))
        {
            if (x >= 800 && !game->mouse)
            {
                game->mouse_rot = R_ANGLE ;
                if (inclusive(800, 900, x))
                    game->k = 0.02 ;
                else if (inclusive(900, 1000, x))
                    game->k = 0.03 ;
                else if (inclusive(1000, 1100, x))
                    game->k = 0.04 ;
                else
                    game->k = 0.05 ;
                game->mouse = 1 ;
            }
            else if (!game->mouse)
            {
                if (inclusive(300, 400, x))
                    game->k = -0.02 ;
                else if (inclusive(200, 300, x))
                    game->k = -0.03 ;
                else if (inclusive(100, 200, x))
                    game->k = -0.04 ;
                else
                    game->k = -0.05 ;
                game->mouse_rot = L_ANGLE ;
                game->mouse = 1 ;
            }
        }
        else
        {
            game->mouse_rot = -1 ;
            game->k = 0 ;
            game->mouse = 0 ;
        }
    }
    return (0) ;
}


void rotate_mouse(t_game *game)
{
    if (game->mouse_rot == R_ANGLE || game->mouse_rot == L_ANGLE)
    {
        game->angle += game->k ;
        normalize_angle1(game) ;
    }
}

int render_player(t_game *game)
{
    int last ;

    rotate_mouse(game) ;
    shoot_rays(game) ;
    last = game->p->last ;
    minimap(game) ;
    mlx_put_image_to_window(game->mlx->init, game->mlx->win, game->mlx->img->img, 0, 0) ;
    if (game->p->last != UNDEFINED)
    {
        mlx_destroy_image(game->mlx->init, game->p->assets[last].img) ;
        game->p->assets[last].img = mlx_xpm_file_to_image(game->mlx->init, game->p->assets[last].relative_path, &game->p->assets[last].img_width, &game->p->assets[last].img_height) ;
        game->p->assets[last].addr = mlx_get_data_addr(game->p->assets[last].img, &game->p->assets->bits_per_pixel, \
        &game->p->assets[last].line_length, &game->p->assets[last].endian) ;
    }
    game->p->last = game->p->current;
    mlx_put_image_to_window(game->mlx->init, game->mlx->win, game->p->assets[game->p->current].img, WIDTH / 2 - game->p->assets[game->p->current].img_width / 2, HEIGHT - game->p->assets[game->p->current].img_height + 250) ;
    game->p->current++ ;
    usleep(10000) ;
    game->p->current %= game->p->frames ;
    return (0) ;
}