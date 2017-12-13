/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesanche <lesanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:14:32 by lesanche          #+#    #+#             */
/*   Updated: 2017/12/11 14:38:32 by lesanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUF_SIZE 550

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_tetri
{
	int		nb_block;
	char	***tab_tab;
	int		**size_tetri;
	int		size_map;
}				t_tetri;

void			ft_read(char *argv);
int				check_validation(int nb, char *buffer);
char			**map_create(int size_map);
void			resolution(t_tetri	*t);
void			print_map(char **map, int size_map);
int				map_solve(char **map, t_tetri *t, int num_block);
t_tetri			*create_tetri_struct(char ***tab, int nb_block, int size_map);
void			put_tetri_top_left(char ***tab, int nb_block);
char			***create_tab(char *str, int length);
int				is_shape_valid(char *str, int length);
int				check_tab(char ***tab, int nb_block);
void			get_tetra_size(char ***tab_arrange, int num_block, int size[2]);
void			ft_lets_go_resolution(char *buffer, int nb);
int				ft_sqrt_fillit(int nb);
#endif
