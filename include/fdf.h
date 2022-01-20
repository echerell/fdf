/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:30:27 by echerell          #+#    #+#             */
/*   Updated: 2022/01/20 22:56:29 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_HEIGHT 720
# define WIN_WIDTH 1280

# define PI 3.14159265

# define COLOR_RED 0xFF0000
# define COLOR_ORANGE 0xFFA500
# define COLOR_YELLOW 0xFFFF00
# define COLOR_GREEN 0x008000
# define COLOR_DODGER_BLUE 0x1E90FF
# define COLOR_BLUE 0x0000FF
# define COLOR_PURPLE 0x800080
# define COLOR_WHITE 0xFFFFFF

# define KEY_ESC 65307
# define KEY_C 99
# define KEY_Q 113
# define KEY_A 97
# define KEY_R 114
# define KEY_ARR_UP 65362
# define KEY_ARR_DOWN 65364
# define KEY_ARR_LEFT 65361
# define KEY_ARR_RIGHT 65363
# define KEY_PLUS 61
# define KEY_MINUS 45
# define KEY_P 112
# define KEY_1 49
# define KEY_2 50
# define KEY_3 51
# define KEY_4 52
# define KEY_5 53
# define KEY_6 54
# define KEY_L 108

# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	x_t;
	int	y_t;
	int	z_t;
	int	color;
}t_point;

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_addr;
	int		bpp;
	int		line_len;
	int		endian;
}t_mlx_data;

typedef struct s_world
{
	t_point		*mat;
	t_mlx_data	mlx;
	int			lines;
	int			cols;
	int			total;
	int			alt_max;
	int			alt_min;
	int			color_num;
	int			color;
	int			proj;
	int			x_min;
	int			x_max;
	int			y_min;
	int			y_max;
	int			x_shift;
	int			y_shift;
	int			x_incr;
	int			y_incr;
	float		zoom;
	int			magn;
	int			add_alt;
	float		x_rot;
	float		y_rot;
	float		z_rot;
	int			legend;
}t_world;

typedef struct s_grad
{
	t_point	start;
	t_point	end;
}t_grad;

typedef struct s_rot_data
{
	float	x_cos;
	float	x_sin;
	float	y_cos;
	float	y_sin;
	float	z_cos;
	float	z_sin;
}t_rot_data;

void	run_prog(int fd);
int		check_map(int fd, t_world *world);
int		make_gradient(t_grad grad, t_point point, char axis);

void	get_maxmin_alt(t_world *world);
void	get_edge_coord(t_world *world);

void	add_color(t_world *world);

void	apply_changes(t_world *world, int shift);
void	apply_proj(t_world *world, t_point *p);
void	set_rot_data(t_world *world, t_rot_data *data);
void	apply_rot(t_world *world, t_point *p, t_rot_data *d);

void	init_zoom(t_world *world);
void	center(t_world *world);

void	display_world(t_world *world);
void	get_x_point(t_world *world, int id, t_point p1, t_point *p2);
void	get_y_point(t_world *world, int id, t_point p1, t_point *p2);
void	draw_line(t_mlx_data *data, t_point p1, t_point p2);

int		key_event(int keycode, void *param);
void	change_alt(t_world *world, int keycode);
void	shift_world(t_world *world, int keycode);
void	reset_world(t_world *world);
void	change_zoom(t_world *world, int keycode);
void	change_proj(t_world *world);
void	change_rot(t_world *world, int keycode);

int		error_occur(char **line, char ***data);
void	free_tmp(char **line, char ***data);
void	free_world(t_world *world);

#endif
