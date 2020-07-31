#include "gnl.h"

char    *ft_strchr(const char *str, char c)
{
    while (*str != c)
    {
        if (*str == '\0')
            return (NULL);
        str++;
    }
    return ((char *)str);
}

int     ft_strlen(char *str)
{
    int len = 0;

    while (*str++)
        len++;
    return (len);
}

char    *ft_strdup(char *str)
{
    char *cpy;
    int     i = 0;

    if (!(cpy = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
        return (NULL);
    while (*str)
        cpy[i++] = *str++;
    cpy[i] = '\0';
    return (cpy);
}

char    *ft_strjoin(char *s1, char *s2)
{
    char *res;
    int i = 0;

    if (!s1 || !s2)
        return (NULL);
    if (!(res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
        return (NULL);
    while (*s1)
        res[i++] = *s1++;
    while (*s2)
        res[i++] = *s2++;
    res[i] = '\0';
    return (res);
}

char    *check_rest(char **rest, char **line)
{
    char *n;
    char *tmp;

    n = NULL;
    if (*rest)
    {
        if ((n = ft_strchr(*rest, '\n')))
        {
            *n = '\0';
            *line = ft_strdup(*rest);
            tmp = *rest;
            *rest = ft_strdup(++n);
            free(tmp);
        }
        else
        {
            *line = ft_strdup(*rest);
            free(*rest);
            *rest = NULL;
        }        
    }
    else 
        *line = ft_strdup("");
    return (n);
}

int     ft_gnl(char **line, int fd)
{
    static char *rest = NULL;
    char buf[BUFFER_SIZE + 1];
    ssize_t	bytes;
    char    *n;
    char    *tmp;

    bytes = 1;
    n = check_rest(&rest, line);
    if (line == NULL || BUFFER_SIZE <= 0 || fd < 0)
        return (-1);
    if (!n && (bytes = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[bytes] = '\0';
        if ((n = ft_strchr(buf, '\n')))
        { 
            *n = '\0';
            rest = ft_strdup(++n);
        }
        tmp = *line;
        if (!(*line = ft_strjoin(*line, buf)))
            return (-1);
        free(tmp);
    }
    if (bytes < 0)
        return (-1);
    return (bytes ? 1 : 0);
}
