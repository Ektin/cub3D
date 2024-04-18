/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgroeppm <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:40:38 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2024/04/19 00:21:31 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*	Initializes the data, assets, and map structures */

void	initialization(t_data *data)
{
	if (NULL == data)
	{
		print_error(-1, "initialization with NULL data");
		return ;
	}
	ft_memset(data, 0, sizeof(*data));
	ft_memset(&(data->texinfo), 0, sizeof(data->texinfo));
	ft_memset(&(data->map), 0, sizeof(data->map));
	ft_memset(&(data->player), 0, sizeof(data->player));
	fill_sin_cos_arr(data);
	data->win_width = WIN_WIDTH;
	data->win_height = WIN_HEIGHT;
}
// data->map->width = 2;
// data->map->height = 2;

int	start_all(int argc, char **argv, t_data *data)
{
	if (!data)
		return (print_error(-1, "NULL in initialize all"));
	initialization(data);
	check_argument(argc, argv);
	read_file(argv[1], data);
	parse_file(data);
	check_config(data);
	create_map(data);
	validate_map(data);
	init_mlx(data);
	init_textures(data);
	init_player(data);
	init_ray(data);
	print_data(data);
	return (0);
}

int	end_all(t_data *data)
{
	free_file(data);
	free_assets(data);
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data->player);
	data->player = NULL;
	free(data->ray);
	data->ray = NULL;
	free_array(data->map.map_arr);
	printf("Bye-bye\n");
	return (0);
}

int	main(int argc, char **argv)
{
	t_data		data;

	start_all(argc, argv, &data);
	draw_picture(&data);
	mlx_hook(data.win, 0, 0, donothing, NULL);
	mlx_hook(data.win, KeyPress, KeyPressMask, doifpress, &data);
	mlx_hook(data.win, DestroyNotify, 0, doifmouseexit, &data);
	mlx_loop(data.mlx);
	end_all(&data);
	return (0);
}
//mlx_loop_hook(data.mlx, donothing, NULL);
