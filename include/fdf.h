/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:30:27 by echerell          #+#    #+#             */
/*   Updated: 2022/01/18 23:45:46 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_HEIGHT 720
# define WIN_WIDTH 1280

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
}t_world;

void	run_prog(int fd);
int		check_map(int fd, t_world *world);

int		error_occur(char **line, char **data);
void	free_tmp(char **line, char **data);
void	free_world(t_world *world);

#endif
