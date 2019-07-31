/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <nshelly@student.21school>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 17:12:33 by nshelly           #+#    #+#             */
/*   Updated: 2019/07/31 17:40:09 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>

# define BUFF_SIZE_FILLIT 21

typedef struct		s_sharp
{
	int x;
	int y;
}					t_sharp;

typedef struct		s_tetramino
{
	t_sharp	sharp[4];
	char	name;
}					t_tet;

int					print_figure(int ***c, char **sp, int l, int i, int j);
int					check_vertical(int ***c, int max_sol, int i, int l);
int					check_and_print(int ***c, char **sp, int l, int i, int j);
void				print_solution(char **s);
int					ft_solve_fillit(int ***c, char **sp, int *l, int figures);
void				clean_map(char **map, int max_sol);
int					max_solution(char **sp);
void				ft_swp(int *a, int *b);
int					*copy_next(int const *a, int *b, int n);
int					*create_first(int *c, int n);
int					factorial(int value);
char				**sp(int max_rows, int increment);
int					all_solutions(int n, char **sp, int ***c);
int					nr(char **map);
void				limits_in_coords(int *start, int *end, int *j, int *y);
int					***find_coordinates(char **map, int ***coordinates,\
		int start, int end);
int					***triple_arr(char **map);
char				***ft_searcher(char ***coords, char **map, int nbr_of_tetr);
char				*reader(int fd);
int					**double_array(int n);

#endif
