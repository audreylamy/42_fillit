/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesanche <lesanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:43:55 by alamy             #+#    #+#             */
/*   Updated: 2017/12/11 15:31:39 by lesanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		***create_tab(char *str, int nb_block)
{
	char	**flat_tab;
	char	***tab;
	int		block;

	if ((flat_tab = ft_strsplit(str, '\n')) == NULL)
		return (NULL);
	if ((tab = (char***)malloc(nb_block * sizeof(char**))) == NULL)
		return (NULL);
	block = 0;
	while (block < nb_block)
	{
		tab[block] = flat_tab + (block * 4);
		block++;
	}
	return (tab);
}

t_tetri		*create_tetri_struct(char ***tab, int nb_block, int size_map)
{
	t_tetri		*t;
	int			block;
	int			size[2];

	t = (t_tetri*)malloc(sizeof(t_tetri));
	t->nb_block = nb_block;
	t->tab_tab = tab;
	t->size_map = size_map;
	if ((t->size_tetri = (int**)malloc(nb_block * sizeof(int*))) == NULL)
		return (0);
	block = 0;
	while (block < nb_block)
	{
		get_tetra_size(tab, block, size);
		t->size_tetri[block] = (int*)malloc(2 * sizeof(int));
		t->size_tetri[block][0] = size[0];
		t->size_tetri[block][1] = size[1];
		block++;
	}
	return (t);
}

void		get_tetra_size(char ***tab, int block, int size[2])
{
	int a;
	int b;

	size[0] = 0;
	size[1] = 0;
	a = 0;
	while (a < 4)
	{
		b = 0;
		while (b < 4)
		{
			if (tab[block][a][b] != '.' && b > size[1])
				size[1] = b;
			if (tab[block][a][b] != '.' && a > size[0])
				size[0] = a;
			b++;
		}
		a++;
	}
	size[0]++;
	size[1]++;
}

char		**map_create(int size_map)
{
	char	**map;
	int		x;
	int		y;

	x = 0;
	y = 0;
	map = (char **)malloc(sizeof(char*) * size_map);
	if (map == NULL)
		return (0);
	while (x < size_map)
	{
		map[x] = (char *)malloc(sizeof(char) * size_map);
		if (map == NULL)
			return (0);
		while (y < size_map)
		{
			map[x][y] = '.';
			y++;
		}
		y = 0;
		x++;
	}
	return (map);
}
