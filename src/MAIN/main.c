/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 02:08:09 by aozsayar          #+#    #+#             */
/*   Updated: 2022/12/31 19:19:40 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	minusc(char *cmd)
{
	update_loop();
	g_core.cmd = cmd;
	exit_signal_check();
	lexer();
	expander();
	parser();
	executer();
	update_history(g_core.cmd);
	return (g_core.exec_output);
}

int	main(int argc, char **argv, char **env)
{
	init_core(env);
	signal(SIGINT, &sig_handler);
	if (argc != 1 && str_compare(argv[1], "-c"))
		return (minusc(argv[2]));
	while (1)
	{
		update_loop();
		g_core.cmd = readline(g_core.title.full_title);
		exit_signal_check();
		lexer();
		expander();
		parser();
		executer();
		update_history(g_core.cmd);
		free_for_loop();
	}
	free_core();
}
