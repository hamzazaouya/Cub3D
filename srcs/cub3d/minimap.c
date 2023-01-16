#include "../../incs/header3D.h"

# define RAY 100
# define DIAMETRE RAY * 2
# define ZOOM 4

# define is_player(c) (c == 'W' || c == 'N' || c == 'E' || c == 'S')


void drow_minimap(t_game *game, int i, int j)
{
    float x = game->player.x - (RAY * ZOOM) + j;
    float y = game->player.y - (RAY * ZOOM) + i;

    x = x / game->width_by_map;
    y = y / game->height_by_map;
    if (window_valid(j / ZOOM, i / ZOOM))
    {
        // if(x > WIDTH || y > HEIGHT || x < 0 || y < 0)
        //     my_mlx_pixel_put(game->mlx->img, j / ZOOM, i / ZOOM, 0x00FF00);
        if((inclusive(0,game->width-1,(int)x) && inclusive(0,game->height-1,(int)y) && game->map[(int)y][(int)x] == '1'))
            my_mlx_pixel_put(game->mlx->img, j / ZOOM, i / ZOOM, 0xFF0000);
        else if ((inclusive(0,game->width-1,(int)x) && inclusive(0,game->height-1,(int)y) && game->map[(int)y][(int)x] == '0'))
            my_mlx_pixel_put(game->mlx->img, j / ZOOM, i / ZOOM, 0xFFFFFF) ;
        else if ((inclusive(0,game->width-1,(int)x) && inclusive(0,game->height-1,(int)y) && is_player(game->map[(int)y][(int)x])))
            my_mlx_pixel_put(game->mlx->img, j / ZOOM, i / ZOOM, 0xFFFFFF) ;
        else
            my_mlx_pixel_put(game->mlx->img, j / ZOOM, i / ZOOM, 0x808080);
    }
}

int ft_pow(int x)
{
    return (x * x);
}

void minimap(t_game *game)
{
    int i = 0;
    int j;

    while(i < DIAMETRE )
    {
        j = 0;
        while(j < DIAMETRE )
        {
            if (window_valid(i, j))
            {
                if(ft_pow(j - RAY) + ft_pow(i - RAY) <= ft_pow(RAY))
                    drow_minimap(game, i * ZOOM, j * ZOOM);
                if(i == RAY || j == RAY)
                    my_mlx_pixel_put(game->mlx->img, j, i, 0x00FF7F);
                if(ft_pow(j - RAY) + ft_pow(i - RAY) >= ft_pow(RAY) - 1000 && ft_pow(j - RAY) + ft_pow(i - RAY) <= ft_pow(RAY))
                    my_mlx_pixel_put(game->mlx->img, j, i, 0x000000);
            }
            j++;
        }
        i++;
    }
}
