# include "parser.h"

int is_all_one(int *arr, int size)
{
    int i ;

    i = 0 ;
    while (i < size)
    {
        if (arr[i] != 1)
            return (0) ;
        i++ ;
    }
    return (1) ;
}

char *rm_newline_trim(char *line)
{
    char *keep;

    if (line && line[0] && line[ft_strlen(line) - 1] == '\n')
    {
        keep = line ;
        line = slice(line, 0, ft_strlen(line) - 1) ;
        free(keep) ;
    }
    keep = line ;
    line = ft_strtrim(line) ;
    if (keep)
        free(keep) ;
    return (line) ;
}


int count_char(const char *s, char c)
{
    int i;
    int res;

    res = 0 ;
    i = -1;
    while (s[++i])
        res += (s[i] == c) ;
    return (res) ;
}


int is_line_valid(char *line, int *player, int *params, int fd)
{
    if (!ft_strncmp(line, "NO", 2))
        return (check_north(line, params)) ;
    else if (!ft_strncmp(line, "SO", 2))
        return (check_south(line, params)) ;
    else if (!ft_strncmp(line, "WE", 2))
        return (check_west(line, params)) ;
    else if (!ft_strncmp(line, "EA", 2))
        return (check_east(line, params)) ;
    else if (!ft_strncmp(line, "F", 1))
        return (check_floor(line, params)) ;
    else if (!ft_strncmp(line, "C", 1))
        return (check_ceiling(line, params)) ;
    else
        return (check_map(line, player, params, fd)) ;
    return (0) ;
}
