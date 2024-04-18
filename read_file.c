/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:04:04 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2024/04/12 17:08:58 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r');
}

void	check_argument(int argc, char **argv)
{
	int	len;

	if (argc != 2)
	{
		printf("Error\nUsage: ./cub3D mapname.cub\n");
		exit(1);
	}
	len = ft_strlen(argv[1]);
	if (len < 4)
	{
		printf("Error\nFilename too short\n");
		exit(1);
	}
	if (ft_strncmp(argv[1] + len - 4, ".cub", 4) != 0)
	{
		printf("Error\nWrong filename! use .cub\n");
		exit(1);
	}
}

static int	prepare_file(char *path, t_data *data, char **buffer)
{
	int	fd;

	*buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*buffer)
		print_error_exit(data, "Error\nFailed to allocate memory for buffer");
	data->file = ft_strdup("");
	if (!data->file)
	{
		free(*buffer);
		print_error_exit(data,
			"Error\nFailed to duplicate string for file data");
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		free(*buffer);
		print_error_exit(data, "Error\nFailed to open file");
	}
	return (fd);
}

static void	read_and_concatenate(int fd, t_data *data, char *buffer)
{
	int		bytes_read;
	char	*tmp;

	tmp = NULL;
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(data->file, buffer);
		free(data->file);
		data->file = ft_strdup(tmp);
		if (!data->file)
			print_error_exit(data, "Error\nFailed duplicate string file data");
		free(tmp);
	}
	if (bytes_read == -1)
	{
		free(buffer);
		close(fd);
		print_error_exit(data, "Error\nFailed to read file");
	}
	close(fd);
	free(buffer);
}

void	read_file(char *path, t_data *data)
{
	char	*buffer;
	int		fd;

	fd = prepare_file(path, data, &buffer);
	read_and_concatenate(fd, data, buffer);
}
