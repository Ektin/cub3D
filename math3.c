/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:43:42 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2024/04/18 23:00:34 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_intmin(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_intmax(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_floor(double x)
{
	int	res;

	if (x >= 0)
		return ((int) x);
	res = (int) x;
	if (res > x)
		return (res - 1);
	return (res);
}
