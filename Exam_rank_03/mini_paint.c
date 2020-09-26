# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef struct	s_zone
{
	int			w;
	int			h;
	char		bg_c;
}				t_zone;

// typedef struct	s_shape
// {
// 	char		type;
// 	float		x;
// 	float		y;
// 	float		radius;
// 	char		color;
// }				t_shape;

typedef struct	s_shape
{
	char		type;
	float		x;
	float		y;
	float		w;
	float		h;
	char		color;
}				t_shape;

int		ft_strlen(const char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

int		str_error(const char *str)
{
	if (str)
		write (1, str, ft_strlen(str));
	return (1);
}	

int		clr_all(FILE *file, char *bg)
{
	fclose(file);
	if (bg)
		free(bg);
	return (1);
}

char	*get_zone(FILE *file, t_zone *zone)
{
	int	i = -1;
	char *tmp;

	if ((fscanf(file, "%d %d %c\n", &zone->w, &zone->h, &zone->bg_c)) != 3)
		return (NULL);
	if (zone->w < 0 || zone->w > 300 || zone->h < 0 || zone->h > 300)
		return (NULL);
	if (!(tmp = malloc(sizeof(*tmp) * (zone->w * zone->h))))
		return (NULL);
	while (++i < zone->w * zone->h)
		tmp[i] = zone->bg_c;
	return (tmp);
}

// int		in_circle(float x, float y, t_shape *shape)
// {
// 	float	dist;

// 	dist = sqrtf(powf(x - shape->x, 2.) + powf(y - shape->y, 2.));
// 	if (dist <= shape->radius)
// 	{
// 		if (shape->radius - dist < 1.)
// 			return (2);
// 		return (1);
// 	}
// 	return (0); 
// }

int		in_rectangle(float x, float y, t_shape *shape)
{
	if ((x < shape->x || (shape->x + shape->w) < x)
		|| (y < shape->y || (shape->y + shape->h) < y))
		return (0);
	if (((x - shape->x) < 1. || (shape->x + shape->w) - x < 1.) 
		|| ((y - shape->y) < 1. || (shape->y + shape->h) - y < 1.))
		return (2);
	return (1);
}

void	draw_shape(t_zone *zone, char *bg, t_shape *shape)
{
	int	x;
	int y;
	int ret;

	y = 0;
	while (y < zone->h)
	{
		x = 0;
		while (x < zone->w)
		{
			//ret = in_circle((float)x, (float)y, shape);
			ret = in_rectangle((float)x, (float)y, shape);
			// if ((shape->type == 'c' && ret == 2) 
			// 	|| (shape->type == 'C' && ret))
			if ((shape->type == 'r' && ret == 2) 
				|| (shape->type == 'R' && ret))
				bg[x + y * zone->w] = shape->color;
			x++;
		}
		y++;
	}
}

int		init_shapes(FILE *file, t_zone *zone, char *bg)
{
	t_shape shape;
	int		ret;

//	while((ret = fscanf(file, "%c %f %f %f %c\n", &shape.type, &shape.x, &shape.y, &shape.radius, &shape.color)) == 5)
	while((ret = fscanf(file, "%c %f %f %f %f %c\n", &shape.type, &shape.x, &shape.y, &shape.w, &shape.h, &shape.color)) == 6)
	{
		// if ((shape.type != 'c' && shape.type != 'C') || shape.radius <= 0.)
		// 	return (0);
		if ((shape.type != 'r' && shape.type != 'R') || shape.w <= 0. || shape.h <= 0.)
			return (0);
		draw_shape(zone, bg, &shape);
	}
	if (ret != -1)
		return (0);
	return (1);
}

void	finish_draw(t_zone *zone, char *bg)
{
	int i = 0;

	while (i < zone->h)
	{
		write(1, bg + (i * zone->w), zone->w);
		write(1, "\n", 1);
		i++;
	}
}

int		main(int ac, char **av)
{
	FILE	*file;
	t_zone	zone;
	char	*bg;

	zone.w = 0;
	zone.h = 0;
	zone.bg_c = 0;
	bg = NULL;
	if (ac != 2)
		return (str_error("Error: argument\n"));
	if (!(file = fopen(av[1], "r")))
		return (str_error("Error: Operation file corrupted\n"));
	if (!(bg = get_zone(file, &zone)))
		return (clr_all(file, NULL) && str_error("Error: Operation file corrupted\n"));
	if (!(init_shapes(file, &zone, bg)))
		return (clr_all(file, bg) && str_error("Error: Operation file corrupted\n"));
	finish_draw(&zone, bg);
	clr_all(file, bg);
	return (0);
}