/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <nshelly@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 18:14:13 by nshelly           #+#    #+#             */
/*   Updated: 2019/07/30 18:14:17 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int ft_solve_fillit(int ***c, char **sp, int *l, int figures)
{
    int i;
    int j;
    int n;

    i = -1;
    n = 0;
    while((++i <= max_solution(sp)) && (n < figures))
    {
        j = -1;
        while(++j <= max_solution(sp))
            if (sp[i][j] == '.')
            {
                if (check_and_print(c, sp,l[n], i, j))
                    n++;
                if (n == figures)
                {
                    print_solution(sp);
                    return (1);
                }
            }
    }
    return (0);
}

int all_solutions(int n, char **sp, int ***c)
{
    int **combinations;
    int i;
    int a;

    i = 0;
    combinations = (int **)ft_memalloc(sizeof(int *) * factorial(n));
    while (i < factorial(n))
    {
        combinations[i] = (int *)ft_memalloc(sizeof(int) * n);
        i++;
    }
    combinations[0] = create_first(combinations[0], n);
    i = 0;
    a = 1;
    while ((i + 1) < factorial(n))
    {
        copy_next(combinations[i], combinations[i + 1], n);
        if ((i + 1) % factorial(n - 1) == 0)
            ft_swp(&combinations[i + 1][0], &combinations[i + 1][n - 1]);
        else{
            ft_swp(&combinations[i + 1][0], &combinations[i + 1][a]);
            if (a == n - 2)
                a = 0;
            a++;
        }
        i++;
        clean_map(sp, max_solution(sp));
        if(ft_solve_fillit(c, sp, combinations[i - 1], n))
            return (1);
    }
    return (0);
}

int		main()//int argc, char **argv)
{
    int max_rows;
    char buf[SIZE_MAP + 1];
    char **map;
    char **sol_space;
    int ***coordinates;
    int figures;
    int increment;

    increment = 0;
    buf[read(open("sample.fillit1", O_RDONLY), buf, SIZE_MAP)] = '\0';
    map = ft_strsplit(buf, '\n');
    max_rows = number_of_rows(map);
    figures = (max_rows + 1) / 4;
    sol_space = solution_space(max_rows, 0);
    coordinates = find_coordinates(map, triple_arr(map), 0, 3);
    while (!all_solutions(figures, sol_space, coordinates))
    {
        sol_space = solution_space(max_rows, increment);
        increment++;
    }
    return (0);
}

