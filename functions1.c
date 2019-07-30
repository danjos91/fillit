/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <nshelly@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 18:01:35 by nshelly           #+#    #+#             */
/*   Updated: 2019/07/30 18:01:52 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int number_of_rows(char **map)
{
    int i;
    int rows;

    i = 0;
    rows = 0;
    while(map[i])
    {
        rows = i;
        if(ft_strlen(map[i]) != 4) {
            ft_putstr("map error");
            return (0);
        }
        i++;
    }
    return(rows);
}

char **solution_space(int max_rows, int increment)
{
    int square_size;
    int n;
    int i;
    char **square;

    n = 0;
    square_size = 0;
    while(square_size < max_rows)
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
    return(square);
}

int ***triple_arr(char **map)
{
    int nbr_tets;
    int i;
    int j;
    int ***crdnts;

    i = 0;
    nbr_tets = (number_of_rows(map) + 1) / 4;//4
    crdnts = (int ***)ft_memalloc(sizeof(int **) * nbr_tets);//4
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

void limits_in_coords(int *start, int *end, int *j, int *y)
{
    if (*j == *end)
    {
        *start = *start + 4;
        *end = *end + 4;
    }
    if (*y == 3)
        *y = -1;
}

int ***find_coordinates(char **map, int ***coordinates, int start, int end)
{
    int i;
    int j;
    int z;
    int y;

    j = -1;
    z = -1;
    y = -1;
    while(++j <= (number_of_rows(map)))
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
    return(coordinates);
}
