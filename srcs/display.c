/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:32:30 by echerell          #+#    #+#             */
/*   Updated: 2022/01/20 23:13:25 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	show_legend(t_world *world)
{
	if (world->legend)
	{
		mlx_string_put(world->mlx.mlx_ptr, world->mlx.win_ptr, 10, 20,
			COLOR_GREEN, "___________COMMANDS (L to hide)___________");
		mlx_string_put(world->mlx.mlx_ptr, world->mlx.win_ptr, 10, 40,
			COLOR_GREEN, "Exit: ESC");
		mlx_string_put(world->mlx.mlx_ptr, world->mlx.win_ptr, 10, 60,
			COLOR_GREEN, "Change color: C");
		mlx_string_put(world->mlx.mlx_ptr, world->mlx.win_ptr, 10, 80,
			COLOR_GREEN, "Increase/decrease altitude: Q/A");
		mlx_string_put(world->mlx.mlx_ptr, world->mlx.win_ptr, 10, 100,
			COLOR_GREEN, "Move: arrows");
		mlx_string_put(world->mlx.mlx_ptr, world->mlx.win_ptr, 10, 120,
			COLOR_GREEN, "Reset world: R");
		mlx_string_put(world->mlx.mlx_ptr, world->mlx.win_ptr, 10, 140,
			COLOR_GREEN, "Zoom: +/-");
		mlx_string_put(world->mlx.mlx_ptr, world->mlx.win_ptr, 10, 160,
			COLOR_GREEN, "Change projection: P");
		mlx_string_put(world->mlx.mlx_ptr, world->mlx.win_ptr, 10, 180,
			COLOR_GREEN, "Rotate X/Y/Z axes: 1-2/3-4/5-6");
	}
}

static void	draw_world(t_world *world)
{
	int		i;
	t_point	next;

	i = 0;
	while (i < world->total)
	{
		get_x_point(world, i, world->mat[i], &next);
		if (next.x > -1)
			draw_line(&(world->mlx), world->mat[i], next);
		get_y_point(world, i, world->mat[i], &next);
		if (next.y > -1)
			draw_line(&(world->mlx), world->mat[i], next);
		i++;
	}
	mlx_put_image_to_window(world->mlx.mlx_ptr, world->mlx.win_ptr,
		world->mlx.img_ptr, 0, 0);
}

void	display_world(t_world *world)
{
	if (world->mlx.img_ptr)
		ft_bzero(world->mlx.img_addr, WIN_WIDTH * WIN_HEIGHT * 4);
	if (!world->mlx.img_ptr)
	{
		world->mlx.img_ptr = mlx_new_image(world->mlx.mlx_ptr, WIN_WIDTH,
				WIN_HEIGHT);
		world->mlx.img_addr = mlx_get_data_addr(world->mlx.img_ptr,
				&(world->mlx.bpp), &(world->mlx.line_len),
				&(world->mlx.endian));
	}
	draw_world(world);
	show_legend(world);
	mlx_hook(world->mlx.win_ptr, 2, 1L << 0, &key_event, world);
	mlx_loop(world->mlx.mlx_ptr);
}
