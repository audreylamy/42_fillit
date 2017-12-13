/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:21:47 by alamy             #+#    #+#             */
/*   Updated: 2017/12/12 15:07:04 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		is_posible_pos(char **map, t_tetri *t, int block, int pos[2])
{
	int		a;
	int		b;
	char	***tab;
	int		size_map;

	size_map = t->size_map;
	tab = t->tab_tab;
	if ((t->size_tetri[block][0] + pos[0] > size_map) ||
		(t->size_tetri[block][1] + pos[1] > size_map))
		return (0);
	a = 0;
	while (a < t->size_tetri[block][0])
	{
		b = 0;
		while (b < t->size_tetri[block][1])
		{
			if ((tab[block][a][b] != '.') &&
				(map[a + pos[0]][b + pos[1]] != '.'))
				return (0);
			b++;
		}
		a++;
	}
	return (1);
}

void			put_tetri_map(char **map, t_tetri *t, int num_block, int pos[2])
{
	int		a;
	int		b;
	char	***tab;

	tab = t->tab_tab;
	a = 0;
	while (a < 4)
	{
		b = 0;
		while (b < 4)
		{
			if (tab[num_block][a][b] != '.')
				map[pos[0] + a][pos[1] + b] = 'A' + num_block;
			b++;
		}
		a++;
	}
}

static char		**erase_tetri(char **map, int block, int pos[2], int size_map)
{
	int a;
	int b;

	a = 0;
	while ((a < 4) && (a + pos[0] < size_map))
	{
		b = 0;
		while ((b < 4) && (b + pos[1] < size_map))
		{
			if (map[a + pos[0]][b + pos[1]] == 'A' + block)
				map[a + pos[0]][b + pos[1]] = '.';
			b++;
		}
		a++;
	}
	return (map);
}

int				map_solve(char **map, t_tetri *t, int num_block)
{
	int pos[2];
	int size_map;

	size_map = t->size_map;
	if (num_block == t->nb_block)
		return (1);
	pos[0] = 0;
	while (pos[0] + t->size_tetri[num_block][0] <= size_map)
	{
		pos[1] = 0;
		while (pos[1] + t->size_tetri[num_block][1] <= size_map)
		{
			if (is_posible_pos(map, t, num_block, pos))
			{
				put_tetri_map(map, t, num_block, pos);
				if (map_solve(map, t, num_block + 1))
					return (1);
			}
			erase_tetri(map, num_block, pos, size_map);
			pos[1]++;
		}
		pos[0]++;
	}
	return (0);
}
