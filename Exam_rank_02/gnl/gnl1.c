#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int     _strlen(char *s)
{
    int len = 0;

    while (s[len])
        len++;
    return (len);
}

int     _strchr(char *s, char c)
{
    int i = 0;

    while (s[i] && s[i] != c)
        i++;
    if (s[i] == c)
        return (i);
    return (-1);
}

char    *_calloc(int len, int size)
{
    char *new;
    int i = 0;
    int mem = 0;

    mem = len * size;
    if (!(new = malloc(mem)))
        return (NULL);
    while (i < mem)
        new[i++] = '\0';
    return (new);
}

char    *_substr(char *s, int begin, int len)
{
    char *new;   
    int i = 0;

    new = _calloc(len + 1, sizeof(char));
    while (s[begin] && i < len)
        new[i++] = s[begin++];
    return (new);
}

char    *_addtostr(char *s, char c)
{
    char *new;
    int i = 0;
    int len = 0;

    len = _strlen(s);
    new = _calloc(len + 2, sizeof(char));
    while (s[i])
    {
        new[i] = s[i];
        i++;
    }
    new[i] = c;
    return (new);
}

int     ft_gnl(char **line, int fd)
{
    static char *s;
    char    buff[1];
    int     pos;
    char    *tmp;

    s = _calloc(1, sizeof(char));
    while (read(fd, buff, 1) > 0)
    {
        tmp = s;
        s = _addtostr(s, buff[0]);
        free(tmp);
        if (buff[0] == '\n')
            break ;
    }
    if ((pos = _strchr(s, '\n')) >= 0)
    {
        *line = _substr(s, 0, pos);
        tmp = s;
        s = _substr(s, ++pos, _strchr(s, '\0'));
        free (tmp);
        return (1);
    }
    *line = _substr(s, 0, _strchr(s, '\0'));
    free(s);
    return (0);
}