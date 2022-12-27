#include "../../Include/minishell.h"

void	run_process(t_cmdlist *cmd_list, int *fd, int fd_index)
{
	if (cmd_list->infile != Stderr && cmd_list->outfile != Stderr)
		run_command(cmd_list, fd, fd_index);
	free_for_loop();
	free_core();
	exit(core.exec_output);
}

void	wait_all()
{
	t_cmdlist	*cmd_list;

	cmd_list = core.cmd_table;
	while (cmd_list)
	{
		waitpid(cmd_list->pid, &core.exec_output, 0);
		cmd_list = cmd_list->next;
	}
}
