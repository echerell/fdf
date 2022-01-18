/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:08:47 by echerell          #+#    #+#             */
/*   Updated: 2022/01/18 22:24:25 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		error_occur(char **line, char **data)
{
	free_tmp(line, data);
	ft_putstr_fd("Wrong data or no data in the file", STDOUT_FILENO);
	return (-1);
}

void	free_tmp(char **line, char **data)
{
	int	i;

	if (line)
		free(line);
	i = 0;
	if (data)
	{
		while (data[i])
		{
			free(data[i]);
			i++;
		}
		free(data);
	}
}

void	free_world(t_world *world)
{
	if (world->mat)
		free(world->mat);
	if (world->mlx.mlx_ptr && world->mlx.win_ptr)
		mlx_destroy_window(world->mlx.mlx_ptr, world->mlx.win_ptr);
}
