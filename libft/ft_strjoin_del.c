/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 13:54:03 by bwaegene          #+#    #+#             */
/*   Updated: 2019/08/14 17:53:02 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_del(char const *s1, char const *s2, int nb)
{
	char *result;

	result = ft_strjoin(s1, s2);
	if (result)
	{
		if (nb == 1 || nb == 3)
			free((char *)s1);
		if (nb == 2 || nb == 3)
			free((char *)s2);
	}
	return (result);
}

/*
** Return a new string resulting of the concatenation of the two string. If it
** succed it also free the first string (1), the second string (2), both (3) or
** none (0).
*/
