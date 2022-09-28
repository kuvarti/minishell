/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinchrcount.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:25:21 by aeryilma          #+#    #+#             */
/*   Updated: 2022/09/13 15:33:45 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strinchrcount(char const *str, char chr)
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str == chr)
			i++;
		str++;
	}
	return (i);
}
/*
#include "stdio.h"
int main()
{
	printf("%d", ft_strinchrcount("", '\"'));
}
*/
