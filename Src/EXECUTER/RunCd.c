#include "../../Include/minishell.h"

void	handle_oldpwd(char *oldpwd, int is_pwdaccess)
{
	t_env	*temp_env;
	char	*temp_oldpwd;

	if (is_pwdaccess)
	{
		if (!update_env("OLDPWD", oldpwd))
		{
			temp_env = core.env_table;
			temp_oldpwd = NULL;
			own_strjoin(&temp_oldpwd, "OLDPWD=");
			own_strjoin(&temp_oldpwd, oldpwd);
			add_newenv(&temp_env, temp_oldpwd);
			free(temp_oldpwd);
		}
	}
	else
		update_env("OLDPWD", NULL);
}

int		change_dir(char *path)
{
	char	pwd[256];
	char	old_pwd[256];
	int		is_pwdaccess;
	char	*oldpwd;
	int		error;

	oldpwd = ft_strdup(getcwd(old_pwd, 256));
	error = chdir(path);
	if (error == -1)
	{
		free(oldpwd);
		return (0);
	}
	is_pwdaccess = update_env("PWD", getcwd(pwd, 256));
	handle_oldpwd(oldpwd, is_pwdaccess);
	if (oldpwd)
		free(oldpwd);
	change_title();
	return (1);
}

void	cd_single_arg()
{
	t_env	*temp_env;
	char	*content;

	temp_env = core.env_table;
	while (temp_env)
	{
		if (str_compare("HOME", temp_env->env_name))
		{
			content = temp_env->content;
			if (!content)
				return ;
			change_dir(content);
			return;
		}
		temp_env = temp_env->next;
	}
	print_error("-bash: cd: HOME not set\n", NULL, NULL);
	core.exec_output |= 1;
}

void	cd_double_arg(t_cmdlist *cmd_node)
{
	if (!change_dir(cmd_node->path[1]))
	{
		print_error("--bash: cd: ", cmd_node->path[1], ": No such file or directory\n");
		core.exec_output = 1;
	}
}

void	run_cd(t_cmdlist *cmd_node)
{
	int		array_len;

	array_len = get_array_len(cmd_node->path);
	if (array_len > 2)
	{
		core.exec_output = 1;
		print_error("-bash: cd: too many arguments\n", NULL, NULL);
	}
	else if (array_len == 2)
		cd_double_arg(cmd_node);
	else
		cd_single_arg();
}

