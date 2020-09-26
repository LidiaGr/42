/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:29:50 by ttarsha           #+#    #+#             */
/*   Updated: 2020/09/15 14:47:41 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <sys/errno.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

# define FILEHEADER_SIZE 14
# define INFOHEADER_SIZE 40
# define HEADER_SIZE (FILEHEADER_SIZE + INFOHEADER_SIZE)

# define ESC 53
# define A 0
# define D 2
# define W 13
# define S 1
# define LEFT 123
# define RIGHT 124

typedef struct		s_mlx
{
	void			*ptr;
}					t_mlx;

typedef struct		s_win
{
	void			*ptr;
	int				width;
	int				height;
}					t_win;

typedef struct		s_img
{
	void			*ptr;
	int				*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}					t_img;

typedef struct		s_map
{
	char			*map_arr;
	int				width;
	int				height;
}					t_map;

typedef struct		s_tex
{
	t_img			tex[6];
	char			*path[6];
	unsigned int	rgb_f;
	unsigned int	rgb_c;
	int				flag_c;
	int				flag_f;
}					t_tex;

typedef struct		s_player
{
	double			x;
	double			y;
	double			dir;
	double			fov;
}					t_player;

typedef struct		s_ray
{
	double			x;
	double			y;
	double			dist;
	double			dir;
	int				col_h;
}					t_ray;

typedef	struct		s_sprite
{
	double			x;
	double			y;
	double			dir;
	double			dist;
	int				screen_size;
	int				hor_offset;
	int				vert_offset;
	void			*next;
}					t_sprite;

typedef struct		s_tools
{
	double			depth_buffer[1920];
	int				save;
}					t_tools;

typedef struct		s_all
{
	t_mlx			mlx;
	t_win			win;
	t_img			img;
	t_map			map;
	t_player		player;
	t_ray			ray;
	t_tex			tex;
	t_sprite		*sprite;
	t_tools			tools;
}					t_all;

int					close_win(t_all *all);
void				key_check(int key, t_all *all);
void				ft_save_to_bmp(t_all *all);
void				set_sprite_position(t_all *all, double tmp_x, double tmp_y);
void				sprite_to_draw(t_all *all);
void				init_picture(t_all *all);
void				init_pre(t_all *all);
void				init_ray(t_all *all);
int					set_walls(int keycode, t_all *all);
void				create_map_arr(char **arr, int map_start, t_all *all);
void				find_player(char **arr, int map_start, t_all *all);
void				free_arr(char **arr, int lines);
int					ft_check_tail(char *s);
int					num_len_base(int num, int base);
void				p_map(char **arr, int map_start, t_all *all);
void				ft_color_check(char *s, t_all *all);
void				ft_tex_check(char *s, t_all *all);
void				p_res(char *s, t_all *all);
int					ft_name_check(char *s1, char *s2);
void				ft_parser(t_all *all, int *fd);
void				exit_game(int error_num, char *str);
int					get_next_line(char **line, int fd);

#endif
