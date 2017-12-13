/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 09:33:18 by alamy             #+#    #+#             */
/*   Updated: 2017/11/14 13:15:19 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s1bis;
	int		i;
	int		j;
	int		len1;

	if ((!s1) || (!s2))
		return (0);
	len1 = (ft_strlen((char *)s1));
	s1bis = (char *)malloc(sizeof(*s1bis) * (len1 + ft_strlen((char *)s2)));
	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1bis)
		return (NULL);
	while (s1[j] != '\0')
		s1bis[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		s1bis[i++] = s2[j++];
	s1bis[i] = '\0';
	return (s1bis);
}
