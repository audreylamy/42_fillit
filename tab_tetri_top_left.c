/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_tetri_top_left.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesanche <lesanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 14:54:30 by alamy             #+#    #+#             */
/*   Updated: 2017/12/11 12:54:07 by lesanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	find_min_position(char ***tab_tab, int num_block, int min_pos[2])
{
	int x;
	int y;

	x = 0;
	y = 0;
	min_pos[0] = 3;
	min_pos[1] = 3;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (tab_tab[num_block][x][y] != '.')
			{
				if (x < min_pos[0])
					min_pos[0] = x;
				if (y < min_pos[1])
					min_pos[1] = y;
			}
			y++;
		}
		x++;
	}
}

void	put_tetri_top_left(char ***tab, int nb_block)
{
	int min_p[2];
	int x;
	int y;
	int n_b;

	n_b = 0;
	while (n_b < nb_block)
	{
		find_min_position(tab, n_b, min_p);
		x = 0;
		while (x < 4)
		{
			y = 0;
			while (y < 4)
			{
				if ((x < 4 - min_p[0]) && (y < 4 - min_p[1]))
					tab[n_b][x][y] = tab[n_b][x + min_p[0]][y + min_p[1]];
				else
					tab[n_b][x][y] = '.';
				y++;
			}
			x++;
		}
		n_b++;
	}
}
