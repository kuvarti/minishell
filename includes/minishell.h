/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:38:46 by aeryilma          #+#    #+#             */
/*   Updated: 2022/09/28 13:11:13 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//* Standart Lib(s)
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <dirent.h>
# include "libft.h"
# include<signal.h>

//! RL... functs
# include <readline/readline.h>
# include <readline/history.h>

//? system and terminal calls
# include <curses.h>
# include <termios.h>

//? That should be detach
# include <sys/ioctl.h>
# include <sys/wait.h>
# include <sys/stat.h>

char	*getinput(void);
int		ft_isbin(char **input);

void	ft_sigint(int sig);

#endif
