# include "parser.h"

int check_north(const char *line, int *params)
{
    char **split;
    int len;
    int is_valid ;

    split = split_by_space(line) ;
    len = get_split_len(split) ;
    is_valid = (len == 2 && !ft_strcmp(split[0], "NO")) ;
    free_split(split) ;
    free(split) ;
    params[NO - 1] += 1 ;
    if (params[NO] - 1 > 1)
        error(PARSE_ERROR) ;
    return (is_valid) ;
}

int check_south(const char *line, int *params)
{
    char **split;
    int len;
    int is_valid ;

    split = split_by_space(line) ;
    len = get_split_len(split) ;
    is_valid = (len == 2 && !ft_strcmp(split[0], "SO")) ;
    if (!is_valid)
        error(PARSE_ERROR) ;
    free_split(split) ;
    free(split) ;
    params[SO - 1] += 1 ;
    if (params[SO - 1] > 1)
        error(PARSE_ERROR) ;
    return (is_valid) ;
}

int check_west(const char *line, int *params)
{
    char **split;
    int len;
    int is_valid ;

    split = split_by_space(line) ;
    len = get_split_len(split) ;
    is_valid = (len == 2 && !ft_strcmp(split[0], "WE")) ;
    if (!is_valid)
        error(PARSE_ERROR) ;
    free_split(split) ;
    free(split) ;
    params[WE - 1] += 1 ;
    if (params[WE - 1] > 1)
        error(PARSE_ERROR) ;
    return (is_valid) ;
}

int check_east(const char *line, int *params)
{
    char **split;
    int len;
    int is_valid ;

    split = split_by_space(line) ;
    len = get_split_len(split) ;
    is_valid = (len == 2 && !ft_strcmp(split[0], "EA")) ;
    if (!is_valid)
        error(PARSE_ERROR) ;
    free_split(split) ;
    free(split) ;
    params[EA - 1] += 1 ;
    if (params[EA - 1] > 1)
        error(PARSE_ERROR) ;
    return (is_valid) ;
}

int check_colors(char **split)
{
    int i;
    int rgb; 
    char *keep;

    i = 0;
    while (split[i] && i < 3)
    {
        keep = split[i] ;
        split[i] = ft_strtrim(split[i]) ;
        free(keep) ;
        rgb = ft_atoi(split[i]) ;
        if (!inclusive(0, 255, rgb))
        {
            error(COLOR_NOT_VALID_ERR) ;
            return (0) ;
        }
        i++ ;
    }
    return (1) ;
}