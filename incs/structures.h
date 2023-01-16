#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <stdatomic.h>

typedef struct rgb
{
    int r ;
    int g ;
    int b ;
    int color ;
}   t_rgb ;

typedef struct pos
{
    double  x ; 
    double  y ;
    int     color ;
    int     up ;
    int     down ;
}   t_pos ;

typedef t_pos vec2 ;

typedef struct asset
{
    void    *img ;
    char    *addr ;
    char    *relative_path ;
    int     fd ;
    int     img_width ;
    int     img_height ;
    int     bits_per_pixel ;
    int     line_length ;
    int     endian ;
}   t_asset ;

typedef struct ray
{
    double      x_origin ; // x origin of the ray
    double      y_origin ; // y origin of the ray
    double      x ;
    double      y ;
    double      x_end ;
    double      y_end ;
    double      delta_y ; // how much y should get incremented
    double      delta_x ; // how much x should get incremented
    double      side_x ; // first x to increment
    double      side_y ; // first y to increment
    double      distance ; // distance to hit the wall
    double      angle ; // angle of the ray
    double      wall_height ;
    int         texture_type ;
    t_asset     *texture ;
    int     col ;
}   t_ray ;

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


typedef struct animation
{
    t_asset      *assets ;
    int          last ;
    int          frames ;
    int          current ;
    atomic_int          isdone ; // 0 not 1 yes
}   t_anim ;

typedef struct t_texture
{
    t_asset *west ;
    t_asset *east ;
    t_asset *south ;
    t_asset *north ;
}   t_textures ;


typedef struct mlxx
{
    void    *init ;
    void    *win ;
    t_data *img ;
}   t_mlx ;

typedef struct game
{
    t_mlx       *mlx ;
    t_pos       player ;
    t_anim      *p ;
    t_asset     *crosshair ;
    t_textures  *textures ;
    t_rgb       *floor ;
    t_rgb       *ceiling ;
    char        *map_file ;
    char        **map ;
    int         width ;
    int         height ;
    double      movex ;
    double      movey ;
    double fov ;
    double angle ;
    double tilex;
    double tiley;
    double width_by_map ;
    double height_by_map ;
    double k ;
    int p_xsize ;
    int p_ysize ;
    int mouse_x ;
    int mouse_y ;
    int mouse_flag ;
    int mouse_rot ;
    int times_rot ;
    atomic_int mouse ;
}   t_game ;


# endif