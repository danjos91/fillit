/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <nshelly@student.21school.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 17:14:20 by nshelly           #+#    #+#             */
/*   Updated: 2019/07/31 17:37:39 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		*copy_next(int const *a, int *b, int n)
{
	int	j;

	j = 0;
	while (j < n)
	{
		b[j] = a[j];
		j++;
	}
	return (b);
}

int		*create_first(int *c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		c[i] = i;
		i++;
	}
	return (c);
}

int		factorial(int value)
{
	if (value == 0)
		return (1);
	if (value > 1)
	{
		value = value * (factorial(value - 1));
	}
	return (value);
}

void	ft_swp(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}


