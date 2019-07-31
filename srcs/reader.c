#include "../includes/fillit.h"

int number_of_rows(char **map)
{
    int i;
    int rows;

    i = 0;
    rows = 0;
    while(map[i++]) // length lines check
	rows = i;
    return(rows); //in the example of 8 figures returns 31
}

int ***triple_arr(char **map) // выделяет памать под тройной массив
{
	int nbr_tets;
	int i;
	int j;
	int ***crdnts; // coordinate

	nbr_tets = 0;
	i = 0;
	nbr_tets = number_of_rows(map + 1) / 4 + 1;
	crdnts = (int ***)ft_memalloc(sizeof(int **) * nbr_tets);

	while (i < nbr_tets)
	{
		j = 0;
		crdnts[i] = (int **)ft_memalloc(sizeof(int *) * 4);
		while (j < 4)
			crdnts[i][j++] = (int *)ft_memalloc((sizeof(int) * 1));
		i++;
	}
	return (crdnts);
}

int check_order(char *buf) // check of hashtags
{
	int i;
	int sum;

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

int check(char *buf, int bytes)
{
	int i;
	int reshetki;

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

char *reader(int fd, char *arr)
{
    int bytes;
    char buff[BUFF_SIZE];
    char letter;

    letter = 'A';
    arr = "\0";
    while ((bytes = read(fd, buff, BUFF_SIZE_FILLIT)))
    {
		buff[bytes] = '\0';
        if (bytes < 20)
            return (NULL);
        letter++;
        if (!(check(buff, bytes)))
            return (NULL);
		if (arr)
            arr = ft_strjoin(arr, buff);
        else
            arr = ft_strdup(buff);
    }
    return (arr);
}