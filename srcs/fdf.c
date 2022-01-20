/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 19:51:30 by echerell          #+#    #+#             */
/*   Updated: 2022/01/20 22:14:33 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset_world(t_world *world)
{
	world->color_num = 0;
	world->x_shift = 0;
	world->y_shift = 0;
	world->x_incr = 0;
	world->y_incr = 0;
	world->zoom = 1;
	world->add_alt = 2;
	world->x_rot = 0.0;
	world->y_rot = 0.0;
	world->z_rot = 0.0;
	add_color(world);
	apply_changes(world, 1);
	get_edge_coord(world);
	init_zoom(world);
	apply_changes(world, 1);
	center(world);
}

static void	init_world(t_world *world)
{
	world->mat = NULL;
	world->mlx.mlx_ptr = NULL;
	world->mlx.win_ptr = NULL;
	world->mlx.img_ptr = NULL;
	world->mlx.img_addr = NULL;
	world->cols = -1;
	world->lines = 0;
	world->total = 0;
	world->alt_max = 0;
	world->alt_min = 0;
	world->color_num = 0;
	world->color = 0;
	world->proj = 1;
	world->x_shift = 0;
	world->y_shift = 0;
	world->x_incr = 0;
	world->y_incr = 0;
	world->zoom = 1;
	world->magn = 30;
	world->add_alt = 2;
	world->x_rot = 0.0;
	world->y_rot = 0.0;
	world->z_rot = 0.0;
	world->legend = 1;
}

void	run_prog(int fd)
{
	t_world	world;

	init_world(&world);
	if (!(check_map(fd, &world)) && world.lines)
	{
		world.mlx.mlx_ptr = mlx_init();
		world.mlx.win_ptr = mlx_new_window(world.mlx.mlx_ptr, WIN_WIDTH,
			WIN_HEIGHT, "fdf");
		get_maxmin_alt(&world);
		add_color(&world);
		apply_changes(&world, 1);
		get_edge_coord(&world);
		init_zoom(&world);
		apply_changes(&world, 1);
		center(&world);
		display_world(&world);
	}
	free_world(&world);
	close(fd);
}
