/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <nshelly@student.21school.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 23:33:51 by nshelly           #+#    #+#             */
/*   Updated: 2019/08/11 23:33:56 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_order(char *buf)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			if (i + 1 <= 19 && buf[i + 1] == '#')
				sum++;
			if (i - 1 >= 0 && buf[i - 1] == '#')
				sum++;
			if (i + 5 <= 19 && buf[i + 5] == '#')
				sum++;
			if (i - 5 >= 0 && buf[i - 5] == '#')
				sum++;
		}
		i++;
	}
	return (sum == 6 || sum == 8);
}

int		check(char *buf, int bytes)
{
	int	i;
	int	reshetki;

	i = 0;
	reshetki = 0;
	while (i < 20)
	{
		if (i % 5 != 4 && !(ft_strchr(".#", buf[i])))
			return (0);
		if (buf[i] == '#' && ++reshetki > 4)
			return (0);
		if (i % 5 == 4 && buf[i] != '\n')
		{
			return (0);
		}
		i++;
	}
	if (ft_strlen(buf) == 21 && (buf[20] != '\n'))
		return (0);
	if (!(check_order(buf)))
		return (0);
	return (bytes == 21 ? 1 : 2);
}

char	*reader(int fd)
{
	char	*arr;
	int		bytes;
	char	buff[BUFF_SIZE];
	char	letter;
	char	*tmp;

	letter = 'A';
	arr = 0;
	while ((bytes = read(fd, buff, BUFF_SIZE_FILLIT)))
	{
		buff[bytes] = '\0';
		if ((bytes < 20) || (!(check(buff, bytes))))
			return (NULL);
		letter++;
		if (arr)
		{
			tmp = arr;
			arr = ft_strjoin(tmp, buff);
			free(tmp);
		}
		else
			arr = ft_strdup(buff);
	}
	return (arr);
}
