# include "parser.h"

int get_split_len(char **m)
{
    int i;

    i = 0;
    while (m[i])
        i++ ;
    return (i) ;
}

void free_split(char **m)
{
    int i;

    i = -1;
    while (m[++i])
    {
        free(m[i]) ;
        m[i] = NULL;
    }
}