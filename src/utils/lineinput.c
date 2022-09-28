/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lineinput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:58:25 by aeryilma          #+#    #+#             */
/*   Updated: 2022/09/20 22:09:29 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char *wait_theLine(void)
{
	char	*ret;

	ret = readline("minishell>$ ");
	while (!(ft_strinchrcount(ret, '\"') % 2 == 0)
		|| !(ft_strinchrcount(ret, '\'') % 2 == 0))
	{
		ret = ft_freestrjoin(ret, ft_strdup("\n"));
		ret = ft_freestrjoin(ret, readline("dquote> "));
	}
	return (ret);
}

char *getinput(void)
{
	char	*ret;

	ret = wait_theLine();
	ret = ft_freestrtrim(ret, " ");
	return (ret);
}
