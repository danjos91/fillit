#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "libft/libft.h"
#include <stdio.h>
#define SIZE_MAP 546//max bytes if 26 tetraminos max



int min_4(int a, int b, int c, int d)
{
    int tmp;
    int i;

    i = 0;
    while(i <= 2)
    {
        if (a > b) {
            tmp = a;
            a = b;
            b = tmp;
        }
        if (b > c) {
            tmp = b;
            b = c;
            c = tmp;
        }
        if (c > d) {
            tmp = c;
            c = d;
            d = tmp;
        }
        i++;
    }
    return (a);
}

int number_of_rows(char **map)
{
    int i;
    int rows;

    i = 0;
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

int symbols_check(int columns, char **map)
{
    int col;
    int i;

    i = 0;
    col = 0;
    while(col <= columns)
    {
        i = 0;
        while(i <= 3)
        {
            if ((map[col][i] != '.') && (map[col][i] != '#'))//symbols check
            {
                ft_putchar('(');
                ft_putnbr(i);
                ft_putchar(',');
                ft_putnbr(col);
                ft_putchar(')');
                ft_putchar('\n');
                ft_putstr("symbols error");
                return (0);
            }
            i++;
        }
        col++;
    }
    return (1);

}

int check_zone(char **map, int i, int j, int end, int start)
{
    int a;

    a = 0;
    if (j == end)//zone3 and zone 6
        if (map[j - 1][i] == '#')//up check
            a++;
    if ((j > start) && (j < end))//zone2 and zone 5
    {
        if (map[j - 1][i] == '#')//up check
            a++;
        if (map[j + 1][i] == '#')//down check
            a++;
    }
    if (j == start)//zone1 and zone4
        if (map[j + 1][i] == '#')//down check
            a++;
    return (a);
}

void change_map_upleft(char **map, int figure[4][2], int start)
{
    int min_x;
    int min_y;

    min_x = min_4(figure[0][0], figure[1][0], figure[2][0], figure[3][0]);
    min_y = min_4(figure[0][1], figure[1][1], figure[2][1], figure[3][1]);
    if ((min_x != 0) || (min_y != 0))
    {
        map[(figure[0][1])][(figure[0][0])] = '.';
        map[(figure[1][1])][(figure[1][0])] = '.';
        map[(figure[2][1])][(figure[2][0])] = '.';
        map[(figure[3][1])][(figure[3][0])] = '.';
        map[(figure[0][1]) - (min_y - start)][(figure[0][0]) - min_x] = '#';//moving to left and up
        map[(figure[1][1]) - (min_y - start)][(figure[1][0]) - min_x] = '#';//each coordinate of
        map[(figure[2][1]) - (min_y - start)][(figure[2][0]) - min_x] = '#';//each figure
        map[(figure[3][1]) - (min_y - start)][(figure[3][0]) - min_x] = '#';//
    }
}

int number_of_contacts(char **map, int i, int j, int end, int start)
{
    int a;

    if (map[j][i + 1] == '#')//right check
        a++;
    if (i > 0)
    {
        if (map[j][i - 1] == '#')//left check
            a++;
        a = check_zone(map, i, j, end, start);
    }
    if (i == 0)
        a = check_zone(map, i, j, end, start);
    return (a);
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
    //square[n - 1 ] = 0;
    i = 0;
    while (i < n - 1)
    {
        square[i] = ft_strsub("...........", 0, n - 1);
        ft_putstr(square[i]);
        ft_putchar('\n');
        i++;
    }
return(square);
}

int ***find_coordinates(char **map) {
    int ***cordinates;//[26][4][2];
    int number_of_figures;
    int i;
    int j;
    int z;
    int start;
    int end;
    int x;
    int y;

    i = 0;
    j = 0;
    number_of_figures = (number_of_rows(map) + 1) / 4;//igual a 8
    cordinates = (int ***)ft_memalloc(sizeof(int **) * number_of_figures);//masiv 3d, creamos la mas superficial
    while (i < number_of_figures)//el ciclo se repite 8 veces xq empieza desde cero y son 8 xq son 8 figuras
    {
        cordinates[i] = (int **)ft_memalloc(sizeof(int *) * 4);//vamos creando los elementos del masiv 2d dentro del 3d uno por uno
        j = 0;
        while (j < 4)//se repite 4 veces porque solo deben existir 4 coordenadas por figura
        {
            cordinates[i][j] = (int *)ft_memalloc((sizeof(int) * 1));//creamos los elementos del masiv 1d como en el caso anterior,2xq solo hay x y z
            j++;
        }
        i++;
    }
    //ahora existe un espacio de 8 puestos, en cada puesto hay 4, y en cada uno de los 4 hay 2
    i = 0;
    j = 0;
    z = -1;
    start = 0;
    end = 3;
    x = 0;
    y = -1;
    //now we check the map and get the coordinates where is # in each figure
    while(j <= (number_of_rows(map)))//de cero hasta 31
    {
        i = 0;
        while (i < 4)
        {
            if ((j == start) && (i == 0)) {
                z++;
            }//numero de figura, tiene que aumentar 8 veces empezando desde -1
            x = 0;
            if (map[j][i] == '#')
            {
                y++;
                cordinates[z][y][x] = j;// copiamos la coordenada j en y
                x++;//pasamos a la segunda coordenada x
                cordinates[z][y][x] = i;// copiamos la coordenada i en x
            }
            if (j == end)
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
    return(cordinates);
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

char **ft_solve_fillit(int ***coordinates, char **sol_space, int i, int j, int *l, int n)//increment is the possible extension of the map
{

    int max_sol;
    int letter;
    int increment;
    int m;
    int last;

    m = 0;
    last = 27;
    increment = 0;
    max_sol = 0;
    while (sol_space[m])
        max_sol = m++;
    letter = 'A' + l[n];
    if(i <= max_sol && j<= max_sol && n < 8 && letter < 73)
    {
        if ((j == max_sol) && (i < max_sol))
        {
            i++;
            j = -1;
        }
        if (j < max_sol)
            j++;
        if (sol_space[i][j] == '.')
        {
            if (((coordinates[l[n]][1][0]) - ((coordinates[l[n]][0][0]) - i)) > max_sol ||
                ((coordinates[l[n]][2][0]) - ((coordinates[l[n]][0][0]) - i)) > max_sol ||
                ((coordinates[l[n]][3][0]) - ((coordinates[l[n]][0][0]) - i)) > max_sol) {
                ft_putstr("make map bigger");
                ft_putchar('\n');
                increment++;
                sol_space = solution_space(31, increment);
                i = 0;
                j = -1;
                l = 0;
            } else if ((sol_space[(coordinates[l[n]][1][0]) - ((coordinates[l[n]][0][0]) - i)][(coordinates[l[n]][1][1]) - ((coordinates[l[n]][0][1]) - j)] == '.')
                       && (sol_space[(coordinates[l[n]][2][0]) - ((coordinates[l[n]][0][0]) - i)][(coordinates[l[n]][2][1]) - ((coordinates[l[n]][0][1]) - j)] == '.')
                       && (sol_space[(coordinates[l[n]][3][0]) - ((coordinates[l[n]][0][0]) - i)][(coordinates[l[n]][3][1]) - ((coordinates[l[n]][0][1]) - j)] == '.'))
            {
                sol_space[i][j] = letter;
                sol_space[(coordinates[l[n]][1][0]) - ((coordinates[l[n]][0][0]) - i)][(coordinates[l[n]][1][1]) -
                                                                                 ((coordinates[l[n]][0][1]) - j)] = letter;
                sol_space[(coordinates[l[n]][2][0]) - ((coordinates[l[n]][0][0]) - i)][(coordinates[l[n]][2][1]) -
                                                                                 ((coordinates[l[n]][0][1]) - j)] = letter;
                sol_space[(coordinates[l[n]][3][0]) - ((coordinates[l[n]][0][0]) - i)][(coordinates[l[n]][3][1]) -
                                                                                 ((coordinates[l[n]][0][1]) - j)] = letter;
                n++;
            }
        }
        sol_space = ft_solve_fillit(coordinates, sol_space, i, j, l, n);
    }
    return (sol_space);
}
int		main()//int argc, char **argv)
{
    int max_sol;
    int i;
    int j;
    int a;
    int max_rows;
    int col;
    char buf[SIZE_MAP + 1];
    char **map;
    char **sol_space;
    int ***coordinates;
    int figure[4][2];
    int start;
    int end;
    int n;// number of #
    int x;
    int y;
    int k;


    n = 0;
    j = 0;
    start = 0;
    end = 3;
    a = 0;
    x = 0;
    y = 0;
    buf[read(open("sample.fillit", O_RDONLY), buf, SIZE_MAP)] = '\0';
    map = ft_strsplit(buf, '\n');
    max_rows = number_of_rows(map);// max_rows is 31 in this example
    if (!(symbols_check(max_rows, map)))
        return (0);
    i = 0;
    col = 0;
    while(col <= (max_rows))//en este ciclo se repite el mismo col 3 veces y se va aumentando i, y solo cuando i llega a 3 se aumenta col
    {
        if (map[j][i] == '#')
        {
            figure[x][y] = i;//guardamos las coordenadas de las figuras
            y++;
            figure[x][y] = j;
            y = 0;
            x++;
            n++;//kolichestvo of #
            a = a + number_of_contacts(map, i, j, end, start);//number of contacts
        }
        if (i == 3)
        {
            i = -1;
            j++;
            col++;
        }
        if ((j == end + 1) && (i == -1))
        {
            if (!((a == 8) && (n == 4)))
                if ((a > 6) || (n > 4))
                {
                    ft_putstr("Is not a tetramino");
                    return (0);
                }
            a = 0;// hacemos cero la cantidad de contactos de cada #
            n = 0;// nos muestra la cantidad de # que hay en un espacio 4x4
            x = 0;//coordenadas en y de las figuras
            change_map_upleft(map, figure, start);
            if (end < max_rows)
            {
                start = start + 4;
                end = end + 4;
            }
        }
        i++;
    }
    i = 0;
    while(map[i])//print the changed map
    {
        ft_putstr(map[i]);
        ft_putchar('\n');
        i++;
    }
    i = 0;
    sol_space = solution_space(max_rows, 0);
    ft_putstr("SOL");
    ft_putchar('\n');
    while(sol_space[i])
    {
        ft_putnbr(i);
        ft_putstr(sol_space[i]);
        ft_putchar('\n');
        i++;
    }
    i = 0;
    j = 0;
    k = 0;
    coordinates = find_coordinates(map);
    ft_putstr("COORDINATES: ");
    ft_putchar('\n');
    while(i <  8)
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
   int *l;
    l = (int*)malloc(sizeof(int) * 8);
    l[0] = 0;
    l[1] = 1;
    l[2] = 2;
    l[3] = 4;
    l[4] = 5;
    l[5] = 6;
    l[6] = 7;
    l[7] = 3;
    //lets start to print the answer
    sol_space = ft_solve_fillit(coordinates, sol_space, 0, -1, l, 0);
    ft_putstr("FINAL SOLUTION:");
    ft_putchar('\n');
    print_solution(sol_space);
    return (0);
}

