/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <nshelly@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 18:13:19 by nshelly           #+#    #+#             */
/*   Updated: 2019/07/30 18:13:21 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#define SIZE_MAP 546//max bytes if 26 tetraminos max

int ft_solve_fillit(int ***c, char **sp, int *l, int figures);
int all_solutions(int n, char **sp, int ***c);
int number_of_rows(char **map);
char    **solution_space(int max_rows, int increment);
int ***triple_arr(char **map);
void    limits_in_coords(int *start, int *end, int *j, int *y);
int ***find_coordinates(char **map, int ***coordinates, int start, int end);
void    print_solution(char **s);
void    clean_map(char **map, int max_sol);
int max_solution(char **sp);
int *copy_next(int const *a, int *b, int n);
int *create_first(int *c, int n);
int check_figure(int ***c, int max_sol, int i, int l);
int print_figure(int ***c, char **sp, int l, int i, int j);
int check_and_print(int ***c, char **sp, int l, int i, int j);
void    ft_swp(int *a, int *b);
int factorial(int value);