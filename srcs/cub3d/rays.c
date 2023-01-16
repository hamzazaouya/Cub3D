#include "../../incs/header3D.h"

void    set_vars(t_game *game, double *xy, int *xpyp, int *oldxpyp)
{
    xy[0] = game->player.x ;
    xy[1] = game->player.y ;
    xpyp[0] = xy[0] / game->width_by_map ;
    xpyp[1] = xy[1] / game->height_by_map ;
}

int is_hit(t_game *game, double *xy, int *xpyp, int *oldxpyp)
{
    if (inclusive(0, (game->height-1), xpyp[1]) && inclusive(0, (game->width - 1), oldxpyp[0]) && game->map[xpyp[1]][oldxpyp[0]] == '1')
        return (1) ;
    else if (inclusive(0, (game->height-1), oldxpyp[1]) && inclusive(0, (game->width - 1), xpyp[0]) && game->map[oldxpyp[1]][xpyp[0]] == '1')
        return (0) ;
    else if (inclusive(0, (game->height-1), xpyp[1]) && inclusive(0, (game->width - 1), xpyp[0]) && game->map[xpyp[1]][xpyp[0]] == '1')
        return (0) ;
    else
        return (-1) ;
}

int where_ray_hits1(t_game *game, t_ray *r, double xs, double ys) // 0 -> x | 1 -> y
{
    double  xy[2] ;
    int     xpyp[2] ;
    int     oldxpyp[2] ;

    set_vars(game, xy, xpyp, oldxpyp) ;
    while (inclusive(0, (game->height-1), xpyp[1]) && inclusive(0, (game->width - 1), xpyp[0]) && game->map[xpyp[1]][xpyp[0]] != '1')
    {
        xpyp[0] = xy[0] / game->width_by_map ;
        xpyp[1] = xy[1] / game->height_by_map ;
        xy[0] += xs;
        xy[1] += ys;
        oldxpyp[0] = xpyp[0] ;
        oldxpyp[1] = xpyp[1] ;
        xpyp[0] = xy[0] / game->width_by_map ;
        xpyp[1] = xy[1] / game->height_by_map ;
        if (is_hit(game, xy, xpyp, oldxpyp) != -1)
            return (is_hit(game, xy, xpyp, oldxpyp)) ;
    }
    return (0) ;
}

double where_ray_hit(t_game *game, t_ray *r, double xs, double ys)
{
    r->distance = INT_MAX ;
    r->x_end = game->player.x ;
    r->y_end = game->player.y ;
    if (where_ray_hits1(game, r, xs, ys))
    {
        r->texture_type = (!isUp(r->angle) ? NORTH : SOUTH) ;
        return get_y_distance(game, r, xs, ys);
    }
    else
    {
        r->texture_type = (!isRight(r->angle) ? EAST : WEST) ;
        return (get_x_distance(game, r, xs, ys));
    }
    return (INT_MAX) ;
    
}

void    init_ray_textures(t_game *game, t_ray *ray)
{
    if (ray->texture_type == WEST)
        ray->texture = game->textures->west ;
    else if (ray->texture_type == EAST)
        ray->texture = game->textures->east ;
    else if (ray->texture_type == NORTH)
        ray->texture = game->textures->north ;
    else if (ray->texture_type == SOUTH)
        ray->texture = game->textures->south ;
}

t_ray *prepare_ray(t_game *game, double angle, int col)
{
    double xstep ;
    double ystep ;
    double x ;
    double y ;
    t_ray   *res ;

    res = alloc(sizeof(t_ray)) ;
    res->angle = angle ;
    xstep = cos(angle) ;
    ystep = sin(angle) ;
    res->distance = where_ray_hit(game, res, xstep, ystep)  ;
    init_ray_textures(game, res) ;
    res->x_origin = game->player.x ;
    res->y_origin = game->player.y ;
    res->col = col ;
    return res ;
}

void    draw_ry(t_game *game, double angle, int col)
{
    t_ray *ray ;

    ray = prepare_ray(game, angle, col) ;
    ray->distance = roundf(ray->distance) ;
    if (ray->distance > 0.001)
        ray->wall_height = wallHeight((ray->distance)) ;
    else
        ray->wall_height = 0 ;
    draw_3dwall(game, ray) ;
    free(ray) ;
}

void    shoot_rays(t_game *game)
{
    char **map ;
    double start_angle ;
    double end_angle ;
    double step ;
    int col ;

    start_angle =  game->angle - (FOV / 2) ;
    end_angle = game->angle + (FOV / 2) ;
    step = FOV / WIDTH ;
    col = 0 ;
    while (start_angle < end_angle)
    {
        draw_ry(game, start_angle, col) ;
        start_angle += step ;
        col++ ;
    }
}
