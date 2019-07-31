#include "../includes/fillit.h"

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

int ft_solve_fillit(int ***c, char **sp, int *l, int figures)
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

void ft_swp(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}