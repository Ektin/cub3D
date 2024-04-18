/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgroeppm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:29:06 by tgroeppm          #+#    #+#             */
/*   Updated: 2024/04/18 22:41:57 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// init_img_clean(image);
void	init_texture_img(t_data *data, t_img *image, char *path)
{
	image->img = mlx_xpm_file_to_image(data->mlx, path, &data->texinfo.size,
			&data->texinfo.size);
	if (image->img == NULL)
		print_error_exit(data, "mlx error/n");
	image->addr = mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}

/* The function xpm_to_img is used to convert an XPM (X PixMap) image file 
into an array of integers, 
where each integer represents a pixel in the image. 
The function takes two parameters: a pointer to the main data structure
(t_data *data),
and the path to the XPM file (char *path). */

static int	*xpm_to_img(t_data *data, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	init_texture_img(data, &tmp, path);
	buffer = ft_calloc(1,
			sizeof(*buffer) * data->texinfo.size * data->texinfo.size);
	if (!buffer)
		print_error_exit(data, "malloc error/n");
	y = 0;
	while (y < data->texinfo.size)
	{
		x = 0;
		while (x < data->texinfo.size)
		{
			buffer[y * data->texinfo.size + x] = \
			*((int *)tmp.addr + y * data->texinfo.size + x);
			++x;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, tmp.img, 100, 10);
	mlx_destroy_image(data->mlx, tmp.img);
	return (buffer);
}

void	init_textures(t_data *data)
{
	data->texinfo.size = TEX_SIZE;
	data->texinfo.hex_floor = (data->map.floor.red << 16) | \
		(data->map.floor.green << 8) | data->map.floor.blue;
	data->texinfo.hex_ceiling = (data->map.ceiling.red << 16) | \
		(data->map.ceiling.green << 8) | data->map.ceiling.blue;
	data->textures = ft_calloc(5, sizeof(*data->textures));
	if (!data->textures)
		print_error_exit(data, "mlx error/n");
	data->textures[NORTH] = xpm_to_img(data, data->texinfo.no_path);
	data->textures[EAST] = xpm_to_img(data, data->texinfo.ea_path);
	data->textures[SOUTH] = xpm_to_img(data, data->texinfo.so_path);
	data->textures[WEST] = xpm_to_img(data, data->texinfo.we_path);
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		print_error_exit(data, "mlx error/n");
	data->win = mlx_new_window(data->mlx, data->win_width, \
					data->win_height, "Cub3D");
	if (!data->win)
		print_error_exit(data, "mlx error/n");
	data->img.img = mlx_new_image(data->mlx, \
			data->win_width, data->win_height);
	data->img.addr = mlx_get_data_addr(data->img.img, \
					&data->img.pixel_bits, \
					&data->img.size_line, \
					&data->img.endian);
	return ;
}
