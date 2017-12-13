/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesanche <lesanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:56:07 by lesanche          #+#    #+#             */
/*   Updated: 2017/12/11 17:43:43 by lesanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_lets_go_resolution(char *buffer, int nb)
{
	char		***tab;
	int			nb_block;
	t_tetri		*t;
	int			size_map;

	buffer[nb] = '\n';
	nb_block = (nb + 2) / 21;
	tab = create_tab(buffer, nb_block);
	if (!check_tab(tab, nb_block))
	{
		write(1, "error\n", 6);
		return ;
	}
	put_tetri_top_left(tab, nb_block);
	size_map = ft_sqrt_fillit(nb_block * 4);
	t = create_tetri_struct(tab, nb_block, size_map);
	resolution(t);
}

void		resolution(t_tetri *t)
{
	char	**map;
	int		size_map;

	size_map = t->size_map;
	map = map_create(size_map);
	if (map_solve(map, t, 0))
	{
		print_map(map, size_map);
		return ;
	}
	t->size_map++;
	resolution(t);
}

void		print_map(char **map, int size_map)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (a < size_map)
	{
		while (b < size_map)
		{
			ft_putchar(map[a][b]);
			b++;
		}
		ft_putchar('\n');
		b = 0;
		a++;
	}
}
