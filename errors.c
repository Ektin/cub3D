/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:48:21 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2024/04/12 18:10:59 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_textures(t_data *data)
{
	int	i;

	if (data->textures)
	{
		i = -1;
		while (++i < 5)
		{
			if (data->textures[i])
			{
				free(data->textures[i]);
				data->textures[i] = NULL;
			}
		}
		free(data->textures);
		data->textures = NULL;
	}
}
//for (int i = 0; i < 5; i++)

void	free_assets(t_data *data)
{
	free(data->texinfo.no_path);
	free(data->texinfo.so_path);
	free(data->texinfo.we_path);
	free(data->texinfo.ea_path);
	free_textures(data);
}

void	free_file(t_data *data)
{
	int	i;

	if (NULL == data)
		return ;
	i = -1;
	free(data->file);
	data->file = NULL;
	while (data->file_by_line && data->file_by_line[++i])
	{
		free(data->file_by_line[i]);
		data->file_by_line[i] = NULL;
	}
	free(data->file_by_line);
	data->file_by_line = NULL;
}

void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = -1;
	while (array[++i])
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array);
	array = NULL;
}
// does not have an impact on array
