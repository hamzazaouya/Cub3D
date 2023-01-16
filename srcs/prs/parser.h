#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <unistd.h>
# include "gnl/get_next_line.h"
# include "../../incs/structures.h"
# include "../../incs/macros.h"

# define OPEN_ERROR "Cub3d: Error in opening the file"
# define MALLOC_ERROR "Cub3D: Unexpected error in malloc!"
# define XPMEXT_ERROR "Cub3D: The file in the map is not an xpm file!"
# define CUBEXT_ERROR "Cub3D: The file you entered is not ending with .cub extension"
# define PARSE_ERROR "Cub3D: Parsing error!"
# define MAP_NOT_VALID_ERROR "Cub3D: Map is not valid!"
# define ARGS_ERROR "Cub3D: please run cub3d as follows: ./cub3d [map_file_path]"
# define MISSING_PLAYER_ERROR "Cub3D: There is no player in the map"
# define MORE_THAN_ONE_PLAYER_ERROR "Cub3D: There is more than one player in the map"
# define PLAYER_HAS_PATH_TO_SPACE_ERROR "Cub3D: There is a path to a space inside the map"
# define COLOR_NOT_VALID_ERR "Cub3D: One color inside the map is not valid\n"
# define NO 1
# define SO 2
# define WE 3
# define EA 4
# define F 5
# define C 6
# define MAP 7

typedef struct mq
{
    char    *line ;
    struct mq *next ;
}   t_mq ;

// checking directions
int check_north(const char *line, int *params) ;
int check_south(const char *line, int *params) ;
int check_west(const char *line, int *params) ;
int check_east(const char *line, int *params) ;

// checking map and colors
int check_colors(char **split) ;
int check_floor(const char *line, int *params) ;
int check_ceiling(const char *line, int *params) ;
int check_map(char *line, int *player, int *params, int fd) ;
int is_map_valid(char *map) ;

// errors
void ft_putstr_fd(int fd, const char *s) ;
int open_file(const char *filename) ;
void *alloc(size_t size) ;
void error(const char *s) ;

// utils functions
int is_space(char c) ;
char *ft_strtrim(const char *s) ;
int ft_atoi(const char *s) ;
int ft_strcmp(const char *s1, const char *s2) ;
int ft_strncmp(const char *s1, const char *s2, int n) ;
char *slice(const char *s, int start, int end) ;

// map util
int mq_size(t_mq *head) ;
t_mq*   new_mq(char *line) ;
void    push(t_mq **head, t_mq *new) ;
void    free_mq(t_mq **head) ;
char    *get_map_line(char *line) ;
void    parse_map(t_game *c, char *firstline, int fd) ;

// parser
void    parse_directions(char *line, char **file, int *fd) ;
void    parse_fc(char *line, t_rgb *colors) ;
void    parse_line(t_game *c, int *phase, char *line) ;
int     parser(t_game *game) ; // true or false ;
int     is_extension_valid(const char *file, char *ext) ;
char    **get_map(t_mq *head) ;
int     get_map_width(char **map) ;
int     get_map_height(char **map) ;
void    normalize_map_width(char **map, int width) ;

void    set_player_data(t_game *game, char **map) ;
int     valid_map(t_game *c) ;

char	**split_by_lim(char const *s, const char *lim) ;
char	**split_by_space(char const *s) ;
int     get_split_len(char **m) ;
void    free_split(char **m) ;
int     is_all_one(int *arr, int size) ;
char    *rm_newline_trim(char *line) ;
int     count_char(const char *s, char c) ;
int     is_line_valid(char *line, int *player, int *params, int fd) ;
int     get_player_x(char **map) ;
int     get_player_y(char **map) ;
char    *get_map_line(char *line) ;
void    rm_spaces_from_map(char **map) ;

# endif