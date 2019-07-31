#include "../includes/fillit.h"

int *copy_next(int const *a, int *b, int n)
{
    int j;

    j = 0;
    while (j < n)
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

char **solution_space(int max_rows, int increment)
{
    int square_size;
    int n;
    int i;
    char **square;

    n = 0;
    square_size = 0;
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