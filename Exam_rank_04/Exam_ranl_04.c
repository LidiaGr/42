#include <unistd.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_fd
{
    int     read;
    int     write;
    int     flag;
}               t_fd;

int     ft_strlen(char *str)
{
    int i = 0;
    
    while(str[i])
        i++;
    return (i);
}

int     ft_strstrlen(char **av)
{
    int i = 0;
    
    while(av[i])
        i++;
    return (i);
}

void    error_fatal(void)
{
    write(2, "error: fatal\n", 13);
    exit(1);
}

void    error_exit(char *s1, char *s2)
{
    write(2, s1, ft_strlen(s1));
    if (s2)
        write(2, s2, ft_strlen(s2));
    write(2, "\n", 1);
}

void    get_fd(t_fd *fd)
{
    int pipes[2];
    
    if (pipe(pipes) == -1)
        error_fatal();
    fd->read = pipes[0];
    fd->write = pipes[1];
    fd->flag = 1;
}

void    start_process(char **av, char **env)
{
    pid_t pid;
    
    if (!strcmp("cd", av[0]))
    {
        if (ft_strstrlen(av) != 2)
            error_exit("error: cd: bad arguments", NULL);
        else if(chdir(av[1]) == -1)
            error_exit("error: cd: cannot change directory to ", av[1]);
    }
    else if ((pid = fork()) == -1)
        error_fatal();
    else if (pid == 0)
    {
        if (execve(av[0], av, env) < 0)
        {
            error_exit("error: cannot execute ", av[0]);
            exit(1);
        }
    }
    else
        waitpid(pid, 0, 0);
}

void    fork_process(t_fd *fd, char **av, char **env)
{
    pid_t pid;
    
    if ((pid = fork()) == -1)
        error_fatal();
    else if (pid == 0)
    {
        dup2(fd->write, 1);
        start_process(av, env);
        exit(0);
    }
    else
    {
        dup2(fd->read, 0);
        close(fd->write);
        waitpid(pid, 0 , 0);
        close(fd->read);
    }
}

void    exec_pre(t_fd *fd, char **av, char **env)
{
    if (fd->flag)
        fork_process(fd, av, env);
    else
        start_process(av, env);
}

int     main(int ac, char **av, char **env)
{
    t_fd fd;
    int i = 0;
    int tmp = dup(0);
    
    av++;
    (void)ac;
    while(av[i])
    {
        fd.flag = 0;
        if (!strcmp(av[i], "|"))
        {
            av[i] = 0;
            if(i)
            {
                get_fd(&fd);
                exec_pre(&fd, av, env);
            }
            av += i + 1;
            i = 0;
        }
        else if(!strcmp(av[i], ";"))
        {
            av[i] = 0;
            if (i)
                exec_pre(&fd, av, env);
            av += i + 1;
            i = 0;
            dup2(tmp, 0);
        }
        else if(!av[i + 1])
        {
            exec_pre(&fd, av, env);
            av += i + 1;
            i = 0;
            dup2(tmp, 0);
        }
        else
            i++;
    }
    close(tmp);
    return (0);
}
