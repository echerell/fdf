/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 02:10:46 by echerell          #+#    #+#             */
/*   Updated: 2022/01/20 23:08:40 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_zoom(t_world *world)
{
	int		dx;
	int		dy;
	float	incr;

	if (world->total > 1)
	{
		incr = 0.0;
		dx = world->x_max - world->x_min;
		dy = world->y_max - world->y_min;
		if (dx < (WIN_WIDTH / 4) && dy < (WIN_HEIGHT / 4))
		{
			while ((dx / world->zoom) * (world->zoom + incr) < WIN_WIDTH
				&& (dy / world->zoom) * (world->zoom + incr) < WIN_HEIGHT)
				incr += 0.02;
		}
		else if (dx > (WIN_WIDTH) || dy > (WIN_HEIGHT))
		{
			while (incr < 0.98
				&& ((dx / world->zoom) * (world->zoom + incr) > WIN_WIDTH
					|| (dy / world->zoom) * (world->zoom + incr) > WIN_HEIGHT))
						incr -= 0.02;
		}
			world->zoom += incr;
	}
}

void	change_zoom(t_world *world, int keycode)
{
	if (keycode == KEY_PLUS)
		world->zoom += 0.02;
	else
	{
		if (world->zoom > 0.02)
			world->zoom -= 0.02;
	}
	apply_changes(world, 1);
}
