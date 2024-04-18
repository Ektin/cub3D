/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:33:25 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2024/04/19 00:16:23 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	donothing(void *data)
{
	(void)data;
	return (0);
}

int	doifmouseexit(t_data *data)
{
	mlx_loop_end(data->mlx);
	if (VERBATIM)
		printf("Mouse closed the window\n");
	return (0);
}

int	doifpress(int keycode, t_data *data)
{
	if (XK_Escape == keycode)
		mlx_loop_end(data->mlx);
	else if (XK_Right == keycode)
		do_if_right_pressed(data);
	else if (XK_Left == keycode)
		do_if_left_pressed(data);
	else if ('w' == keycode)
		do_if_w_pressed(data);
	else if ('d' == keycode)
		do_if_d_pressed(data);
	else if ('a' == keycode)
		do_if_a_pressed(data);
	else if ('s' == keycode)
		do_if_s_pressed(data);
	if (VERBATIM && ft_isprint((char)keycode))
		printf("[%d][%c] presssed\n", keycode, (char) keycode);
	else if (VERBATIM)
		printf("[%d][%d] pressed\n", keycode, keycode);
	if (VERBATIM)
		fflush(stdout);
	return (0);
}
// printf("[%d][%c] pressed\n", keycode, (char) keycode); do not do it!!!
// printf("[%c]\n", 27); got stuck: escape is printed as %c.
// fine with fr_printf or write, bad with printf
