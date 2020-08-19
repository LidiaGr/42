#include "gnl.h"

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

char    *add_sym(char *s, char *c)
{
   char *cpy;
   int i = 0;
   
   if (!(cpy = (char *)malloc(sizeof(char) * ft_strlen(s) + 2)))
       return (NULL);
   while (s && s[i])
   {
       cpy[i] = s[i];
       i++;
   }
    cpy[i++] = c[0];
    cpy[i] = '\0';
   return (cpy);
}

int     get_next_line(char **line, int fd)
{
    char    buf[1];
    ssize_t bytes;
    static char    *str;
    char    *tmp;
    
    while ((bytes = read(fd, buf, 1)) > 0)
    {
        if (buf[0] != '\n')
        {
            tmp = str;
            str = add_sym(str, buf);
            free(tmp);
        }
        else
            break ;
    }
    *line = ft_strdup(str);
    free(str);
    str = NULL;
    if (bytes < 0)
        return (-1);
    return (bytes ? 1 : 0);
}

#include <fcntl.h>
#include <stdio.h>
int main(void)
{
    int fd = 0;
    char *line = NULL;
    int i = 0;
    
    fd = open("./text.txt", O_RDONLY);
    while (i < 10)
    {
        get_next_line(&line, fd);
        printf("%s \n", line);
        free(line);
        i++;
    }
    return (0);
}
