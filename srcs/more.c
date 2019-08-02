/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <nshelly@student.21school.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:24:30 by nshelly           #+#    #+#             */
/*   Updated: 2019/07/31 18:31:21 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void ft_swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int ft_permute(char *a, int l, int r, int ***c, char **map)
{
    int i;
    static int q;
    int v[r + 1];

    if (l == r)
    {
        q = 0;
        while (a[q] != '\0')
        {
            v[q] = a[q] - 'A';
            q++;
        }
        q = 0;
        clean_map(map, max_solution(map));
        if (ft_solve_fillit(c, map, v, r + 1))
            exit(EXIT_SUCCESS);
    }
    else
    {
        i = l;
        while(i <= r)
        {
            ft_swap((a+l), (a+i));
            ft_permute(a, l+1, r, c, map);
            ft_swap((a+l), (a+i));
            i++;
        }
    }
    return(0);
}

int		ft_solve_fillit(int ***c, char **sp, int *l, int figures)
{
    int i;
    int j;
    int n;

    i = -1;
    n = 0;
    while ((++i <= max_solution(sp)) && (n < figures))
    {
        j = -1;
        while (++j <= max_solution(sp))
            if (sp[i][j] == '.')
            {
                if (check_and_print(c, sp, l[n], i, j))
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

int		check_and_print(int ***c, char **sp, int l, int i, int j)
{
    int ms;

    ms = max_solution(sp);
    if (!check_vertical(c, ms, i, l) ||\
			((i == ms) && (j == (ms - 2))))
        return (0);
    else
    {
        if (print_figure(c, sp, l, i, j))
        {
            return (1);
        }
    }
    return (0);
}


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
