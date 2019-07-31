/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <nshelly@student.21school.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 19:19:15 by nshelly           #+#    #+#             */
/*   Updated: 2019/07/31 19:21:10 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"


void	limits_in_coords(int *start, int *end, int *j, int *y)
{
	if (*j == *end)
	{
		*start = *start + 4;
		*end = *end + 4;
	}
	if (*y == 3)
		*y = -1;
}

int		***find_coordinates(char **map, int ***coordinates, int start, int end)
{
	int i;
	int j;
	int z;
	int y;

	j = -1;
	z = -1;
	y = -1;
	while (++j < (nr(map)))
	{
		i = -1;
		while (++i < 4)
		{
			if ((j == start) && (i == 0))
				z++;
			if (map[j][i] == '#')
			{
				coordinates[z][++y][0] = j;
				coordinates[z][y][1] = i;
			}
			limits_in_coords(&start, &end, &j, &y);
		}
	}
	return (coordinates);
}
