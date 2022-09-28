/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestrjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:18:08 by aeryilma          #+#    #+#             */
/*   Updated: 2022/09/13 15:21:00 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_freestrjoin(char *s1, char *s2)
{
	char	*ret;
	int		index;
	int		s1len;

	if (!s1 || !s2)
		return (NULL);
	index = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc(sizeof(char) * (index + 1));
	if (!(ret))
		return (0);
	index = 0;
	while (s1[index] != '\0')
	{
		ret[index] = s1[index];
		index++;
	}
	free(s1);
	s1len = index;
	while (s2[index - s1len] != '\0')
	{
		ret[index] = s2[index - s1len];
		index++;
	}
	free(s2);
	ret[index] = '\0';
	return (ret);
}
