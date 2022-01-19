/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:30:27 by echerell          #+#    #+#             */
/*   Updated: 2022/01/19 22:42:18 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_HEIGHT 720
# define WIN_WIDTH 1280

# define COLOR_RED 0xFF0000
# define COLOR_ORANGE 0xFFA500
# define COLOR_YELLOW 0xFFFF00
# define COLOR_GREEN 0x008000
# define COLOR_DODGER_BLUE 0x1E90FF
# define COLOR_BLUE 0x0000FF
# define COLOR_PURPLE 0x800080
# define COLOR_WHITE 0xFFFFFF

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
	int	color;
}t_point;

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
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

}t_world;

typedef struct s_grad
{
	t_point	start;
	t_point end;
}t_grad;

void	run_prog(int fd);
int		check_map(int fd, t_world *world);
int		make_gradient(t_grad grad, t_point point);

void	get_maxmin_alt(t_world *world);
void	add_color(t_world *world);

int		error_occur(char **line, char ***data);
void	free_tmp(char **line, char ***data);
void	free_world(t_world *world);

#endif
