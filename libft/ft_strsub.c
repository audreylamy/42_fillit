/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 09:43:19 by alamy             #+#    #+#             */
/*   Updated: 2017/11/17 18:51:23 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char			*copys;
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	copys = (char *)malloc(sizeof(*copys) * (len + 1));
	if (!copys)
		return (NULL);
	while (i < len)
	{
		copys[i] = s[start + i];
		i++;
	}
	copys[i] = '\0';
	return (copys);
}
