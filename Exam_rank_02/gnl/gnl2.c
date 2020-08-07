#include "gnl2.h"

int     ft_strlen(char *s)
{
    int len = 0;
    
    while (s && s[len])
        len++;
    return (len);
}

char    *ft_strdup(char *s)
{
   char *cpy;
   int i = 0;

    if (!(cpy = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
        return (NULL);
    while (s && s[i])
    {
        cpy[i] = s[i];
        i++;
    }
   cpy[i] = '\0';
   return (cpy);
}
          
char    *ft_addsym(char *s, char *c)
{
    char    *new;
    int     i = 0;
    
    if(!(new = (char *)malloc(sizeof(char) * ft_strlen(s) + 2)))
        return (NULL);
    while (s && *s)
        new[i++] = *s++;
    new[i++] = c[0];
    new[i] = '\0';
    return (new);
}

int    ft_getline(char **str, char **line, int bytes)
{
    if (bytes == 0)
    {
        *line = ft_strdup(*str);
        free(*str);
        *str = NULL;
    }
    if (bytes < 0)
        return (-1);
    return (bytes ? 1 : 0);
}

int     gnl(char **line, int fd)
{
    char            buf[1];
    static char     *str;
    ssize_t         bytes;
    char            *tmp;
    
    while ((bytes = read(fd, buf, 1) > 0))
    {
        if (*buf && *buf != '\n')
        {
            tmp = str;
            str = ft_addsym(str, buf);
            free(tmp);
        }
        else
        {
            *line = ft_strdup(str);
            free(str);
            str = NULL;
            break ;    
        }
    }
    return (ft_getline(&str, line, bytes));
}

#include <stdio.h>
#include <fcntl.h>

int     main(void)
{
    int fd = 0;
    char *line = NULL;
//    int i = 0;
    
    gnl(&line, fd);
    printf("%s\n", line);
    // fd = open("test.txt", O_RDONLY);
    // while (i < 3)
    // {
    //     gnl(&line, fd);
    //     printf("%s\n", line);
    //     free(line);
    //     i++;
    // }
    return (0);
}
