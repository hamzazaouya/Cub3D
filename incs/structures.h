/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:01:27 by hazaouya          #+#    #+#             */
/*   Updated: 2023/01/18 11:11:55 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <stdatomic.h>

typedef struct rgb
{
	int	r;
	int	g;
	int	b;
	int	color;
}	t_rgb;

typedef struct pos
{
	double	x;
	double	y;
	int		color;
	int		up;
	int		down;
}	t_pos;

typedef struct asset
{
	void	*img;
	char	*addr;
	char	*relative_path;
	int		fd;
	int		img_width;
	int		img_height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_asset;

typedef struct ray
{
	double		x_origin;
	double		y_origin;
	double		x_end;
	double		y_end;
	double		distance;
	double		angle;
	double		wall_height;
	int			texture_type;
	t_asset		*texture;
	int			col;
}	t_ray;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct animation
{
	t_asset		*assets;
	int			last;
	int			frames;
	int			current;
	atomic_int	isdone;
}	t_anim;

typedef struct t_texture
{
	t_asset		*west;
	t_asset		*east;
	t_asset		*south;
	t_asset		*north;
}	t_textures;

typedef struct mlxx
{
	void	*init;
	void	*win;
	t_data	*img;
}	t_mlx;

typedef struct game
{
	t_mlx		*mlx;
	t_pos		player;
	t_anim		*p;
	t_asset		*crosshair;
	t_textures	*textures;
	t_rgb		*floor;
	t_rgb		*ceiling;
	char		*map_file;
	char		**map;
	int			width;
	int			height;
	double		movex;
	double		movey;
	double		fov;
	double		angle;
	double		tilex;
	double		tiley;
	double		width_by_map;
	double		height_by_map;
	double		k;
	int			p_xsize;
	int			p_ysize;
	int			mouse_x;
	int			mouse_y;
	int			mouse_flag;
	int			mouse_rot;
	int			times_rot;
	atomic_int	mouse;
}	t_game;

typedef struct moves
{
	double		after_move_x;
	double		after_move_y;
	double		angle;
	int			ax;
	int			ay;
}	t_moves;

#endif
