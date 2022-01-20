/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 01:14:29 by echerell          #+#    #+#             */
/*   Updated: 2022/01/20 22:13:00 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_proj(t_world *world)
{
	if (world->proj == 2)
		world->proj = 1;
	else
		world->proj = 2;
	apply_changes(world, 1);
	get_edge_coord(world);
	init_zoom(world);
	apply_changes(world, 1);
	center(world);
}

static void	isometric(t_point *p)
{
	int	tmp_x_t;
	int	tmp_y_t;

	tmp_x_t = p->x_t;
	tmp_y_t = p->y_t;
	p->x_t = (tmp_x_t - tmp_y_t) * cos(35 * PI / 180);
	p->y_t = -(p->z_t) + (tmp_x_t + p->y_t) * sin(35 * PI / 180);
}

static void	cabinet(t_point *p)
{
	int	tmp_x_t;
	int	tmp_y_t;

	tmp_x_t = p->x_t;
	tmp_y_t = p->y_t;
	p->x_t = tmp_x_t + p->z_t * cos(-1) * 0.5;
	p->y_t = tmp_y_t + p->z_t * sin(-1) * 0.5;
}

void	apply_proj(t_world *world, t_point *p)
{
	if (world->proj == 1)
		isometric(p);
	else
		cabinet(p);
}
