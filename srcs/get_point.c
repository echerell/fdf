/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 00:42:40 by echerell          #+#    #+#             */
/*   Updated: 2022/01/20 00:47:53 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_x_point(t_world *world, int id, t_point p1, t_point *p2)
{
	if (p1.x == world->cols - 1)
		p2->x = -1;
	else
		*p2 = world->mat[id + 1];
}

void	get_y_point(t_world *world, int id, t_point p1, t_point *p2)
{
	if (p1.y == world->lines - 1)
		p2->y = -1;
	else
		*p2 = world->mat[id + world->cols];
}
