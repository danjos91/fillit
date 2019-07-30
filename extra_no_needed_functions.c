/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_no_needed_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <nshelly@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 18:03:37 by nshelly           #+#    #+#             */
/*   Updated: 2019/07/30 18:03:39 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void print_row(int const *c, int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        ft_putnbr(c[i]);
        i++;
    }
    ft_putchar('\n');
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
        ft_putnbr(i + 1);
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