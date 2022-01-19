/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 21:35:22 by echerell          #+#    #+#             */
/*   Updated: 2022/01/19 21:46:05 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_maxmin_alt(t_world *world)
{
	int	i;

	world->alt_max = ((world->mat)[0]).z;
	world->alt_min = ((world->mat)[0]).z;
	i = 1;
	while (i < world->total)
	{
		if (((world->mat)[i]).z > world->alt_max)
			world->alt_max = ((world->mat)[i]).z;
		if (((world->mat)[i]).z < world->alt_min)
			world->alt_min = ((world->mat)[i]).z;
		i++;
	}
}
