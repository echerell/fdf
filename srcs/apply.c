/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 01:07:45 by echerell          #+#    #+#             */
/*   Updated: 2022/01/20 23:18:14 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	alt_zoom(t_world *world)
{
	int	i;

	i = 0;
	while (i < world->total)
	{
		world->mat[i].z_t = world->mat[i].z * world->add_alt * world->zoom;
		world->mat[i].x_t = world->mat[i].x * world->magn * world->zoom;
		world->mat[i].y_t = world->mat[i].y * world->magn * world->zoom;
		i++;
	}
}

static void	rot_proj_shift(t_world *world)
{
	int			i;
	t_rot_data	data;

	i = 0;
	set_rot_data(world, &data);
	get_edge_coord(world);
	while (i < world->total)
	{
		apply_rot(world, &(world->mat[i]), &data);
		apply_proj(world, &(world->mat[i]));
		world->mat[i].x_t += world->x_shift;
		world->mat[i].y_t += world->y_shift;
		i++;
	}
}

void	apply_changes(t_world *world, int shift)
{
	int	i;

	if (shift == 1)
	{
		alt_zoom(world);
		rot_proj_shift(world);
	}
	else
	{
		i = 0;
		while (i < world->total)
		{
			world->mat[i].x_t += world->x_incr;
			world->mat[i].y_t += world->y_incr;
			i++;
		}
	}
}
