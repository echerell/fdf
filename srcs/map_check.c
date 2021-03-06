/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:18:02 by echerell          #+#    #+#             */
/*   Updated: 2022/01/20 23:07:23 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	split_line(char **line, char ***data)
{
	*data = ft_split(*line, ' ');
	if (!(*data))
		return (0);
	if (!((*data)[0]))
		return (0);
	return (1);
}

static int	check_cols(t_world *world, char **data)
{
	int	i;

	i = 0;
	if (world->cols == -1)
	{
		while (data[i])
			i++;
		world->cols = i;
		return (1);
	}
	else
	{
		while (data[i])
			i++;
	}
	return ((i == world->cols));
}

static int	add_matrix(t_world *world, char **data)
{
	t_point	*matrix;
	int		i;
	int		start;

	i = 0;
	start = world->cols * (world->lines - 1);
	matrix = (t_point *)malloc(world->cols * world->lines * sizeof(t_point));
	if (!matrix)
		return (0);
	if (world->mat)
		ft_memcpy(matrix, world->mat, world->cols * (world->lines - 1)
			* sizeof(t_point));
	while (data[i])
	{
		matrix[start + i].x = i;
		matrix[start + i].y = world->lines - 1;
		matrix[start + i].z = ft_atoi(data[i]);
		i++;
	}
	free(world->mat);
	world->mat = matrix;
	return (1);
}
/*
static void	print_data(t_world *world)
{
	int i;

	i = 0;
	if (world->mat)
	{
		ft_putstr_fd("X matrix: \n", STDOUT_FILENO);
		while (i < world->total)
		{
			ft_putnbr_fd(world->mat[i].x, STDOUT_FILENO);
			ft_putchar_fd(' ', STDOUT_FILENO);
			if (i > 0 && (i + 1) % world->cols == 0)
				ft_putchar_fd('\n', STDOUT_FILENO);
			i++;
		}
		i = 0;
		ft_putstr_fd("Y matrix: \n", STDOUT_FILENO);
		while (i < world->total)
		{
			ft_putnbr_fd(world->mat[i].y, STDOUT_FILENO);
			ft_putchar_fd(' ', STDOUT_FILENO);
			if (i > 0 && (i + 1) % world->cols == 0)
				ft_putchar_fd('\n', STDOUT_FILENO);
			i++;
		}
		i = 0;
		ft_putstr_fd("Z matrix: \n", STDOUT_FILENO);
		while (i < world->total)
		{
			ft_putnbr_fd(world->mat[i].z, STDOUT_FILENO);
			ft_putchar_fd(' ', STDOUT_FILENO);
			if (i > 0 && (i + 1) % world->cols == 0)
				ft_putchar_fd('\n', STDOUT_FILENO);
			i++;
		}
	}
}
*/

static void	free_error(t_world *world, int ret, char **line, char ***data)
{
	if (ret < 1)
	{
		free_tmp(line, data);
		if (world->lines == 0)
			ft_putstr_fd("Wrong data or no data in the file\n", STDOUT_FILENO);
		if (ret == -1)
			perror("Error");
	}
}

int	check_map(int fd, t_world *world)
{
	char	*line;
	char	**data;
	int		ret;

	line = NULL;
	data = NULL;
	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		world->lines++;
		if (!split_line(&line, &data))
			return (error_occur(&line, &data));
		if (!check_cols(world, data))
			return (error_occur(&line, &data));
		world->total += world->cols;
		if (!add_matrix(world, data))
			return (error_occur(&line, &data));
		free_tmp(&line, &data);
		ret = get_next_line(fd, &line);
	}
	free_error(world, ret, &line, &data);
	return (ret);
}
