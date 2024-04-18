/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:44:42 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2024/04/13 15:31:05 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_outside_the_map(t_point point, t_map *map)
{
	if (!map)
		return (print_error(1, "invalid map"));
	if (point.x < 1)
		return (print_error(1, "too small x coordinate"));
	if (point.x > map->width)
		return (print_error(1, "too large x coordinate"));
	if (point.y < 1)
		return (print_error(1, "too little y coordinate"));
	if (point.y > map->height)
		return (print_error(1, "too large y coordinate"));
	return (0);
}

int	assign_side_return_one(t_intpoint intpoint, t_point point, \
					t_point pointinit, char *side)
{
	if (fabs(point.x - intpoint.x) < EPS || \
			fabs(point.x - intpoint.x - 1) < EPS)
	{
		if (point.x > pointinit.x && NULL != side)
			*side = 'W';
		else if (point.x <= pointinit.x && NULL != side)
			*side = 'E';
		return (1);
	}
	if (fabs(point.y - intpoint.y) < EPS || \
		fabs(point.y - intpoint.y - 1) < EPS)
	{
		if (point.y > pointinit.y && NULL != side)
			*side = 'N';
		else if (point.y <= pointinit.y && NULL != side)
			*side = 'S';
		return (1);
	}
	if (NULL != side)
		*side = 0;
	return (print_error(-2, "talking from inside the wall?"));
}

int	is_on_the_wall(t_point point, t_point pointinit, \
					char *side, t_map *map)
{
	int		intx;
	int		inty;
	int		i;
	int		j;

	if (is_outside_the_map(point, map))
		return (print_error(-1, "wrong in is_on_the_wall"));
	i = -1;
	while (++i < 2)
	{
		j = -1;
		while (++j < 2)
		{
			intx = (int)(point.x + 2 * EPS * (2 * j - 1));
			inty = (int)(point.y + 2 * EPS * (2 * i - 1));
			if ('1' == map->map_arr[inty][intx])
			{
				return (assign_side_return_one(mkintpnt(intx, \
					inty), point, pointinit, side));
			}
			if ('x' == map->map_arr[inty][intx])
				return (print_error(-1, "wrong:'x' in is_on_the_wall"));
		}
	}
	return (0);
}

// returns distance to the next point on the grid
double	next_grid_point(t_point *nextpoint, t_point point, \
				t_ray *ray)
{
	double	epsx;
	double	epsy;

	ray->angle = ft_modangle(ray->angle);
	if (point.x < 1 || point.y < 1)
		print_error(-1, "next_grid_point problem: wrong input");
	nextpoint->x = getnextx(point.x, ray);
	epsx = 10.0;
	if (fabs(90.0 - ray->angle) > EPS && fabs(90 + ray->angle) > EPS)
		epsx = (nextpoint->x - point.x) / ray->cosangle;
	nextpoint->y = getnexty(point.y, ray);
	epsy = 10.0;
	if (fabs(ray->angle) > EPS && fabs(ray->angle - 180.0) > EPS && \
				fabs(ray->angle + 180.0) > EPS)
		epsy = - (nextpoint->y - point.y) / ray->sinangle;
	if ((epsx < EPS || epsy < EPS) || (epsx > 5.0 && epsy > 5.0))
		printf("Impossible in next_grid_point: epsx=%f, epsy=%f\n", epsx, epsy);
	if (epsx <= epsy)
		nextpoint->y = point.y - epsx * ray->sinangle;
	else
		nextpoint->x = point.x + epsy * ray->cosangle;
	if (epsx <= epsy)
		return (epsx);
	return (epsy);
}

// we should think of a situation, that our point is on the wall, and the
// next point is also on the wall. Here two different scenarios are possible:
// they are on the same wall, or on different walls.
// We check for this by checking if a middle point is on the wall or not.
// Also we should take into account the situation, when we move just 
// along the wall.
// UPDATE: we cannot handle it. So, prohibit the character to be exactly 
// on the wall.

double	getdistance(double angle, t_ray *ray)
{
	t_point	nextpoint;
	char	side;

	if (is_outside_the_map(ray->init_point, &ray->data->map))
		return ((double)print_error(-1, "outside the map in getdistance"));
	set_angle_in_ray(ray, angle);
	ray->dist_to_wall = next_grid_point(&nextpoint, ray->init_point, ray);
	while (0 == is_on_the_wall(nextpoint, ray->init_point, &side, \
							&ray->data->map))
		ray->dist_to_wall += next_grid_point(&nextpoint, nextpoint, ray);
	if (0 != is_on_the_wall(mkpnt(ray->init_point.x * 0.5 + nextpoint.x * 0.5, \
					ray->init_point.y * 0.5 + nextpoint.y * 0.5), \
		ray->init_point, NULL, &ray->data->map))
	{
		ray->wall_point.x = ray->init_point.x;
		ray->wall_point.y = ray->init_point.y;
		ray->dist_to_wall = 0.0;
		return (0.0);
	}
	ray->side = side;
	ray->wall_point.x = nextpoint.x;
	ray->wall_point.y = nextpoint.y;
	ray->fish_dist_to_wall = ray->dist_to_wall * \
		ft_cos(ray->main_angle - ray->angle, ray->data);
	return (ray->dist_to_wall);
}
