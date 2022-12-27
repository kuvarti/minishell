#include "../../Include/minishell.h"

void	free_metachars()
{
	char	**temp_metachars;

	temp_metachars = core.metachars;
	if (!temp_metachars)
		return ;
	while (temp_metachars && *temp_metachars)
		free(*(temp_metachars++));
	free(core.metachars);
}

void	free_envtable()
{
	t_env	*env;
	t_env	*temp_env;

	env = core.env_table;
	while (env)
	{
		temp_env = env;
		env = env->next;
		free(temp_env->env_name);
		free(temp_env->content);
		free(temp_env);
	}
}

void 	free_title()
{
	free(core.title.full_title);
	free(core.title.head);
}
