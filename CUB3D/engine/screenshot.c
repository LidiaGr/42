/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:29:50 by ttarsha           #+#    #+#             */
/*   Updated: 2020/09/15 14:49:19 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	init_bmp_header(int8_t *header, t_all *all)
{
	int16_t data_16bit;
	int32_t	data_32bit;

	ft_bzero(header, HEADER_SIZE);
	ft_memcpy(header + 0x00, "BM", 2);
	data_32bit = HEADER_SIZE;
	ft_memcpy(header + 0x0A, &data_32bit, sizeof(data_32bit));
	data_32bit = INFOHEADER_SIZE;
	ft_memcpy(header + 0x0E, &data_32bit, sizeof(data_32bit));
	data_32bit = all->win.width;
	ft_memcpy(header + 0x12, &data_32bit, sizeof(data_32bit));
	data_32bit = -all->win.height;
	ft_memcpy(header + 0x16, &data_32bit, sizeof(data_32bit));
	data_16bit = 1;
	ft_memcpy(header + 0x1A, &data_16bit, sizeof(data_16bit));
	data_16bit = all->img.bits_per_pixel;
	ft_memcpy(header + 0x1C, &data_16bit, sizeof(data_16bit));
}

void	ft_save_to_bmp(t_all *all)
{
	int8_t	*file_bmp;
	int		fd_screen;
	int		file_size;

	set_walls(0, all);
	file_size = HEADER_SIZE + all->img.line_length * all->win.height;
	file_bmp = malloc(file_size);
	init_bmp_header(file_bmp, all);
	ft_memcpy(file_bmp + HEADER_SIZE, all->img.addr, \
				file_size - HEADER_SIZE);
	fd_screen = open("screenshot.bmp", O_WRONLY | O_CREAT, \
					S_IRUSR | S_IWUSR | S_IROTH);
	if (fd_screen == -1)
		exit_game(EINVAL, "Fd bmp");
	if (write(fd_screen, file_bmp, file_size) == -1)
		exit_game(EINVAL, "Write bmp");
	free(file_bmp);
	close(fd_screen);
}
