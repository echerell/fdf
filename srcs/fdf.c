/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 19:51:30 by echerell          #+#    #+#             */
/*   Updated: 2022/01/18 23:44:47 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_world(t_world *world)
{
	world->mat = NULL;
	world->mlx.mlx_ptr = NULL;
	world->mlx.win_ptr = NULL;
	world->cols = -1;
	world->lines = 0;
	world->total = 0;
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
	}
	free_world(&world);
	close(fd);
}
