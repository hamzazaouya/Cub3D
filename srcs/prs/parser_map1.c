# include "parser.h"

int get_player_x(char **map)
{
    int i;
    int j;

    i = 0 ;
    while (map[i])
    {
        j = 0 ;
        while (map[i][j])
        {
            if (map[i][j] == 'W' || map[i][j] == 'S' | map[i][j] == 'E' || map[i][j] == 'N')
                return (j) ;
            j++ ;
        }
        i++ ;
    }
    return (-1) ;
}

int get_player_y(char **map)
{
    int i;
    int j;

    i = 0 ;
    while (map[i])
    {
        j = 0 ;
        while (map[i][j])
        {
            if (map[i][j] == 'W' || map[i][j] == 'S' | map[i][j] == 'E' || map[i][j] == 'N')
                return (i) ;
            j++ ;
        }
        i++ ;
    }
    return (-1) ;
}

char    *get_map_line(char *line)
{
    char    *res;
    int     i;
    int     j;
    int     len ;

    i = -1;
    len = 0 ;
    while (line[++i])
        len += 1 ; // is_space was here
    res = (char *) alloc((len + 1) * sizeof(char)) ;
    i = -1 ;
    j = 0 ;
    while (line[++i])
        res[j++] = line[i] ;
    res[j] = 0 ;
    return (res) ;
}

int     get_len_without_spaces(char *s)
{
    int len;
    int i;

    len = 0 ;
    i = 0 ;
    while (s[i])
    {
        if (!is_space(s[i]))
            len += 1 ;
        i++ ;
    }
    return (len) ;
}

void    rm_spaces_from_map(char **map)
{
    int i ;
    int j ;
    int len ;
    int k ;
    char    *res ;

    i = 0 ;
    while (map[i])
    {
        j = 0 ;
        len = get_len_without_spaces(map[i]) ;
        res = alloc((len + 1) * sizeof(char)) ;
        res[len] = 0 ;
        k = 0 ;
        while (map[i][j])
        {
            if (!is_space(map[i][j]))
                res[k++] = map[i][j] ;
            j++ ;
        }
        free(map[i]) ;
        map[i] = res ;
        i++ ;
    }
}