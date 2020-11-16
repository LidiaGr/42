#include <stdlib.h>
#include <unistd.h>
#include <strings.h>

#define STDIN 0
#define STDOUT 1

#define END 2
#define PIPE 3
#define	BREAK 4

typedef struct	s_data
{
	char 	**tab;
	int 	size;
	int 	delim;
	int		pipe[2];
	struct s_data *next;
	struct s_data *prev;
} 				t_data;

int		ft_strlen(char *str)
{
	int i = 0;

	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char 	*ft_strdup(char *str)
{
	char *cpy;
	int len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (!(cpy = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	cpy[len] = '\0';
	while (--len >= 0)
		cpy[len] = str[len];
	return (cpy);
}

void 	exit_from(char *str, char *str2)
{
	write(STDOUT, str, ft_strlen(str));
	if (str2)
		write(STDOUT, str2, ft_strlen(str2));
	write(STDOUT, "\n", 1);
	exit(1);
}

void 	ft_lst_addback(t_data **input, t_data *new)
{
	t_data	*tmp;
	if (!(*input))
		*input = new;
	else
	{
		tmp = *input;
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		tmp->prev = tmp;
	}
}

int 	count_tabsize(char **av)
{
	int i = 0;

	while (av[i] && strcmp(av[i], ";") != 0 && strcmp(av[i], "|") != 0)
		i++;
	return (i);
}

int 	check_end(char *av)
{
	if (!av)
		return (END);
	if (strcmp(av, "|") == 0)
		return (PIPE);
	if (strcmp(av, ";") == 0)
		return (BREAK);
	return (0);
}

int 	parse_args(t_data **input, char **av)
{
	int size;
	t_data	*new;

	size = count_tabsize(av);
	if (!(new = malloc(sizeof(t_data))))
		exit_from("error: fatal", NULL);
	if (!(new->tab = malloc(sizeof(char *) * (size + 1))))
		exit_from("error: fatal", NULL);
	new->size = size;
	new->next = NULL;
	new->prev = NULL;
	new->tab[size] = NULL;
	while (--size >= 0)
		new->tab[size] = ft_strdup(av[size]);
	new->delim = check_end(av[new->size]);
	ft_lst_addback(input, new);
	return (new->size);
}

void 	exec_act(t_data *tmp, char **env)
{
	pid_t	pid;
	int 	status;
	int 	flag;

	flag = 0;
	if (tmp->delim == PIPE || (tmp->prev && tmp->prev->delim == PIPE))
	{
		flag = 1;
		if (pipe(tmp->pipe))
			exit_from("error: fatal", NULL);
	}
	pid = fork();
	if (pid < 0)
		exit_from("error: fatal", NULL);
	else if (pid == 0)
	{
		if (tmp->delim == PIPE && dup2(tmp->pipe[1], STDOUT) < 0)
			exit_from("error: fatal", NULL);
		if (tmp->prev && tmp->prev->delim == PIPE && dup2(tmp->prev->pipe[0], STDIN) < 0)
			exit_from("error: fatal", NULL);
		if ((execve(tmp->tab[0], tmp->tab, env) < 0))
			exit_from("error: cannot execute ", tmp->tab[0]);
		exit (0);
	}
    waitpid(pid, &status, 0);
    if (flag)
    {
        close(tmp->pipe[1]);
        if (!tmp->next || tmp->delim == BREAK)
            close(tmp->pipe[0]);
    }
    if (tmp->prev && tmp->prev->delim == PIPE)
        close(tmp->pipe[0]);
}

void 	exec_pre(t_data *input, char **env)
{
	t_data	*tmp;

	tmp = input;
	while (tmp)
	{
		if (strcmp("cd", tmp->tab[0]) == 0)
		{
			if (tmp->size != 2)
                exit_from("error: cd: bad arguments", NULL);
			if (chdir(tmp->tab[1]) < 0)
				exit_from("error: cd: cannot change directory to ", tmp->tab[1]);
		}
		else
			exec_act(tmp, env);
		tmp = tmp->next;
	}
}

void 	ft_clear(t_data *input)
{
	t_data	*tmp;
	int i;

	while (input)
	{
		tmp = input->next;
		i = 0;
		while (i < input->size)
			free(input->tab[i++]);
		free(input->tab);
		free(input);
		input = tmp;
	}
	input = NULL;
}

int 	main(int ac,char **av, char **env)
{
	t_data *input = NULL;
	int i = 1;

	if (ac > 1)
	{
		while (av[i])
		{
			if (strcmp(av[i], ";") == 0 || strcmp(av[i], "|") == 0)
			{
				i++;
				continue ;
			}
			i += parse_args(&input, &av[i]);
		}
		if (input)
			exec_pre(input, env);
		ft_clear(input);
	}
	return (0);
}
