/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:26:49 by echerell          #+#    #+#             */
/*   Updated: 2022/01/20 23:12:22 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	key_event1(t_world *world, int keycode)
{
	if (keycode == KEY_ESC)
	{
		free_world(world);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == KEY_C)
	{
		if (world->color_num == 6)
			world->color_num = 0;
		else
			world->color_num++;
		add_color(world);
	}
}

int	key_event(int keycode, void *param)
{
	t_world	*world;

	world = (t_world *)param;
	key_event1(world, keycode);
	if (keycode == KEY_Q || keycode == KEY_A)
		change_alt(world, keycode);
	else if (keycode == KEY_ARR_UP || keycode == KEY_ARR_DOWN
		|| keycode == KEY_ARR_LEFT || keycode == KEY_ARR_RIGHT)
		shift_world(world, keycode);
	else if (keycode == KEY_R)
		reset_world(world);
	else if (keycode == KEY_PLUS || keycode == KEY_MINUS)
		change_zoom(world, keycode);
	else if (keycode == KEY_P)
		change_proj(world);
	else if (keycode >= KEY_1 && keycode <= KEY_6)
		change_rot(world, keycode);
	else if (keycode == KEY_L)
		world->legend = !world->legend;
	display_world(world);
	return (1);
}
