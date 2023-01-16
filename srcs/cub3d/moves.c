#include "../../incs/header3D.h"

double  get_normalized_angle(double angle)
{
    if (angle > M_PI)
        angle = (M_PI - (angle - M_PI)) * -1;
    else if (angle < -M_PI)
        angle = M_PI - (angle + M_PI) ;
    if (angle < 0.01 && angle > 0.01)
        angle = 0 ;
    return (angle) ;
}

void    move_down(t_game *game)
{
    double  after_move_x;
    double  after_move_y ;
    double  angle ;
    int     ax ;
    int     ay ;

    angle = game->angle + M_PI ;
    angle = get_normalized_angle(angle) ;
    after_move_x = game->player.x + (game->movex * cos(angle)) ;
    after_move_y = game->player.y + (game->movey * sin(angle)) ;
    ay = after_move_y / game->height_by_map ;
    ax = after_move_x / game->width_by_map ;
    if (inclusive(0, (game->height-1), ay) && inclusive(0, (game->width - 1), ax) && game->map[ay][ax] != '1')
    {
        ax = after_move_x + KEEP_AWAY(game->width_by_map) * cos(angle) ;
        ax /= game->width_by_map ;
        ay = game->player.y + KEEP_AWAY(game->height_by_map) * sin(angle) ;
        ay /= game->height_by_map ;
        if (inclusive(0, (game->height-1), ay) && inclusive(0, game->width - 1, ax) && game->map[ay][ax] != '1')
        {
            game->player.x = after_move_x ;
            game->player.y = after_move_y ;
        }
    }
}

void    move_right(t_game *game)
{
    double  after_move_x;
    double  after_move_y ;
    double  angle ;
    int     ax ;
    int     ay ;

    angle = game->angle + M_PI_2 ;
    angle = get_normalized_angle(angle) ;
    after_move_x = game->player.x + (game->movex * cos(angle)) ;
    after_move_y = game->player.y + (game->movey * sin(angle)) ;
    ay = after_move_y / game->height_by_map ;
    ax = after_move_x / game->width_by_map ;
    if (inclusive(0, (game->height-1), ay) && inclusive(0, (game->width - 1), ax) && game->map[ay][ax] != '1')
    {
        ax = after_move_x + KEEP_AWAY(game->width_by_map) * cos(angle) ;
        ax /= game->width_by_map ;
        ay = game->player.y + KEEP_AWAY(game->height_by_map) * sin(angle) ;
        ay /= game->height_by_map ;
        if (inclusive(0, (game->height-1), ay) && inclusive(0, game->width - 1, ax) && game->map[ay][ax] != '1')
        {
            game->player.x = after_move_x ;
            game->player.y = after_move_y ;
        }
    }
}

void    move_left(t_game *game)
{
    double  after_move_x;
    double  after_move_y ;
    double  angle ;
    int     ax ;
    int     ay ;

    angle = game->angle - M_PI_2 ;
    angle = get_normalized_angle(angle) ;
    after_move_x = game->player.x + (game->movex * cos(angle)) ;
    after_move_y = game->player.y + (game->movey * sin(angle)) ;
    ay = after_move_y / game->height_by_map ;
    ax = after_move_x / game->width_by_map ;
    if (inclusive(0, (game->height-1), ay) && inclusive(0, (game->width - 1), ax) && game->map[ay][ax] != '1')
    {
        ax = after_move_x + KEEP_AWAY(game->width_by_map) * cos(angle) ;
        ax /= game->width_by_map ;
        ay = game->player.y + KEEP_AWAY(game->height_by_map) * sin(angle) ;
        ay /= game->height_by_map ;
        if (inclusive(0, (game->height-1), ay) && inclusive(0, game->width - 1, ax) && game->map[ay][ax] != '1')
        {
            game->player.x = after_move_x ;
            game->player.y = after_move_y ;
        }
    }
}

void    movve(t_game *game)
{
    double  after_move_x;
    double  after_move_y ;
    int     ax ;
    int     ay ;

    after_move_x = game->player.x + (game->movex * cos(game->angle)) ;
    after_move_y = game->player.y + (game->movey * sin(game->angle)) ;
    ay = after_move_y / game->height_by_map ;
    ax = after_move_x / game->width_by_map ;
    if (inclusive(0, (game->height-1), ay) && inclusive(0, (game->width - 1), ax) && game->map[ay][ax] != '1')
    {
        ax = after_move_x + KEEP_AWAY(game->width_by_map) * cos(game->angle) ;
        ax /= game->width_by_map ;
        ay = game->player.y + KEEP_AWAY(game->height_by_map) * sin(game->angle) ;
        ay /= game->height_by_map ;
        if (inclusive(0, (game->height-1), ay) && inclusive(0, game->width - 1, ax) && game->map[ay][ax] != '1')
        {
            game->player.x = after_move_x ;
            game->player.y = after_move_y ;
        }
    }
}
