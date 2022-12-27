#include "../../Include/minishell.h"

int		env_arg_control(char *env)
{
	int	flag;
	int	env_len;

	if (!env)
		return (0);
	flag = 0;
	env_len = ft_strlen(env);
	if ((*env >= 'a' && env[env_len] <= 'z') ||
		(*env >= 'A' && env[env_len] <= 'Z'))
		flag = 1;
	while (*env)
	{
		if ((*env > '0' && *env < '9' && !flag)
			|| compare_metachars(env) || *env == ' ')
			return (0);
		env++;
	}
	return (1);
}

int		change_env(char *envname, char *arg, int is_equal)
{
	t_env	*env;

	env = core.env_table;
	while (env)
	{
		if (str_compare(envname, env->env_name))
		{
			if (is_equal)
				update_env(envname, arg);
			return (1);
		}
		env = env->next;
	}
	return (0);
}

void	single_export_arg(t_cmdlist *cmd_node)
{
	char	*content;
	t_env	*env;

	env = core.env_table;
	while (env)
	{
		write(cmd_node->outfile, "declare -x ", 11);
		write(cmd_node->outfile, env->env_name, ft_strlen(env->env_name));
		if (!env->content)
		{
			write(cmd_node->outfile, "\n", 1);
			env = env->next;
			continue;
		}
		write(cmd_node->outfile, "=\"", 2);
		content++;
		write(cmd_node->outfile, env->content, ft_strlen(env->content));
		write(cmd_node->outfile, "\"\n", 2);
		env = env->next;
	}
}

void	double_export_arg(char *env_cmd)
{
	char	*arg;
	int		is_equal;
	t_env	*env;
	char	*temp_envname;

	if (!env_arg_control(env_cmd))
	{
		print_error("-bash: export: `", env_cmd, "': not a valid identifier\n");
		core.exec_output = 1;
		return;
	}
	temp_envname = get_env_name(env_cmd);
	arg = env_cmd + ft_strlen(temp_envname);
	is_equal = 0;
	if (*arg == '=')
		is_equal |= 1;
	if (change_env(temp_envname, ++arg, is_equal))
	{
		free(temp_envname);
		return ;
	}
	env = core.env_table;
	add_newenv(&env, env_cmd);
	if (!is_equal)
		update_env(env_cmd, NULL);
	free(temp_envname);
}

void	run_export(t_cmdlist *cmd_node)
{
	int		array_len;
	char	**temp_path;

	array_len = get_array_len(cmd_node->path);
	if (array_len > 1)
	{
		temp_path = cmd_node->path;
		while (*(++temp_path))
			double_export_arg(*temp_path);
	}
	else
		single_export_arg(cmd_node);
}
