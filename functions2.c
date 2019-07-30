/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <nshelly@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 18:02:02 by nshelly           #+#    #+#             */
/*   Updated: 2019/07/30 18:02:04 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void print_solution(char **s)
{
    int i;

    i = 0;
    while (s[i])
    {
        ft_putstr(s[i]);
        ft_putchar('\n');
        i++;
    }
}

int factorial(int value)
{
    if (value == 0)
        return (1);
    if (value > 1)
    {
        value = value * (factorial(value - 1));
    }
    return (value);
}

void clean_map(char **map, int max_sol)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i <= max_sol)
    {
        j = 0;
        while (j <= max_sol)
        {
            map[i][j] = '.';
            j++;
        }
        i++;
    }
}
int max_solution(char **sp)
{
    int m;
    int max_sol;

    max_sol = 0;
    m = 0;
    while (sp[m])
        max_sol = m++;
    return(max_sol);
}

int *copy_next(int const *a, int *b, int n)//copy a in b
{
    int j;

    j = 0;
    while (j < n)//copiamos los elementos en el nuevo massiv recien creado
    {
        b[j] = a[j];
        j++;
    }
    return (b);
}