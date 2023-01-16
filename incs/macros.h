#ifndef MACROS_H
# define MACROS_H

# define FOV 1.1072

# define CEIL_COLOR 0x7ec8e3
# define FLOOR_COLOR 0x222222

# define CUBE_SIZE 64

# define RIGHT_KEY 124
# define LEFT_KEY 123
# define UP_KEY 126
# define DOWN_KEY 125
# define W_KEY 13
# define S_KEY 1
# define R_ANGLE 2
# define L_ANGLE 0
# define EXIT_KEY 53

# define MOUSE_MOVE_EVENT 6

# define WIDTH 1200
# define HEIGHT 800

# define WIDTH_3D (WIDTH * 2)
# define HEIGHT_3D (HEIGHT)

// 3D MACROS
# define WIDTH_3D_START WIDTH
# define WIDTH_3D_END (WIDTH * 2 - 1)
# define HEIGHT_3D_START 0
# define HEIGHT_3D_END (HEIGHT - 1)

# define MOVE_X 20
# define MOVE_Y 20
# define KEEP_AWAY(tile) ((double)tile / 4)
# define KEEP_DISTANCE_FROM_WALL(tile_size) (tile_size / 2)

# define WALL_HEIGHT 32

# define inclusive(a,b,x) (x >= a && x <= b)
# define inbetween(a,b,x) (x > a && x < b)
# define is_color_valid(c) (inclusive(0,255,c))
# define pow2(a) (a * a)
# define pow3(a) (a * a * a)
# define min(a, b) (a < b ? a : b)
# define max(a, b) (a > b ? a : b)
# define UNDEFINED INT_MAX

# define distProjPlane ((double)(WIDTH / 2) / tan(FOV / 2))
# define wallHeight(distance) ((CUBE_SIZE / distance) * distProjPlane)

# define isUp(angle) (sin(angle) <= 0)
# define isRight(angle) (cos(angle) >= 0)

# define WEST 1
# define EAST 2
# define SOUTH 3
# define NORTH 4

# define RAY 100
# define DIAMETRE RAY * 2
# define ZOOM 4
# define is_player(c) (c == 'W' || c == 'N' || c == 'E' || c == 'S')

# endif