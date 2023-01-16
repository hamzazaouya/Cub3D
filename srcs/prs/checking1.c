# include "parser.h"

int check_floor(const char *line, int *params)
{
    char **split;
    int len;
    int is_valid ;

    if (line[0] != 'F')
        return (0) ;
    line++ ;
    split = split_by_lim(line, ",") ;
    len = get_split_len(split) ;
    is_valid = (len == 3 && count_char(line, ',') == 2 && check_colors(split)) ;
    if (!is_valid)
        error(PARSE_ERROR) ;
    free_split(split) ;
    free(split) ;
    params[F - 1] += 1 ;
    if (params[F - 1] > 1)
        error(PARSE_ERROR) ;
    return (is_valid) ;
}

int check_ceiling(const char *line, int *params)
{
    char **split;
    int len;
    int is_valid ;

    if (line[0] != 'C')
        return (0) ;
    line++ ;
    split = split_by_lim(line, ",") ;
    len = get_split_len(split) ;
    is_valid = (len == 3 && count_char(line, ',') == 2 && check_colors(split)) ;
    if (!is_valid)
        error(PARSE_ERROR) ;
    free_split(split) ;
    free(split) ;
    params[C - 1] += 1 ;
    if (params[C - 1] > 1)
        error(PARSE_ERROR) ;
    return (is_valid) ;
}

int check_map(char *line, int *player, int *params, int fd)
{
    int i;

    line = ft_strdup(line) ;
    while (line)
    {
        i = 0 ;
        while (line[i])
        {
            if (line[i] != '1' && line[i] != '0' && !is_space(line[i]) && line[i] != 'E' && line[i] != 'W' && line[i] != 'N' && line[i] != 'S')
            {
                free(line) ;
                error(PARSE_ERROR) ;
                return (0) ;
            }
            *player += (line[i] == 'E' || line[i] == 'W' || line[i] == 'N' || line[i] == 'S') ;
            i++;
        }
        if (line)
            free(line) ;
        line = NULL ;
        line = get_next_line(fd) ;
        if (!line)
            break ;
        line = rm_newline_trim(line) ;
    }
    params[MAP - 1] = 1 ;
    return (1) ;
}

int yes_valid(int *params, int p_len, int player)
{
    if (player == 0)
        error(MISSING_PLAYER_ERROR) ;
    else if (player > 1)
        error(MORE_THAN_ONE_PLAYER_ERROR) ;
    else if  (!is_all_one(params, p_len))
        error(PARSE_ERROR) ;
    return (1) ;
}

int is_map_valid(char *map)
{
    int         fd;
    int         player ;
    static int  params[7] ;
    char        *line;

    if (!is_extension_valid(map, ".cub"))
        error(CUBEXT_ERROR) ;
    fd = open_file(map) ;
    player = 0 ;
    while (1)
    {
        line = get_next_line(fd) ;
        if (!line)
            break ;
        line = rm_newline_trim(line) ;
        if (line && line[0] && !is_line_valid(line, &player, params, fd))
        {
            free(line) ;
            close(fd) ;
            return (0) ;
        }
        if (line)
            free(line) ;
    }
    close(fd) ;
    return (yes_valid(params, 7, player)) ;
}