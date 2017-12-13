/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesanche <lesanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 10:06:02 by lesanche          #+#    #+#             */
/*   Updated: 2017/12/11 13:51:34 by lesanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt_fillit(int nb)
{
	int a;
	int b;
	int c;
	int	nb_integrer;

	nb_integrer = 0;
	a = 0;
	b = nb / 2;
	while (a < b)
	{
		c = (a + b) / 2;
		if (c * c < nb)
			a = c + 1;
		else
			b = c;
	}
	if (a * a == nb)
		return (a);
	else
		while (nb_integrer < a)
			nb_integrer++;
	return (nb_integrer);
}
