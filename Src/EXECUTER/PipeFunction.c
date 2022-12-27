#include "../../Include/minishell.h"

int		cmd_table_len(t_cmdlist *cmd_list)
{
	int	i = 0;
	while (cmd_list)
	{
		i++;
		cmd_list = cmd_list->next;
	}
	return (i);
}

int		*create_pipe()
{
	int		index;
	int		pipe_len;
	int		*fd;

	pipe_len = cmd_table_len(core.cmd_table) * 2;
	fd = (int *)malloc(sizeof(int) * pipe_len);
	index = 0;
	while (index < pipe_len)
	{
		pipe(&fd[index]);
		index += 2;
	}
	return(fd);
}

void	clear_pipe(int *fd)
{
	int	index;
	int	fd_len;

	if (fd)
	{
		index = -1;
		fd_len = cmd_table_len(core.cmd_table) * 2;
		while (++index < fd_len)
			close(fd[index]);
		free(fd);
	}
}
