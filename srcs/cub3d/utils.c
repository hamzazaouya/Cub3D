#include "../../incs/header3D.h"

int     get_color_from_texture(t_game *game, t_ray *ray, int y, int x) // just the up for now
{
    t_asset *t;
    int     *color ;
    int     offset ;

    t = ray->texture ;
    offset = (y * t->line_length + x * (t->bits_per_pixel / 8)) ;
    color = (int *)(t->addr + offset) ;
    return (*color) ;
}

int    window_valid(int x, int y)
{
    return (inbetween(-1, WIDTH, x) && inbetween(-1, HEIGHT, y)) ;
}

void    normalize_angle(t_game *game)
{
    double angle;

    angle = game->angle ;
    if (angle > M_PI)
        angle = (M_PI - (angle - M_PI)) * -1;
    else if (angle < -M_PI)
        angle = M_PI - (angle + M_PI) ;
    game->angle = angle ;
    if (angle < 0.01 && angle > 0.01)
        game->angle = 0 ;
}

void    normalize_angle1(t_game *game)
{
    double angle;

    angle = game->angle ;
    if (angle >= M_PI * 2)
        angle = angle - M_PI * 2;
    else if (angle <= 0)
        angle = M_PI * 2 + angle ;
    // else if (angle < -M_PI)
    //     angle = M_PI - (angle + M_PI) ;
    game->angle = angle ;
    if (angle < 0.01 && angle > 0.01)
        game->angle = 0 ;
}

t_pos *getPlayerPosInMap(t_game *game, double x, double y)
{
    t_pos *r ;

    r = (t_pos *) malloc(sizeof(t_pos)) ;
    r->x = (int) x / game->tilex ;
    r->y = (int) y / game->tiley ;
    return r ;
}

t_pos *getPlayerPosInWindow(t_game *game, int x, int y)
{
    t_pos *r ;

    r = (t_pos *) malloc(sizeof(t_pos)) ;
    r->x = x * game->width ;
    r->y = y * game->height ;
    return r ;
}
