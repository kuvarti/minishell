/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:59:44 by aeryilma          #+#    #+#             */
/*   Updated: 2022/09/28 16:43:43 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lexer(char *input)
{
	char	**name;

	if (!input)
		return ;
	name = ft_split(input, ' ');
	ft_isbin(name);
}

void	addhistory(char *text, int fd)
{
	if (!text)
		return ;
	add_history(text);
	write(fd, text, ft_strlen(text));
	write(fd, "\n", 1);
}

void	initializator(void)
{
	signal(SIGINT, ft_sigint);
}

int	main(int argc, char **argv, char **env)
{
	char	*line;
	int		fd;

	if (!argc || !argv || !env)
		return (printf("Hata : 0") * 0);
	initializator();
	fd = open(".history", O_RDWR | O_CREAT);
	while (1)
	{
		line = getinput();
		addhistory(line, fd);
		lexer(line);
		//printf("line : %s\n", line);
	}
}
