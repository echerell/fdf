/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:58:52 by echerell          #+#    #+#             */
/*   Updated: 2022/01/20 23:20:04 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		ft_putstr_fd("Format: ./fdf map\n", STDOUT_FILENO);
	else
	{
		fd = open((const char *)argv[1], O_RDONLY);
		if (fd == -1)
			perror("Error");
		else
			run_prog(fd);
	}
	return (0);
}
