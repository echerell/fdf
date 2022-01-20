/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 21:54:38 by echerell          #+#    #+#             */
/*   Updated: 2022/01/20 22:56:53 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	set_world_color(t_world *world)
{
	if (world->color_num == 0)
		return (COLOR_RED);
	if (world->color_num == 1)
		return (COLOR_ORANGE);
	if (world->color_num == 2)
		return (COLOR_YELLOW);
	if (world->color_num == 3)
		return (COLOR_GREEN);
	if (world->color_num == 4)
		return (COLOR_BLUE);
	if (world->color_num == 5)
		return (COLOR_DODGER_BLUE);
	return (COLOR_PURPLE);
}

static void	set_point_color(t_world *world, t_point *p)
{
	t_grad	grad;

	grad.start.z = world->alt_min;
	grad.end.z = world->alt_max;
	grad.start.color = world->color;
	if (world->alt_min == world->alt_max)
		grad.end.color = world->color;
	else
		grad.end.color = COLOR_WHITE;
	p->color = make_gradient(grad, *p, 'z');
}

void	add_color(t_world *world)
{
	int	i;

	world->color = set_world_color(world);
	i = 0;
	while (i < world->total)
	{
		set_point_color(world, &(world->mat[i]));
		i++;
	}
}
