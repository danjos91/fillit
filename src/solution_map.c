/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <nshelly@student.21school.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 23:34:09 by nshelly           #+#    #+#             */
/*   Updated: 2019/08/11 23:35:59 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**sp(int numb_of_figures, int increment)
{
	int		square_size;
	int		n;
	int		i;
	char	**square;

	n = 0;
	square_size = 0;
	while (square_size < (numb_of_figures * 4))
	{
		square_size = n * n;
		n++;
	}
	n = n + increment;
	square = (char **)ft_memalloc(sizeof(char *) * n);
	i = 0;
	while (i < n - 1)
	{
		square[i] = ft_strsub("..........", 0, n - 1);
		i++;
	}
	return (square);
}

void	print_map(char **map)
{
	int i;

	if (map == 0)
	{
		ft_putendl("error");
		return ;
	}
	i = 0;
	while (map[i] != 0)
	{
		ft_putendl(map[i]);
		i++;
	}
}

char	**delete_figure(char **map, t_coord *figures, int size)
{
	int x;
	int y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (map[y][x] == figures->c)
				map[y][x] = '.';
			x++;
		}
		y++;
	}
	return (map);
}

char	**print_figure(char **map, t_coord *figures, int size)
{
	int x;
	int y;
	int i;

	i = 0;
	y = 0;
	x = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (figures->y[i] == y && figures->x[i] == x)
			{
				map[y][x] = figures->c;
				i++;
			}
			x++;
		}
		y++;
	}
	return (map);
}
