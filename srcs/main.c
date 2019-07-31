#include "../includes/fillit.h"

int main(int ac, char **av)
{
    int fd;
    char *arr;
    char **map;
    int ***coords;
    char **sol_space;
    int inc = 0;

    arr = 0;
    if (ac != 2)
    {
        ft_putstr("usage: ./fillit input file\n");
		exit(EXIT_SUCCESS);
    }
    fd = open(av[1], O_RDONLY);
    if (!(arr = reader(fd, arr)))
    {
        ft_putstr("error\n");
		exit(EXIT_SUCCESS);
    }
    map = ft_strsplit(arr, '\n');
    coords = find_coordinates(map, triple_arr(map), 0, 3);
    sol_space = solution_space(number_of_rows(map), 0);
    while (!all_solutions((number_of_rows(map) / 4), sol_space, coords))
    {
        sol_space = solution_space(number_of_rows(map), inc);
        inc++;
    }
    return (0);
}
