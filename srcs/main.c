/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <nshelly@student.21school>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:14:49 by nshelly           #+#    #+#             */
/*   Updated: 2019/07/31 20:28:09 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int	main(int ac, char **av)
{
	int		fd;
	char	*arr;
	char	**map;
	int		***cor;
	int		inc;

	inc = -1;
	arr = 0;
	if (ac != 2)
	{
		ft_putstr("usage: ./fillit input file\n");
		exit(EXIT_SUCCESS);
	}
	fd = open(av[1], O_RDONLY);
	if (!(arr = reader(fd)))
	{
		close(fd);
		ft_putstr("error\n");
		exit(EXIT_SUCCESS);
	}
	map = ft_strsplit(arr, '\n');
	cor = find_coordinates(map, triple_arr(map), 0, 3);
	while (!all_solutions((nr(map) / 4), sp(nr(map), inc), cor))
		inc++;
	return (0);
}
