/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 21:35:22 by echerell          #+#    #+#             */
/*   Updated: 2022/01/20 19:31:32 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	calc_edge_coord(t_world *world, int id)
{
	if (!id)
	{
		world->x_min = world->mat[id].x_t;
		world->x_max = world->mat[id].x_t;
		world->y_min = world->mat[id].y_t;
		world->y_max = world->mat[id].y_t;
	}
	else
	{
		if (world->mat[id].x_t < world->x_min)
			world->x_min = world->mat[id].x_t;
		if (world->mat[id].x_t > world->x_max)
			world->x_max = world->mat[id].x_t;
		if (world->mat[id].y_t < world->y_min)
			world->y_min = world->mat[id].y_t;
		if (world->mat[id].y_t > world->y_max)
			world->y_max = world->mat[id].y_t;
	}
}

void	get_edge_coord(t_world *world)
{
	int	i;

	i = 0;
	while (i < world->total)
	{
		calc_edge_coord(world, i);
		i++;
	}
}

void	get_maxmin_alt(t_world *world)
{
	int	i;

	world->alt_max = ((world->mat)[0]).z;
	world->alt_min = ((world->mat)[0]).z;
	i = 1;
	while (i < world->total)
	{
		if (((world->mat)[i]).z > world->alt_max)
			world->alt_max = ((world->mat)[i]).z;
		if (((world->mat)[i]).z < world->alt_min)
			world->alt_min = ((world->mat)[i]).z;
		i++;
	}
}

void	change_alt(t_world *world, int keycode)
{
	if (keycode == KEY_Q)
		world->add_alt += 2;
	else
		world->add_alt -= 2;
	apply_changes(world, 1);
}

void	shift_world(t_world *world, int keycode)
{
	world->x_incr = 0;
	world->y_incr = 0;
	if (keycode == KEY_ARR_UP)
		world->y_incr = 10;
	else if (keycode == KEY_ARR_DOWN)
		world->y_incr = -10;
	else if (keycode == KEY_ARR_LEFT)
		world->x_incr = 10;
	else if (keycode == KEY_ARR_RIGHT)
		world->x_incr = -10;
	world->x_shift += world->x_incr;
	world->y_shift += world->y_incr;
	apply_changes(world, 2);
}
