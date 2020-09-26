/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 10:42:34 by ttarsha           #+#    #+#             */
/*   Updated: 2020/09/20 13:54:05 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>

void	test_strlen()
{
	printf("std = %zu\n", strlen("hello world"));
	printf("mio = %zu\n", ft_strlen("hello world"));
	printf("std = %zu\n", strlen(""));
	printf("mio = %zu\n", ft_strlen(""));
	printf("std = %zu\n", strlen("An assembly (or assembler) language, \
		abbreviated asm, is a low-level programming language for a computer,\
		or other programmable device, in which there is a very strong (but \
		often not one-to-one) correspondence between the language and the \
		architecture’s machine code instructions. Each assembly language \
		is specific to a particular computer architecture. In contrast, \
		most high-level programming languages are generally portable \
		across multiple architectures but require interpreting or \
		compiling. Assembly language may also be called symbolic \
		machine code."));
	printf("mio = %zu\n", ft_strlen("An assembly (or assembler) language, \
		abbreviated asm, is a low-level programming language for a computer,\
		or other programmable device, in which there is a very strong (but \
		often not one-to-one) correspondence between the language and the \
		architecture’s machine code instructions. Each assembly language \
		is specific to a particular computer architecture. In contrast, \
		most high-level programming languages are generally portable \
		across multiple architectures but require interpreting or \
		compiling. Assembly language may also be called symbolic \
		machine code."));	
}

void	define_str(char **s)
{
	char	*s1;
	char	*s2;
	char	*s3;

	s1 = "hello world";
	s2 = "";
	s3 = "An assembly (or assembler) language, \
abbreviated asm, is a low-level programming language for a computer,\
or other programmable device, in which there is a very strong (but \
often not one-to-one) correspondence between the language and the \
architecture’s machine code instructions. Each assembly language \
is specific to a particular computer architecture. In contrast, \
most high-level programming languages are generally portable \
across multiple architectures but require interpreting or \
compiling. Assembly language may also be called symbolic \
machine code.";
	s[0] = s1;
	s[1] = s2;
	s[2] = s3;
	s[3] = NULL;
}

void	test_strcpy()
{
	char	*std;
	char	*mio;
	char	*s[4];
	int		i;

	i = 0;
	define_str(s);
	while (i < 3)
	{
		std = malloc(sizeof(char) * strlen(s[i]) + 1);
		mio = malloc(sizeof(char) * strlen(s[i]) + 1);
		strcpy(std, s[i]);
		ft_strcpy(mio, s[i]);
		printf("std = %s\nmio = %s\n", std, mio);
		i++;
		free(std);
		free(mio);
	}
}

void	test_strcmp()
{
	char *str;
	
	str = "hello";
	printf("std = %d\n", strcmp(str, "hello"));
	printf("mio = %d\n", ft_strcmp(str, "hello"));
	printf("std = %d\n", strcmp(str, ""));
	printf("mio = %d\n", ft_strcmp(str, ""));
	printf("std = %d\n", strcmp(str, "ha"));
	printf("mio = %d\n", ft_strcmp(str, "ha"));
	printf("std = %d\n", strcmp("", str));
	printf("mio = %d\n", ft_strcmp("", str));
	str = "";
	printf("std = %d\n", strcmp("", str));
	printf("mio = %d\n", ft_strcmp("", str));
}

void	test_write_next()
{
	char *str;
	int err_std;
	int err_mio;
	
	errno = 0;
	str = "world\n";
	write(5, str, strlen(str));
	err_std = errno;
	ft_write(5, str, strlen(str));
	err_mio = errno;
	printf("err_std = %d\nerr_mio = %d\n", err_std, err_mio);
	
	errno = 0;
	str = "today\n";
	write(1, str, -3);
	err_std = errno;
	ft_write(1, str, -3);
	err_mio = errno;
	printf("err_std = %d\nerr_mio = %d\n", err_std, err_mio);
}

void	test_write()
{
	char *str;
	int err_std;
	int err_mio;
	
	errno = 0;
	str = "hello\n";
	write(1, str, strlen(str));
	err_std = errno;
	ft_write(1, str, strlen(str));
	err_mio = errno;
	printf("err_std = %d\nerr_mio = %d\n", err_std, err_mio);
	
	errno = 0;
	str = "how much words can we write\n";
	write(1, str, strlen(str));
	err_std = errno;
	ft_write(1, str, strlen(str));
	err_mio = errno;
	printf("err_std = %d\nerr_mio = %d\n", err_std, err_mio);
	test_write_next();
}

void	test_read_next()
{
	int 	err_std;
	int		err_mio;
	char	buf_std[100];
	char 	buf_mio[100];

	errno = 0;
	read(60, buf_std, 55);
	err_std = errno;
	ft_read(60, buf_mio, 55);
	err_mio = errno;
	printf("err_std = %d\nerr_mio = %d\n", err_std, err_mio);

	errno = 0;
	read(0, buf_std, 25);
	err_std = errno;
	ft_read(0, buf_mio, 25);
	err_mio = errno;
	printf("err_std = %d\nerr_mio = %d\n", err_std, err_mio);
}

void	test_read()
{
	int 	err_std;
	int		err_mio;
	int		fd_std;
	int		fd_mio;
	char	buf_std[100];
	char 	buf_mio[100];
	
	errno = 0;
	fd_std = open("test/read.txt", O_RDWR);
	fd_mio = open("test/read.txt", O_RDWR);
	read(fd_std, buf_std, 55);
	err_std = errno;
	ft_read(fd_mio, buf_mio, 55);
	err_mio = errno;
	printf("std = %s\nmio = %s\n", buf_std, buf_mio);
	printf("err_std = %d\nerr_mio = %d\n", err_std, err_mio);
    
    errno = 0;
    read(fd_std, buf_std, -1);
    err_std = errno;
    ft_read(fd_mio, buf_mio, -1);
    err_mio = errno;
    printf("err_std = %d\nerr_mio = %d\n", err_std, err_mio);
    
	test_read_next();
}

void	test_strdup()
{
	printf("std = %s\n", strdup("hello world"));
	printf("mio = %s\n", ft_strdup("hello world"));
	printf("std = %s\n", strdup(""));
	printf("mio = %s\n", ft_strdup(""));
	printf("std = %s\n", strdup("An assembly (or assembler) language, \
abbreviated asm, is a low-level programming language for a computer,\
or other programmable device, in which there is a very strong (but \
often not one-to-one) correspondence between the language and the \
architecture’s machine code instructions. Each assembly language \
is specific to a particular computer architecture. In contrast, \
most high-level programming languages are generally portable \
across multiple architectures but require interpreting or \
compiling. Assembly language may also be called symbolic \
machine code."));
	printf("mio = %s\n", ft_strdup("An assembly (or assembler) language, \
abbreviated asm, is a low-level programming language for a computer,\
or other programmable device, in which there is a very strong (but \
often not one-to-one) correspondence between the language and the \
architecture’s machine code instructions. Each assembly language \
is specific to a particular computer architecture. In contrast, \
most high-level programming languages are generally portable \
across multiple architectures but require interpreting or \
compiling. Assembly language may also be called symbolic \
machine code."));
}

int		main(void)
{
	printf("\033[36m--------------------\033[0m\n");
	printf("\n\033[36m---FT_STRLEN_TEST---\033[0m\n");
	test_strlen();
	printf("\n\033[36m---FT_STRCPY_TEST---\033[0m\n");
	test_strcpy();
	printf("\n\033[36m---FT_STRCMP_TEST---\033[0m\n");
	test_strcmp();
	printf("\n\033[36m---FT_WRITE_TEST---\033[0m\n");
	test_write();
	printf("\n\033[36m---FT_READ_TEST---\033[0m\n");
	test_read();
	printf("\n\033[36m---FT_STRDUP_TEST---\033[0m\n");
	test_strdup();
	printf("\033[36m--------------------\033[0m\n");
	return (0);
}
