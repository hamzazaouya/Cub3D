# include "parser.h"

int is_space(char c)
{
    return (c == ' ' || c == '\n' || c == '\t' \
    || c == '\v' || c == '\f' || c == '\r') ;
}

char *ft_strtrim(const char *s)
{
    int i;
    int j;

    if (!s)
        return (NULL) ;
    i = 0;
    j = ft_strlen(s) - 1 ;
    while (s[i] && is_space(s[i]))
        i++ ;
    while (j >= 0 && is_space(s[j]))
        j-- ;
    return (slice(s, i, j + 1)) ;
}

int ft_atoi(const char *s)
{
    int i;
    int res;

    i = 0;
    res = 0;
    while (s[i])
    {
        res = (res * 10) + s[i] - '0' ;
        i++;
    }
    return res ;
}

int ft_strcmp(const char *s1, const char *s2)
{
    int i;

    i = 0;
    while (s1[i] || s2[i])
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]) ;
        i++ ;
    }
    return (0) ;
}

int ft_strncmp(const char *s1, const char *s2, int n)
{
    int i;

    i = 0;
    while ((s1[i] || s2[i]) && i < n)
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]) ;
        i++ ;
    }
    return (0) ;
}