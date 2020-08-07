# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct  s_list
{
    int         width;
    int         precision;
    char        spec;
    int         len;
}               t_list;

void    check_symbols_for_write(const char **str, va_list *ap, t_list *list);

void    make_list(t_list *list)
{
    (*list).width = 0;
    (*list).precision = 0;
    (*list).spec = 0;
    (*list).len = 0;
}

void    reset_list(t_list *list)
{
    (*list).width = 0;
    (*list).precision = 0;
    (*list).spec = 0;
}

int		ft_atoi(const char **str)
{
	int buff;
	int minus;

	buff = 0;
	minus = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			minus = -1;
		(*str)++;
	}
	while (**str >= '0' && **str <= '9')
	{
		buff = (**str - '0') + (buff * 10);
		(*str)++;
	}
	buff = buff * minus;
	return (buff);
}

void    check_width(const char **str, va_list *ap, t_list *list)
{
    int num;

    num = 0;
    if (**str == '*')
    {
        num = va_arg(*ap, int);
		str++;
    }
    else 
        num = ft_atoi(str);
    if (num < 0)
        num *= -1;
    (*list).width = num;
}

void    check_precision(const char **str, va_list *ap, t_list *list)
{
    int num;

    num = -1;
    if (**str == '.')
    {
        (*str)++;
        if (**str == '*')
        {
            num = va_arg(*ap, int);
            str++;
        }
        else 
            num = ft_atoi(str);
        if (num <= 0)
            num = 0;
    }
    (*list).precision = num;
}

char    *ft_itoa(int num)
{
    int     minus = 0;
    int     nb = num;
    int     len = 1;
    char    *num_str = NULL;

    if (num < 0)
    {
        minus = 1;
        nb *= -1;
    }
    while (nb / 10)
    {
        len++;
        nb /= 10;
    }
    if (!(num_str = (char *)malloc(sizeof(char) * (len + minus + 1))))
        return (NULL);
    if (minus)
    {
        num_str++;
        *num_str = '-';
    } 
    while(num / 10)
    {
        *num_str = num % 10 + '0';
        num /= 10;
        num_str++;
    }
    *num_str = num + '0';
    return (num_str);
}

int     ft_strlen(char *str)
{
    int len = 0;

    while (*str++)
        len++;
    return (len);
}

char    *ft_strjoin(char *s1, char *s2)
{
    char *res;
    int     i = 0;

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

void    go_width(char **str, t_list *list)
{
    int     len = 0;
    char    *add_str = NULL;
    int     pre;

    len = ft_strlen(*str);
    if ((*list).width > len)
    {
        pre = (*list).width - len;
        if (!(add_str = (char *)malloc(sizeof(char) * (pre + 1))))
            exit (0);
        while (--pre >= 0 )
            add_str[pre] = ' ';
        (*str) = ft_strjoin(add_str, (*str));
        free(add_str); 
    }
}

void    go_precision(char **str, t_list *list)
{
    int     len = 0;
    char    *add_str = NULL;
    int     pre;

    len = ft_strlen(*str);
    if ((*list).precision > len)
    {
        pre = (*list).precision - len;
        if (!(add_str = (char *)malloc(sizeof(char) * (pre + 1))))
            exit (0);
        while (--pre >= 0)
            add_str[pre] = '0';
        (*str) = ft_strjoin(add_str, (*str));
        free(add_str); 
    }
}

char    *ft_itoa_base(unsigned int num)
{
    int     nb = num;
    int     len = 1;
    char    *num_str = NULL;

    while (nb >= 16)
    {
        len++;
        nb /= 16;
    }
    if (!(num_str = (char *)malloc(sizeof(char) * (len + 1))))
        return (NULL);
    while(num / 16)
    {
        *num_str = num % 16 + '0';
        if (*num_str > '9')
            *num_str += 39;
        num /= 16;
        num_str++;
    }
    *num_str = num + '0';
    return (num_str);
}

void    ft_process_hex(va_list *ap, t_list *list)
{
    int		num = 0;
	char	*num_str = NULL;

    num = va_arg(*ap, unsigned int);
    num_str = ft_itoa_base(num);
    go_precision(&num_str, list);
    go_width(&num_str, list);
    write(1, num_str, ft_strlen(num_str));
    (*list).len += ft_strlen(num_str);
}

void    ft_process_str(va_list *ap, t_list *list)
{
	char	*str = NULL;

    str = va_arg(*ap, char *);
    go_precision(&str, list);
    go_width(&str, list);
    write(1, str, ft_strlen(str));
    (*list).len += ft_strlen(str);
}

void    ft_process_dec(va_list *ap, t_list *list)
{
    int		num = 0;
	char	*num_str = NULL;

    num = va_arg(*ap, int);
    num_str = ft_itoa(num);
    go_precision(&num_str, list);
    go_width(&num_str, list);
    write(1, num_str, ft_strlen(num_str));
    (*list).len += ft_strlen(num_str);
}

void    check_type(const char **str, va_list *ap, t_list *list)
{
    if (**str == 'd' || **str == 's' || **str == 'x')
    {
        (*list).spec = **str;
        (*str)++;
    }
    if ((*list).spec == 'd')
        ft_process_dec(ap, list);
    if ((*list).spec == 's')
        ft_process_str(ap, list);
    if ((*list).spec == 'x')
        ft_process_hex(ap, list);
}

void    ft_parser(const char **str, va_list *ap, t_list *list)
{
    check_width(str, ap, list);
    check_precision(str, ap, list);
    check_type(str, ap, list);
    check_symbols_for_write(str, ap, list);
}

void    check_symbols_for_write(const char **str, va_list *ap, t_list *list)
{
    while (**str != '%' && **str != '\0') 
    {
            write(1, (*str), 1);
            (*str)++;
            (*list).len++;
    }
    if (**str == '%')
    {
        (*str)++;
        reset_list(list);
        ft_parser(str, ap, list);
    }
}

int     ft_printf(const char *str, ...)
{
    va_list ap;
    t_list list;

    make_list(&list);
    va_start(ap, str);
    check_symbols_for_write(&str, &ap, &list);
    va_end(ap);
    return (list.len);
}

#include <stdio.h>
int     main(void)
{
    // ft_printf("hello %8.4d\n", 5);
    // printf("hello %8.4d\n", 5);

    // ft_printf("%10.2s\n", "hello");
    // printf("%10.2s\n", "hello");

    ft_printf("Hexadecimal for %d is %x\n", 42, 42);
    printf("Hexadecimal for %d is %x\n", 42, 42);

    return (0);
}