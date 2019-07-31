#include "../includes/fillit.h"

int check_and_print(int ***c, char **sp, int l, int i, int j)
{
    int max_sol;

    max_sol = max_solution(sp);
    if (!check_figure(c, max_sol, i, l) || ((i == (max_sol - 1)) && (j == max_sol)))
        return (0);
    else
    {
        if (print_figure(c, sp, l, i, j))
        {
            return(1);
        }
    }
    return (0);
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
    while(++j < (number_of_rows(map)))
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

void print_coordinates(int ***coordinates, int figures)
{
    int i;
    int j;
    int k;

    i = 0;

    ft_putstr("COORDINATES: ");
    ft_putchar('\n');
    while(i <  figures)
    {
        ft_putstr("FIGURE ");
        ft_putnbr(i);
        ft_putchar('\n');
        j = 0;
        while(j < 4)
        {
            k = 0;
            while (k < 2)
            {
                ft_putchar('[');
                ft_putnbr(coordinates[i][j][k]);
                ft_putchar(']');
                if (k == 1)
                    ft_putchar('\n');
                k++;
            }
            j++;
        }
        i++;
    }
}