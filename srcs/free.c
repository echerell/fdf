/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:08:47 by echerell          #+#    #+#             */
/*   Updated: 2022/01/19 23:50:58 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		error_occur(char **line, char ***data)
{
	free_tmp(line, data);
	ft_putstr_fd("Wrong data or no data in the file\n", STDOUT_FILENO);
	return (-1);
}

void	free_tmp(char **line, char ***data)
{
	int	i;

	if (line && *line)
		free(*line);
	*line = NULL;
	i = 0;
	if (*data)
	{
		while ((*data)[i])
		{
			free((*data)[i]);
			i++;
		}
		free((*data)[i]);
		free(*data);
		*data = NULL;
	}
}

void	free_world(t_world *world)
{
	if (world->mat)
		free(world->mat);
	world->mat = NULL;
	if (world->mlx.mlx_ptr && world->mlx.img_ptr)
		mlx_destroy_image(world->mlx.mlx_ptr, world->mlx.img_ptr);
	world->mlx.img_ptr = NULL;
	world->mlx.img_addr = NULL;
	if (world->mlx.mlx_ptr && world->mlx.win_ptr)
		mlx_destroy_window(world->mlx.mlx_ptr, world->mlx.win_ptr);
	world->mlx.mlx_ptr = NULL;
	world->mlx.win_ptr = NULL;
}
