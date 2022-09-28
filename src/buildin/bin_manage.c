/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:35:18 by aeryilma          #+#    #+#             */
/*   Updated: 2022/09/28 12:52:42 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_isbin(char **input)
{
	if (!ft_strncmp(input[0], "cd", ft_strlen(input[0])))
		return (ft_cd(input[1]));
	else if (!ft_strncmp(input[0], "pwd", ft_strlen(input[0])))
		return (ft_pwd());
	else
		return (0);
}
