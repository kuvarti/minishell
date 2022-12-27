#include "../../Include/minishell.h"

int		get_env_len()
{
	t_env	*env_list;
	int		count;

	env_list = core.env_table;
	count = 0;
	while (env_list)
	{
		if (env_list->content)
			count++;
		env_list = env_list->next;
	}
	return (count);
}

char	**get_env_cpy()
{
	int		env_len;
	char	**envlist;
	char	*temp_env;
	t_env	*temp_envlist;

	env_len = get_env_len();
	envlist = (char **)malloc(sizeof(char *) * (env_len + 1));
	envlist[env_len] = NULL;
	temp_envlist = core.env_table;
	while (temp_envlist)
	{
		if (temp_envlist->content)
		{
			temp_env = NULL;
			own_strjoin(&temp_env, temp_envlist->env_name);
			str_addchar(&temp_env, '=');
			own_strjoin(&temp_env, temp_envlist->content);
			envlist[--env_len] = temp_env;
		}
		temp_envlist = temp_envlist->next;
	}
	return (envlist);
}

void	free_env_cpy(char **envlist)
{
	char	**temp_envlist;

	temp_envlist = envlist;
	while (*temp_envlist)
		free(*(temp_envlist++));
	free(envlist);
}

void	run_execve(t_cmdlist *cmd_node, int *fd, int fd_index)
{
	char	**envlist;
	int		new_pid;

	new_pid = fork();
	if (!new_pid)
	{
		create_dup(cmd_node, fd, fd_index);
		envlist = get_env_cpy();
		if (execve(cmd_node->cmd, cmd_node->path, envlist) == -1)
		{
			if (!cmd_node->cmd)
				print_error(get_cmd(cmd_node->cmd), " command not found\n", NULL);
			free_env_cpy(envlist);
			free_for_loop();
			free_core();
			exit(1);
		}
	}
	if (fd && new_pid)
		clear_pipe(fd);
	waitpid(new_pid, &core.exec_output, 0);
}
