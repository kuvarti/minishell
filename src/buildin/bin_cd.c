/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:35:35 by aeryilma          #+#    #+#             */
/*   Updated: 2022/09/28 10:56:30 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_pwd(void)
{
	printf("%s\n", getcwd(NULL, 250));
	return (0);
}

int	ft_cd(char *directory)
{
	if (!directory || !ft_strncmp(directory, ".", 1))
		return (chdir(directory));
	else
		return (chdir(directory));
}

int	ft_echo(const char *string, char option)
{
	printf("%s", string);
	if (option != 'n')
		printf("\n");
	return (0);
}
