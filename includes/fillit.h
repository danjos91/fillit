/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:12:48 by ryaoi             #+#    #+#             */
/*   Updated: 2019/08/14 17:45:27 by nshelly          ###   ########.fr       */
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

typedef struct		s_coord
{
	char			c;
	int				x[4];
	int				y[4];
	struct s_coord	*next;
}					t_coord;

void				clean_map(char **map);
int					check_order(char *buf);
int					check(char *buf, int bytes);
char				*reader(int fd);
char				**sp(int max_rows, int increment);
int					count_figures(char *str);
void				set_coordinates(t_coord **tmp, char *str);
t_coord				*get_coords(char *str);
void				ft_upleft(t_coord **figures, int x, int y);
char				**brute_force(char **tetri_map, t_coord *figures);
void				solve(t_coord *figures, int numb_of_figures);
void				print_map(char **map);
char				**delete_figure(char **map, t_coord *figures, int size);
char				**print_figure(char **map, t_coord *figures, int size);
int					check_figure(char **map, t_coord *figures, int size);
int					max_solution(char **sp);

#endif
