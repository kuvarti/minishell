/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputcmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 00:28:15 by aeryilma          #+#    #+#             */
/*   Updated: 2022/12/29 00:36:50 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//25 satıra azaltmak için
static void	frees(char *s1, char *s2)
{
	free(s1);
	free(s2);
}

static char	*ft_freestrjoin(char *s1, char *s2)
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
	s1len = index;
	while (s2[index - s1len] != '\0')
	{
		ret[index] = s2[index - s1len];
		index++;
	}
	frees(s1, s2);
	ret[index] = '\0';
	return (ret);
}

static int	ft_strinchrcount(char const *str, char chr)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == chr)
			i++;
		str++;
	}
	return (i);
}

static char	*wait_theline(void)
{
	char	*ret;

	ret = readline(g_core.title.full_title);
	while (!(ft_strinchrcount(ret, '\"') % 2 == 0)
		|| !(ft_strinchrcount(ret, '\'') % 2 == 0))
	{
		ret = ft_freestrjoin(ret, ft_strdup("\n"));
		ret = ft_freestrjoin(ret, readline("dquote> "));
	}
	return (ret);
}

char	*input_cmd(void)
{
	char	*ret;

	ret = wait_theline();
	return (ret);
}
