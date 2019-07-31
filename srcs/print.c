#include "../includes/fillit.h"

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

int check_figure(int ***c, int max_sol, int i, int l)
{

    if (((c[l][1][0]) - ((c[l][0][0]) - i)) > max_sol || ((c[l][2][0]) - ((c[l][0][0]) - i)) > max_sol ||
        ((c[l][3][0]) - ((c[l][0][0]) - i)) > max_sol)
        return (0);
    return (1);
}