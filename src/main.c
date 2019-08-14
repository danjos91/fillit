/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:14:49 by nshelly           #+#    #+#             */
/*   Updated: 2019/08/14 17:48:56 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_list_del(t_coord **alst)
{
	if (!alst)
		return ;
	if ((*alst)->next)
		ft_list_del(&(*alst)->next);
	free(*alst);
	*alst = 0;
}

/*
**ft_tcoord_del frees all linked list by recursion
*/

void	clean_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		ft_strdel(&map[i]);
		i++;
	}
	free(map);
}

int		main(int ac, char **av)
{
	char	*arr;
	int		fd;
	t_coord	*figures;

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
	close(fd);
	figures = get_coords(arr);
	solve(figures, count_figures(arr));
	ft_list_del(&figures);
	ft_strdel(&arr);
	return (0);
}
/*
** coords contains the coordinates of each figure,
** and his respective letter solve find the solution
** working whit other functions, count_figure give
**us the number of figures(tetraminos)
*/
