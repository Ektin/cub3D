/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:50:26 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2024/04/19 00:20:37 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../src/libft/libft.h"
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <string.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx.h"

# define TEX_SIZE 64
# define BUFFER_SIZE 100
# define MIN_FILE_SIZE 17

# define WIN_WIDTH 640
# define WIN_HEIGHT 480

# define EPS 1e-6
# define PI 3.14159265358979

# define VERBATIM 0

typedef enum e_ErrorCode
{
	ERR_USAGE,
	ERR_FILE_NOT_CUB,
	ERR_FILE_OPEN,
	ERR_IDENT,
	ERR_FILE_READ,
	ERR_FILE_SIZE,
	ERR_FILE_NOT_XPM,
	ERR_FILE_IS_DIR,
	ERR_FLOOR_CEILING,
	ERR_COLOR_FLOOR,
	ERR_COLOR_CEILING,
	ERR_INVALID_MAP,
	ERR_INV_LETTER,
	ERR_NUM_PLAYER,
	ERR_TEX_RGB_VAL,
	ERR_TEX_MISSING,
	ERR_TEX_INVALID,
	ERR_COLOR_MISSING,
	ERR_MAP_MISSING,
	ERR_MAP_TOO_SMALL,
	ERR_MAP_NO_WALLS,
	ERR_MAP_LAST,
	ERR_PLAYER_POS,
	ERR_PLAYER_DIR,
	ERR_MALLOC,
	ERR_MLX_START,
	ERR_MLX_WIN,
	ERR_MLX_IMG,
	ERR_COUNT
}	t_ErrorCode;
//ERR_COUNT : This is the total number of error codes

typedef enum e_Identifier
{
	ID_NO,
	ID_SO,
	ID_WE,
	ID_EA,
	ID_F,
	ID_C,
	ID_MAP,
	ID_EMPTY,
	ID_UNKNOWN
}	t_identifie;

enum e_texture_index
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

///////////////// not yet used////////////////////////

/*typedef struct s_player
{
	//char	dir;
	double	pos_x;
	double	pos_y;
	//double	dir_x;
	//double	dir_y;
	//double	plane_x;
	//double	plane_y;
	double	anglerad;
	int		angledeg;
	int		has_moved;
	//int		move_x;
	//int		move_y;
	int		rotate;
}	t_player;*/

typedef struct s_player
{
	double	x;
	double	y;
	int		angledeg;
	int		halfanglespan;
	double	deltal;
	int		deltaphi;
	double	step_angle_to_draw;
	double	viewzoom;
}	t_player;

//////////////////////////////////////////////////////

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_color
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	bool			color_ok;
}			t_color;

typedef struct s_texinfo
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		size;
	int		hex_floor;
	int		hex_ceiling;
}			t_texinfo;

typedef struct s_map
{
	int			player_x;
	int			player_y;
	char		player_direction;
	int			p_count;
	int			width;
	int			height;
	t_color		ceiling;
	t_color		floor;
	bool		map_parsing; // indicates, if map parsing has started
	char		**map_start; // pointer to the map part of file_by_line
	char		**map_arr;
}				t_map;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_img			img_north;
	t_img			img_south;
	t_img			img_east;
	t_img			img_west;
	int				win_height;
	int				win_width;

	int				**texture_pixels;
	int				**textures;

	char			*file;

	char			**file_by_line;
	t_player		*player;
	struct s_ray	*ray;
	t_texinfo		texinfo;
	t_map			map;

	double			sinarr[46];
	double			cosarr[46];
}				t_data;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_intpoint
{
	int	x;
	int	y;
}	t_intpoint;

/*typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;*/

typedef struct s_ray
{
	t_point	init_point;
	t_point	wall_point;
	double	angle;
	int		main_angle;
	char	side;
	double	sinangle;
	double	cosangle;
	double	dist_to_wall;
	double	fish_dist_to_wall;
	t_data	*data;
}	t_ray;

////////////////////////////////////////////

// errors.c //needed
// void		error_exit_read(int exit_code);
// void		free_map(t_map *map);
// void		error_exit_map(int exit_code, t_map *map);
// void		check_asset_error(t_data *image);
void		free_textures(t_data *data);
void		free_assets(t_data *data);
void		free_file(t_data *data);
void		free_array(char **array);
void		print_error_exit(t_data *data, char *message);
int			print_error(int res, char *msg);
void		error_exit(t_data *data, t_ErrorCode code);

// parse_file.c //needed
void		parse_file(t_data *data);

// parse_file_2.c //needed
t_identifie	get_identifier(char *str);
void		check_config(t_data *data);
// char		*get_config_path(t_data *data, char *line);
void		set_path(char *line, t_data *data, t_identifie id);

// read_file.c //needed
bool		ft_isspace(int c);
void		check_argument(int argc, char **argv);
void		read_file(char *path, t_data *data);

// parse_map.c //needed
void		check_invalid_char(char *line, t_data *data);
void		create_map(t_data *data);

// debug.c //needed
void		print_color(t_color color);
void		print_map(t_map *map);
void		print_floor_and_ceiling_colors(t_texinfo *texinfo);
void		print_asset(t_texinfo *asset);
void		print_data(t_data *data);

// map_check.c //needed
void		check_invalid_char(char *line, t_data *data);
void		validate_map(t_data *data);

// init.c //needed
void		init_texture_img(t_data *data, t_img *image, char *path);
void		init_textures(t_data *data);
void		init_mlx(t_data *data);

// init2.c
int			fill_sin_cos_arr(t_data *data);
int			init_player(t_data *data);
int			init_ray(t_data *data);

// events.c
int			donothing(void *data);
int			doifmouseexit(t_data *data);
int			doifpress(int keycode, t_data *data);

// events2.c
void		do_if_right_pressed(t_data *data);
void		do_if_left_pressed(t_data *data);

// events3.c
void		do_if_w_pressed(t_data *data);
void		do_if_a_pressed(t_data *data);
void		do_if_s_pressed(t_data *data);
void		do_if_d_pressed(t_data *data);
//void		do_if_p_pressed(t_data *data);

// point.c
t_point		mkpnt(double x, double y);
t_intpoint	mkintpnt(int x, int y);

// distance.c
int			is_outside_the_map(t_point point, t_map *map);
int			assign_side_return_one(t_intpoint intpoint, \
			t_point point, t_point pointinit, char *side);
int			is_on_the_wall(t_point point, \
			t_point pointinit, char *side, t_map *map);
double		next_grid_point(t_point *next, t_point pnt, t_ray *ray);
double		getdistance(double angle, t_ray *ray);

// distance2.c
double		getnextx(double x, t_ray *ray);
double		getnexty(double y, t_ray *ray);

// math.c
double		fabs(double num);
double		distL1(t_point p1, t_point p2);
int			modangle(int angle);
double		ft_modangle(double angle);
double		mypow(double x, int i);

// math2.c
double		mysin(int angle, t_data *data);
double		mycos(int angle, t_data *data);
double		ft_sin(double angle, t_data *data);
double		ft_cos(double angle, t_data *data);

// math3.c
int			ft_intmin(int a, int b);
int			ft_intmax(int a, int b);
int			ft_floor(double x);

// main.c
void		initialization(t_data *data);

//ray.c
int			interwine_ray_to_data(t_ray *ray, t_data *data);
int			set_angle_in_ray(t_ray *ray, double angle);
int			set_init_point_in_ray(t_ray *ray, t_point point);
int			set_main_angle_in_ray(t_ray *ray, int main_angle);

// draw_picture.c
void		reset_image(t_data *data);
int			draw_picture(t_data *data);
int			draw_vertline_raycast(int j, t_data *data);

// draw2.c
int			get_tmpx(t_data *data);
int			get_color_of_pixel(int i, t_intpoint i_min_max, \
						int tmpx, t_data *data);
void		paint_point(int i, int j, int color, t_data *data);

#endif
