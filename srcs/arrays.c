/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <nshelly@student.21school.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 17:43:24 by nshelly           #+#    #+#             */
/*   Updated: 2019/07/31 18:22:53 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**sp(int max_rows, int increment)
{
    int		square_size;
    int		n;
    int		i;
    char	**square;

    n = 0;
    square_size = 0;
    while (square_size < max_rows)
    {
        square_size = n * n;
        n++;
    }
    n = n + increment;
    square = (char **)ft_memalloc(sizeof(char *) * n - 1);
    i = 0;
    while (i < n - 1)
    {
        square[i] = ft_strsub("...........", 0, n - 1);
        i++;
    }
    return (square);
}

int		***triple_arr(char **map)
{
	int	nbr_tets;
	int	i;
	int	j;
	int	***crdnts;

	i = 0;
	nbr_tets = nr(map + 1) / 4 + 1;
	crdnts = (int ***)ft_memalloc(sizeof(int **) * nbr_tets);
	while (i < nbr_tets)
	{
		j = 0;
		crdnts[i] = (int **)ft_memalloc(sizeof(int *) * 4);
		while (j < 4)
			crdnts[i][j++] = (int *)ft_memalloc((sizeof(int) * 1));
		i++;
	}
	return (crdnts);
}
