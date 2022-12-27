#include "../../Include/minishell.h"

char	*get_cmd(char *cmd)
{
	int		command_len;

	command_len = 0;
	while (*cmd)
	{
		command_len++;
		if (*cmd == '/')
			command_len = 0;
		cmd++;
	}
	return (cmd - command_len);
}

void	run_command(t_cmdlist *cmd_node, int *fd, int fd_index)
{
	char	*cmd;
	int		builtin_index;

	if(cmd_node && !cmd_node->cmd)
		return ;
	cmd = get_cmd(cmd_node->cmd);
	builtin_index = is_builtin(cmd);
	if (builtin_index)
		run_builtin(cmd_node, builtin_index, fd, fd_index);
	else
		run_execve(cmd_node, fd, fd_index);
}

void	run_single_command(t_cmdlist *cmd_list, int *fd)
{
	if (cmd_list->infile != Stderr && cmd_list->outfile != Stderr)
		run_command(cmd_list, fd, -1);
}

void	run_multiple_command(t_cmdlist *cmd_list)
{
	int			*fd;
	int			fd_count;

	fd_count = 0;
	fd = create_pipe();
	while (cmd_list)
	{
		cmd_list->pid = fork();
		if (cmd_list->pid <= 0 )
			run_process(cmd_list, fd, fd_count);
		fd_count += 2;
		cmd_list = cmd_list->next;
	}
	clear_pipe(fd);
	wait_all();
}
