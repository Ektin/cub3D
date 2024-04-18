/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:31:13 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2024/04/13 19:16:16 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	interwine_ray_to_data(t_ray *ray, t_data *data)
{
	if (NULL == ray)
		return (print_error(-1, "ray is NULL in init_ray"));
	ray->data = data;
	return (0);
}

int	set_angle_in_ray(t_ray *ray, double angle)
{
	if (!ray)
		return (print_error(-1, "NULL ray in set_angle_in_ray"));
	ray->angle = ft_modangle(angle);
	ray->sinangle = ft_sin(ray->angle, ray->data);
	ray->cosangle = ft_cos(ray->angle, ray->data);
	return (0);
}

int	set_init_point_in_ray(t_ray *ray, t_point point)
{
	if (!ray)
		return (print_error(-1, "NULL ray in set_init_point_in_ray"));
	ray->init_point.x = point.x;
	ray->init_point.y = point.y;
	return (0);
}

int	set_main_angle_in_ray(t_ray *ray, int main_angle)
{
	if (!ray)
		return (print_error(-1, "NULL ray in set_main_angle_in_ray"));
	ray->main_angle = main_angle;
	return (0);
}
