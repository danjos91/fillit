/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <nshelly@student.21school.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 23:37:26 by nshelly           #+#    #+#             */
/*   Updated: 2019/08/11 23:51:21 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		max_solution(char **sp)
{
	int m;
	int max_sol;

	max_sol = 0;
	m = 0;
	while (sp[m])
		max_sol = m++;
	return (max_sol);
}

int		check_figure(char **map, t_coord *figures, int size)
{
	int i;
	int x;
	int y;

	i = 0;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (figures->y[i] < size && figures->x[i] < size &&
					map[figures->y[i]][figures->x[i]] == '.')
			{
				i++;
				if (i == 4)
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_upleft(t_coord **figures, int x, int y)
{
	int	pos_x;
	int pos_y;
	int i;

	i = 0;
	pos_x = 100;
	pos_y = 100;
	while (i < 4)
	{
		if ((*figures)->x[i] < pos_x)
			pos_x = (*figures)->x[i];
		if ((*figures)->y[i] < pos_y)
			pos_y = (*figures)->y[i];
		i++;
	}
	i--;
	while (i >= 0)
	{
		(*figures)->x[i] = (*figures)->x[i] - pos_x + x;
		(*figures)->y[i] = (*figures)->y[i] - pos_y + y;
		i--;
	}
}

char	**brute_force(char **tetri_map, t_coord *figures)
{
	int		x;
	int		y;
	char	**map;
	int		size;

	size = max_solution(tetri_map) + 1;
	if (figures->next == 0)
		return (tetri_map);
	map = 0;
	y = -1;
	while (y++ < size)
	{
		x = -1;
		while (x++ < size)
		{
			ft_upleft(&figures, x, y);
			if (check_figure(tetri_map, figures, size))
				map = brute_force(print_figure(tetri_map,\
							figures, size), figures->next);
			if (map)
				return (map);
			tetri_map = delete_figure(tetri_map, figures, size);
		}
	}
	return (0);
}

void	solve(t_coord *figures, int numb_of_figures)
{
	char	**result;
	char	**sol_map;
	int		increment;

	increment = 0;
	sol_map = sp(numb_of_figures, increment);
	while (!(result = brute_force(sol_map, figures)))
	{
		increment++;
		ft_memdel((void **)sol_map);
		sol_map = sp(numb_of_figures, increment);
	}
	print_map(result);
}
/*
** brute_force is the algorithm(backtracking)
** ft_upleft moves the coordinates to the max possible upleft
** position, then we check if it is possible put all the figures,
** if not, we comeback to the last figure and change his position
** to the next free cell, and always we go in order A,B,C...
** max_solution give the size of our solution_map, if whe have a
** n*n map, max_solution returns n - 1
** for print and delete(if necesary) figures of our map we use
** insert_figure and delete_figure.
*/
