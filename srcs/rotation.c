/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:02:07 by echerell          #+#    #+#             */
/*   Updated: 2022/01/20 21:59:49 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_rot(t_world *world, int keycode)
{
	if (keycode == KEY_1)
		world->x_rot -= 0.2;
	if (keycode == KEY_2)
		world->x_rot += 0.2;
	if (keycode == KEY_3)
		world->y_rot -= 0.2;
	if (keycode == KEY_4)
		world->y_rot += 0.2;
	if (keycode == KEY_5)
		world->z_rot -= 0.2;
	if (keycode == KEY_6)
		world->z_rot += 0.2;
	apply_changes(world, 1);
}

void	apply_rot(t_world *world, t_point *p, t_rot_data *d)
{
	int	tmp_x_t;
	int	tmp_y_t;
	int	tmp_z_t;

	tmp_x_t = p->x_t - ((world->x_max - world->x_min) / 2);
	tmp_y_t = p->y_t - ((world->y_max - world->y_min) / 2);
	tmp_z_t = p->z_t;
	p->x_t = tmp_x_t * d->y_cos * d->z_cos
		+ tmp_y_t * (d->x_sin * d->y_sin * d->z_cos - d->x_cos * d->z_sin)
		+ tmp_z_t * (d->x_cos * d->y_sin * d->z_cos + d->x_sin * d->z_sin);
	p->y_t = tmp_x_t * d->y_cos * d->z_sin
		+ tmp_y_t * (d->x_sin * d->y_sin * d->z_sin + d->x_cos * d->z_cos)
		+ tmp_z_t * (d->x_cos * d->y_sin * d->z_sin - d->x_sin * d->z_cos);
	p->z_t = -tmp_x_t * d->y_sin
		+ tmp_y_t * d->x_sin * d->y_cos
		+ tmp_z_t * d->x_cos * d->y_cos;
}

void	set_rot_data(t_world *world, t_rot_data *data)
{
	data->x_cos = cos(world->x_rot);
	data->x_sin = sin(world->x_rot);
	data->y_cos = cos(world->y_rot);
	data->y_sin = sin(world->y_rot);
	data->z_cos = cos(world->z_rot);
	data->z_sin = sin(world->z_rot);
}
