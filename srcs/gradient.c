/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 22:38:16 by echerell          #+#    #+#             */
/*   Updated: 2022/01/19 22:53:53 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	color_percent(int start, int end, int point_z)
{
	float	dist;
	float	pos;

	dist = (float)end - (float)start;
	pos = (float)point_z - (float)start;
	if (!dist)
		return (1.0);
	return (pos / dist);

}

static int	get_grad_mix(int start_col, int end_col, float per)
{
	return ((int)(start_col * (1 - per) + end_col * per));
}

int	make_gradient(t_grad grad, t_point point)
{
	int		r;
	int		g;
	int		b;
	float	per;

	per = color_percent(grad.start.z, grad.end.z, point.z);
	r = get_grad_mix((grad.start.color >> 16) & 0xFF,
		(grad.end.color >> 16) & 0xFF, per);
	g = get_grad_mix((grad.start.color >> 8) & 0xFF,
		(grad.end.color >> 8) & 0xFF, per);
	b = get_grad_mix(grad.start.color & 0xFF,
		grad.end.color & 0xFF, per);
	return (r << 16 | g << 8 | b);
}
