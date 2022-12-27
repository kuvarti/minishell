#include "../../Include/minishell.h"

void create_dup(t_cmdlist *cmd_list, int *fd, int fd_index)
{
	if (cmd_list->infile > Stderr)
		dup2(cmd_list->infile, STDIN_FILENO);
	else if (fd && cmd_list != core.cmd_table)
		dup2(fd[fd_index - 2], STDIN_FILENO);
	if (cmd_list->outfile > Stderr)
		dup2(cmd_list->outfile, STDOUT_FILENO);
	else if (fd && cmd_list->next)
		dup2(fd[fd_index + 1], STDOUT_FILENO);
	if (fd_index >= 0)
		clear_pipe(fd);
	if (fd_index >= 0 && (cmd_list->infile == Stderr || cmd_list->outfile == Stderr))
	{
		free_for_loop();
		free_core();
		exit(1);
	}
}
