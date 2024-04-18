/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:48:21 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2024/04/12 18:07:46 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_error_exit(t_data *data, char *message)
{
	printf("%s\n", message);
	free_file(data);
	free_assets(data);
	free_array(data->map.map_arr);
	free_textures(data);
	exit(1);
}

int	print_error(int res, char *msg)
{
	if (msg)
		printf("[%s]\n", msg);
	return (res);
}

void	error_exit(t_data *data, t_ErrorCode code)
{
	if (code == ERR_FILE_NOT_CUB)
		printf("file is not .cub\n");
	else if (code == ERR_FILE_READ)
		printf("error reading file\n");
	else if (code == ERR_FILE_IS_DIR)
		printf("is directory\n");
	else if (code == ERR_FILE_OPEN)
		printf("error opening file\n");
	else if (code == ERR_FILE_SIZE)
		printf("file too big\n");
	else if (code == ERR_IDENT)
		printf("Identifier error\n");
	else if (code == ERR_FLOOR_CEILING)
		printf("Floor / Ceiling error\n");
	else if (code == ERR_INVALID_MAP)
		printf("Invalid Map\n");
	free_file(data);
	free_assets(data);
	free(data->player);
	data->player = NULL;
	exit(1);
}
