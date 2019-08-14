/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <nshelly@student.21school.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 23:18:43 by nshelly           #+#    #+#             */
/*   Updated: 2019/08/14 17:46:06 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			count_figures(char *str)
{
	int		i;
	int		result;

	if (str == 0)
		return (0);
	result = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			result++;
		i++;
	}
	return (result / 4);
}

void		set_coordinates(t_coord **tmp, char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			(*tmp)->x[j] = i % 5;
			(*tmp)->y[j] = i / 5;
			j++;
		}
		i++;
	}
	ft_strdel(&str);
}

t_coord		*get_coords(char *str)
{
	int		c_tetri;
	int		add21;
	char	c;
	t_coord *stock;
	t_coord *tmp;

	add21 = 0;
	c = 'A';
	c_tetri = count_figures(str);
	if (!(stock = (t_coord *)ft_memalloc(sizeof(t_coord))))
		return (0);
	tmp = stock;
	while (c_tetri > 0)
	{
		tmp->c = c;
		set_coordinates(&tmp, ft_strsub(str, 0 + add21, 20));
		if (!(tmp->next = (t_coord *)ft_memalloc(sizeof(t_coord))))
			return (0);
		tmp = tmp->next;
		c_tetri--;
		c++;
		add21 += 21;
	}
	tmp->next = 0;
	return (stock);
}
/*
** get_coords put the coordinates in the structure with his
** respective letter in the respective order, in the first time
** tmp->c is equal to 'A', and set_coordinates saves the 4
** coordinates of the tetramino, and we create the necesary memory
** for the next structure in the list, and we decrease the number
** of figures till we get 0, also we add 21 characters each time
*/
