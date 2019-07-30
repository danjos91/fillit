#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#define SIZE_MAP 546//max bytes if 26 tetraminos max\


#include <stdio.h>
#include <stdlib.h>

int number_of_rows(char **map)
{
    int i;
    int rows;

    i = 0;
    rows = 0;
    while(map[i])// length lines check
    {
        rows = i;//max row if first line is line 0 equal to 31 in this example
        if(ft_strlen(map[i]) != 4) {
            ft_putstr("map error");

            return (0);
        }
        i++;
    }
    return(rows);//si regresara i, tendriamos que regresar i menos uno
}

char **solution_space(int max_rows, int increment)
{
    int square_size;
    int n;
    int i;
    char **square;

    n = 0;
    square_size = 0;// max rows is the number of cells that have to be used for the solution
    while(square_size < max_rows)
    {
        square_size = n * n;
        n++;
    }
    n = n + increment;
    square = (char **)ft_memalloc(sizeof(char *) * n - 1);
    i = 0;
    while (i < n - 1)
    {
        square[i] = ft_strsub("...........", 0, n - 1);
        i++;
    }
return(square);
}

int ***triple_arr(char **map) // выделяет памать под тройной массив
{
    int nbr_tets;
    int i;
    int j;
    int ***crdnts; // coordinate

    nbr_tets = 0;
    i = 0;
    nbr_tets = (number_of_rows(map) + 1) / 4;//4
    crdnts = (int ***)ft_memalloc(sizeof(int **) * nbr_tets);//4

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

int ***find_coordinates(char **map, int ***coordinates, int start, int end) {
    int i;
    int j;
    int z;
    int x;
    int y;

    j = 0;
    z = -1;
    y = -1;
    while(j <= (number_of_rows(map)))
    {
        i = 0;
        while (i < 4)
        {
            if ((j == start) && (i == 0)) {
                z++;
            }
            x = 0;
            if (map[j][i] == '#')
            {
                y++;
                coordinates[z][y][x] = j;
                x++;
                coordinates[z][y][x] = i;
            }
            if (j == start + 3)
            {
                start = start + 4;
                end = end + 4;
            }
            if (y == 3)
                y = -1;
            i++;
        }
        j++;
    }
    return(coordinates);
}

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

int check_figure(int ***c, int max_sol, int i, int l)//
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



int ft_solve_fillit(int ***c, char **sp, int *l, int figures)//increment is the possible extension of the map c = coordinates sp = solution space p = number of figures
{
    int i;
    int j;
    int n;

    i = -1;
    n = 0;
    while((++i <= max_solution(sp)) && (n < figures))
    {
        j = -1;
        while(++j <= max_solution(sp))
            if (sp[i][j] == '.')
            {
                if (check_and_print(c, sp,l[n], i, j))
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

void ft_swp(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int all_solutions(int n, char **sp, int ***c)
{
    int **combinations;
    int i;
    int a;

    i = 0;
    combinations = (int **)ft_memalloc(sizeof(int *) * factorial(n));
    while (i < factorial(n))
    {
        combinations[i] = (int *)ft_memalloc(sizeof(int) * n);
        i++;
    }
    combinations[0] = create_first(combinations[0], n);
    i = 0;
    a = 1;
    while ((i + 1) < factorial(n))
    {
        copy_next(combinations[i], combinations[i + 1], n);
        if ((i + 1) % factorial(n - 1) == 0)
            ft_swp(&combinations[i + 1][0], &combinations[i + 1][n - 1]);
        else{
            ft_swp(&combinations[i + 1][0], &combinations[i + 1][a]);
            if (a == n - 2)
                a = 0;
            a++;
        }
        i++;
        clean_map(sp, max_solution(sp));
        if(ft_solve_fillit(c, sp, combinations[i - 1], n))
            return (1);
    }
    return (0);
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
int		main()//int argc, char **argv)
{
    int max_rows;
    char buf[SIZE_MAP + 1];
    char **map;
    char **sol_space;
    int ***coordinates;
    int figures;
    int increment;

    increment = 0;
    buf[read(open("sample.fillit", O_RDONLY), buf, SIZE_MAP)] = '\0';
    map = ft_strsplit(buf, '\n');
    max_rows = number_of_rows(map);
    figures = (max_rows + 1) / 4;
    sol_space = solution_space(max_rows, 0);
    coordinates = find_coordinates(map, triple_arr(map), 0, 3);
    ft_putstr("MYSTERY");
    print_coordinates(coordinates, figures);
    while (!all_solutions(figures, sol_space, coordinates))
    {
        sol_space = solution_space(max_rows, increment);
        increment++;
    }

    return (0);
}

