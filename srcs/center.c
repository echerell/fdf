/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 01:59:08 by echerell          #+#    #+#             */
/*   Updated: 2022/01/20 02:55:35 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	center(t_world *world)
{
	int	dx;
	int	dy;

	get_edge_coord(world);
	dx = world->x_max - world->x_min;
	dy = world->y_max - world->y_min;
	world->x_incr = 0;
	world->y_incr = 0;
	world->x_incr = (WIN_WIDTH / 2) - (dx / 2) - world->x_min;
	world->y_incr = (WIN_HEIGHT / 2) - (dy / 2) - world->y_min;
	world->x_shift += world->x_incr;
	world->y_shift += world->y_incr;
	apply_changes(world, 2);
}
