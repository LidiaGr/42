#include <stdarg.h>
#include <unistd.h>

typedef struct  s_list
{
	int     i;
	int     len;
	int     width;
	int     have_prec;
	int     prec;
	int     negativ;
	int     zero_count;
	int     output;
	va_list arg;
}               t_list;

void    init(t_list *list)
{
	list->i = 0;
	list->output = 0;
}

void    list_reset(t_list *list)
{
	list->len = 0;
	list->width = 0;
	list->have_prec = 0;
	list->prec = 0;
	list->negativ = 0;
	list->zero_count = 0;
}

void    ft_putchar(char c)
{
	write(1, &c, 1);
}

int     ft_strlen(char *str)
{
	int len = 0;

	while(str[len])
		len++;
	return (len);
}

int		isnum(char c)
{
	return (c >= '0' && c <= '9');
}

void    check_flags(const char *s, t_list *list)
{
	list->i++;
	if (isnum(s[list->i]))
	{
		while (isnum(s[list->i]))
		{
			list->width = (list->width * 10) + (s[list->i] - '0');
			list->i++;
		} 
	}
	if (s[list->i] == '.')
	{
		list->i++;    
		list->have_prec = 1;
		while (isnum(s[list->i]))
		{
			list->prec = (list->prec * 10) + (s[list->i] - '0');
			list->i++; 
		}
	}
}

void	print_x_char(char c, int len, t_list **list)
{
	int i = 0;

	while (i < len)
	{
		ft_putchar(c);
		(**list).output++;
		i++;
	}
}

void	ft_putstrlen(char *s, int len)
{
	int i = 0;

	while (i < len)
	{
		ft_putchar(s[i]);
		i++;
	}
}

int		num_len(long num, int base)
{
	int len = 1;

	while (num >= base)
	{
		num /= base;
		len++;
	}
	return (len);
}

void	ft_putnbr_base(long num, int base, char *set)
{
	if (num >= base)
	{
		ft_putnbr_base(num / base, base, set);
		ft_putnbr_base(num % base, base, set);
	}
	else
		ft_putchar(set[num]);
}

void	process_s(t_list *list)
{
	char *str;

	list->i++;
	str = va_arg(list->arg, char *);
        if (!str)
                str = "(null)";
	list->len = ft_strlen(str);
	if (list->have_prec && list->prec < list->len)
		list->len = list->prec;
	print_x_char(' ', list->width - list->len, &list);
	ft_putstrlen(str, list->len);
	list->output += list->len;
}

void	process_d(t_list *list)
{
	long	num;

	list->i++;
	num = va_arg(list->arg, int);
	if (num < 0)
	{
		list->negativ = 1;
		num *= -1;
	}
	list->len = num_len(num, 10);
	if (num == 0 && list->have_prec)
		list->len = 0;
	if (list->have_prec && list->prec > list->len)
		list->zero_count = list->prec - list->len;
	if (list->negativ)
		list->len++;
        print_x_char(' ', list->width - (list->len + list->zero_count), &list);
	if (list->negativ)
		ft_putchar('-');
	print_x_char('0', list->zero_count, &list);
	if (num == 0 && list->have_prec)
		return ;
	ft_putnbr_base(num, 10, "0123456789");
	list->output += list->len;
}

void	process_x(t_list *list)
{
	unsigned int	num;

	list->i++;
	num = va_arg(list->arg,unsigned int);
	list->len = num_len(num, 16);
	if (num == 0 && list->have_prec)
		list->len = 0;
	if (list->prec > list->len)
		list->zero_count = list->prec - list->len;
	print_x_char(' ', list->width - (list->len + list->zero_count), &list);
	print_x_char('0', list->zero_count, &list);
	if (num == 0 && list->have_prec)
		return ;
	ft_putnbr_base(num, 16, "0123456789abcdef");
	list->output += list->len;
}

void	print_until(const char *str, char c, t_list *list)
{
	while (str[list->i] && str[list->i] != c)
	{
		ft_putchar(str[list->i]);
		list->output++;
		list->i++;
	}
}

int     ft_printf(const char *str, ...)
{
	t_list  list;

	init(&list);
	va_start(list.arg, str);
	while (str[list.i])
	{
		list_reset(&list);
		print_until(str, '%', &list);
		if (str[list.i])
		{
			check_flags(str, &list);
			if (str[list.i] == 's')
				process_s(&list);
			else if (str[list.i] == 'd')
				process_d(&list);
			else if (str[list.i] == 'x')
				process_x(&list);
		}
	}
	va_end(list.arg);
	return (list.output);
}

#include <stdio.h>

int		main(void)
{
	int s_l;
	int m_l;

	// s_l = printf("hello %10.3s hi %8.4d i %4.5x\n", "world", 123, 156);
	// m_l = ft_printf("hello %10.3s hi %8.4d i %4.5x\n", "world", 123, 156);
	
	s_l = printf("Hexadecimal for %d is %x\n", 42, 42);
	m_l = ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("st_len = %d, my_len = %d", s_l, m_l);
}
