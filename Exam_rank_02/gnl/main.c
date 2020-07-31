#include <fcntl.h>
#include <stdio.h>
#include "gnl.h"

int     main(void)
{
    // int fd = 0;
	// char *line == NULL;
	// // int i;

	// // i = 0;

	// get_next_line(&line, fd);
	// printf("%s\n", line);

    int fd;
    char *line;
    int res;

    line = NULL;
    fd = open("test.txt", O_RDONLY);
    res = ft_gnl(&line, fd);
    printf("%s\n", line);
    printf("res = %d\n", res);
    free(line);
    res = ft_gnl(&line, fd);
    printf("%s\n", line);
    printf("res = %d\n", res);
    free(line);
    res = ft_gnl(&line, fd);
    printf("%s\n", line);
    printf("res = %d\n", res);
    free(line);

    return (0);
}