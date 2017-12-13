/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesanche <lesanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 10:20:57 by lesanche          #+#    #+#             */
/*   Updated: 2017/12/11 17:31:44 by lesanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	if (argc < 2 || argc > 2)
		write(1, "usage: fillit[valid file]\n", 26);
	if (argc == 2)
		ft_read(argv[1]);
	return (0);
}

void		ft_read(char *argv)
{
	int		fd;
	int		nb;
	char	buffer[BUF_SIZE + 1];

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		write(1, "error\n", 6);
	}
	if ((nb = read(fd, buffer, BUF_SIZE)) > 0)
	{
		if (is_shape_valid(buffer, nb) == 0)
		{
			write(1, "error\n", 6);
		}
		else
		{
			ft_lets_go_resolution(buffer, nb);
		}
	}
	else
		write(1, "error\n", 6);
	close(fd);
}
