/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <nshelly@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 18:10:41 by nshelly           #+#    #+#             */
/*   Updated: 2019/07/30 18:10:43 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int *create_first(int *c, int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        c[i] = i;
        i++;
    }
    return (c);
}

int check_figure(int ***c, int max_sol, int i, int l)
{

    if (((c[l][1][0]) - ((c[l][0][0]) - i)) > max_sol || ((c[l][2][0]) - ((c[l][0][0]) - i)) > max_sol ||
        ((c[l][3][0]) - ((c[l][0][0]) - i)) > max_sol)
        return (0);
    return (1);
}

int print_figure(int ***c, char **sp, int l, int i, int j)
{
    int letter;

    letter = 'A' + l;
    if ((sp[(c[l][1][0]) - ((c[l][0][0]) - i)][(c[l][1][1]) - ((c[l][0][1]) - j)] == '.')
        && (sp[(c[l][2][0]) - ((c[l][0][0]) - i)][(c[l][2][1]) - ((c[l][0][1]) - j)] == '.')
        &&(sp[(c[l][3][0]) - ((c[l][0][0]) - i)][(c[l][3][1]) - ((c[l][0][1]) - j)] == '.'))
    {
        sp[i][j] = letter;
        sp[(c[l][1][0]) - ((c[l][0][0]) - i)][(c[l][1][1]) - ((c[l][0][1]) - j)] = letter;
        sp[(c[l][2][0]) - ((c[l][0][0]) - i)][(c[l][2][1]) - ((c[l][0][1]) - j)] = letter;
        sp[(c[l][3][0]) - ((c[l][0][0]) - i)][(c[l][3][1]) - ((c[l][0][1]) - j)] = letter;
        return (1);
    }
    return(0);
}

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

void ft_swp(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}
