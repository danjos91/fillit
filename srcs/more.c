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

int		all_solutions(int n, char **sp, int ***c)
{
    int	**combinations;
    int	i;
    int	a;

    combinations = double_array(n);
    combinations[0] = create_first(combinations[0], n);
    i = 0;
    a = 0;
    while ((i + 1) < factorial(n))
    {
        copy_next(combinations[i], combinations[i + 1], n);
        if ((i + 1) % factorial(n - 1) == 0)
            ft_swp(&combinations[i + 1][0], &combinations[i + 1][n - 1]);
        else
        {
            ft_swp(&combinations[i + 1][0], &combinations[i + 1][++a]);
            if (a == n - 2)
                a = 0;
        }
        i++;
        clean_map(sp, max_solution(sp));
        if (ft_solve_fillit(c, sp, combinations[i - 1], n))
            return (1);
    }
    return (0);
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
