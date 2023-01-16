#include "../../incs/header3D.h"

void    draw_wall(t_game *game, int x, int y, int sizex, int sizey, int color)
{
    int i = 0 ;
    while (i < sizey)
    {
        int j = 0 ;
        while (j < sizex)
        {
            if (window_valid(x + j, y + i))
                my_mlx_pixel_put(game->mlx->img, x + j, y + i, color) ;
            j++ ;
        }
        i++ ;
    }
}

void    draw_lne(t_game *game, double x, double y, double rx, double ry, int color)
{
    double dx = rx - x ;
    double dy = ry - y ;
    double steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy) ;
    double xsteps = dx / steps ;
    double ysteps = dy / steps ;
    int up = (ry < y) ;
    int right = (rx > x) ;
    while (1)
    {
        if (window_valid((int)x, (int)y))
            my_mlx_pixel_put(game->mlx->img, (int)x, (int)y, color) ;
        y += ysteps ;
        x += xsteps ;
        if ((up && y <= ry) || (!up && y >= ry))
            break ;
        if ((right && x >= rx) || (!right && x <= rx))
            break ;
    }
}

void    draw_circle(t_game *game, double x, double y, int r)
{
    double angle = 0.0 ;
    double rx = cos(angle) * r ;
    double ry = sin(angle) * r ;
    while (angle < 2*M_PI)
    {
        rx = cos(angle) * r ;
        ry = sin(angle) * r ;
        draw_lne(game, x, y, rx, ry, 0x23ff30) ;
        angle += 0.03;
    }
}

void    draw_square(t_game *game, int x, int y, int size, int color)
{
    int i = 0 ;
    while (i < size)
    {
        int j = 0 ;
        while (j < size)
        {
            if (window_valid(x + j, y + j))
                my_mlx_pixel_put(game->mlx->img, x + j, y + i, color) ;
            j++ ;
        }
        i++ ;
    }
}

void    draw_player(t_game *game)
{
    int px = game->player.x;
    int py = game->player.y  ;
    double xstart = game->player.x ;
    double ystart = game->player.y ;
    double xend = px + cos(game->angle) * 40 ;
    double yend = py + sin(game->angle) * 40 ;
    // draw_circle(game, px, py, 20) ;
    // draw_square(game, px - 10, py - 10, 20, 0x3eff00) ;
    draw_lne(game, xstart, ystart, xend, yend, 0xff0033) ;
}

void    draw2d(t_game *game)
{
    int i;
    int j;
    int tilex = (int)game->tilex ;
    int tiley = (int)game->tiley ;
    i = 0 ;
    while (i < game->height)
    {
        j = 0 ;
        while (j < game->width)
        {
            if (game->map[i][j] == '1')
                draw_wall(game, j * tilex, i * tiley, tilex, tiley, 0xffffff) ;
            j++ ;
        }
        i++ ;
    }
    draw_player(game) ;
    for (int i = 0; game->map[i]; i++)
    {
        for (int j = 0; game->map[i][j]; j++)
            printf("%c", game->map[i][j]) ;
        printf("\n") ;
    }
}