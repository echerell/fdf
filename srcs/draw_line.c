/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 00:00:06 by echerell          #+#    #+#             */
/*   Updated: 2022/01/21 01:14:55 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fill_img_data(t_mlx_data *data, t_point p1, int color)
{
	int	r;
	int	g;
	int	b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	(data->img_addr)[p1.x_t * 4 + data->line_len * p1.y_t] = b;
	(data->img_addr)[p1.x_t * 4 + data->line_len * p1.y_t + 1] = g;
	(data->img_addr)[p1.x_t * 4 + data->line_len * p1.y_t + 2] = r;
	(data->img_addr)[p1.x_t * 4 + data->line_len * p1.y_t + 3] = 0;
}

static int	print_line_img_case1(t_mlx_data *data, t_point p1, t_point p2,
		t_grad grad)
{
	int	e;
	int	dx;
	int	dy;
	int	y_incr;

	dx = p2.x_t - p1.x_t;
	dy = abs(p2.y_t - p1.y_t);
	y_incr = -1;
	if (p2.y_t >= p1.y_t)
		y_incr = 1;
	e = (2 * dy) + dx;
	while (p1.x_t <= p2.x_t)
	{
		e -= (2 * dy);
		if (e <= 0)
		{
			p1.y_t += y_incr;
			e += (2 * dx);
		}
		if (0 <= p1.x_t && p1.x_t < WIN_WIDTH && 0 <= p1.y_t
			&& p1.y_t < WIN_HEIGHT)
			fill_img_data(data, p1, make_gradient(grad, p1, 'x'));
		p1.x_t++;
	}
	return (1);
}

static int	print_line_img_case2(t_mlx_data *data, t_point p1, t_point p2,
		t_grad grad)
{
	int	dx;
	int	dy;
	int	e;
	int	x_incr;

	dx = abs(p2.x_t - p1.x_t);
	dy = p2.y_t - p1.y_t;
	x_incr = -1;
	if (p1.x_t <= p2.x_t)
		x_incr = 1;
	e = (2 * dx) + dy;
	while (p1.y_t <= p2.y_t)
	{
		e -= (2 * dx);
		if (e <= 0)
		{
			p1.x_t += x_incr;
			e += (2 * dy);
		}
		if (0 <= p1.x_t && p1.x_t < WIN_WIDTH && 0 <= p1.y_t
			&& p1.y_t < WIN_HEIGHT)
			fill_img_data(data, p1, make_gradient(grad, p1, 'y'));
		p1.y_t++;
	}
	return (1);
}

static void	swap_points(t_point *p1, t_point *p2)
{
	t_point	tmp;

	tmp.x_t = p1->x_t;
	tmp.y_t = p1->y_t;
	tmp.z_t = p1->z_t;
	tmp.color = p1->color;
	p1->x_t = p2->x_t;
	p1->y_t = p2->y_t;
	p1->z_t = p2->z_t;
	p1->color = p2->color;
	p2->x_t = tmp.x_t;
	p2->y_t = tmp.y_t;
	p2->z_t = tmp.z_t;
	p2->color = tmp.color;
}

void	draw_line(t_mlx_data *data, t_point p1, t_point p2)
{
	int		dx;
	int		dy;
	t_grad	grad;

	dx = abs(p2.x_t - p1.x_t);
	dy = abs(p2.y_t - p1.y_t);
	if (dx >= dy)
	{
		if (p1.x_t > p2.x_t)
			swap_points(&p1, &p2);
		grad.start = p1;
		grad.end = p2;
		print_line_img_case1(data, p1, p2, grad);
	}
	else
	{
		if (p1.y_t > p2.y_t)
			swap_points(&p1, &p2);
		grad.start = p1;
		grad.end = p2;
		print_line_img_case2(data, p1, p2, grad);
	}
}
