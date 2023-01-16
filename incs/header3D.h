#ifndef HEADER3D_H
# define HEADER3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <limits.h>
# include <string.h>
# include <time.h>
# include <stdatomic.h>
# include "structures.h"
# include "../srcs/prs/parser.h"
# include "../srcs/prs/parser.h"
# include "macros.h"


// Random Map Generation
char    *generate_random_line(int height, int width, int y, int x) ;
char    **get_mapp(t_game *game, int width, int height, int isRandom) ;
void    print_map(char **map) ;
char	*ft_itoa(int n) ;
char	*ft_strjoin(const char *s1, const char *s2) ;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color) ;
double  length(t_ray *ray) ;

// RAYS
double length(t_ray *ray) ;
void    draw_ry(t_game *game, double angle, int col) ;
void    shoot_rays(t_game *game) ;

// MOVES
void    move_right(t_game *game) ;
void    move_left(t_game *game) ;
void    move_up(t_game *game) ;
void    move_down(t_game *game) ;
void    move(t_game *game) ;
int     mouse(int x, int y, t_game *game) ;

// UTILS
void    normalize_angle1(t_game *game) ; // normalizes the angle to not surpass PI VALUE and -PI VALUE ([-PI, 0] -> DOWN | [0, P] -> UP)
void    normalize_angle(t_game *game) ; // normalizes the angle to not surpass PI VALUE and -PI VALUE ([-PI, 0] -> DOWN | [0, P] -> UP)
t_pos   *getPlayerPosInMap(t_game *game, double x, double y) ;
t_pos   *getPlayerPosInWindow(t_game *game, int x, int y) ;
int     window_valid(int x, int y) ;
// ACTIONS
int     actions(int key, t_game *game) ;
int     exit_cub3d(t_game *game) ;
// DRAWING
void    draw_line(t_game *game) ; // not used but could be useful
void    draw_3dline(t_game *game, t_ray *ray) ;
void    draw_3dwall(t_game *game, t_ray *ray) ; // drawing ceiling, floor and 3d walls

// MOVES
void    move_right(t_game *game) ;
void    move_left(t_game *game) ;
void    move_up(t_game *game) ;
void    move_down(t_game *game) ;
void    move(t_game *game) ;

// PLAYER
int render_player(t_game *game) ;

// 2D
void    draw2d(t_game *game) ;

// testing moves
void    movve(t_game *game) ;

double get_x_distance(t_game *game, t_ray *r, double xs, double ys) ;
double get_y_distance(t_game *game, t_ray *r, double xs, double ys) ;


int     get_color_from_texture(t_game *game, t_ray *ray, int y, int x) ; // just the up for now ;

// minimap
void minimap(t_game *game) ;

//Initialization
void	init_animations(t_game *game);
void	simplify_colors(t_game *game);
void	init_textures(t_game *game);
t_game	*init_game(char *map_file);

void	rotate_mouse(t_game *game);
double	where_ray_hit(t_game *game, t_ray *r, double xs, double ys);

# endif