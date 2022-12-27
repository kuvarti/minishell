#include "../../Include/minishell.h"

char	*create_search_arg(char **envs, char *search_arg_name)
{
	char	*ptr;
	int		count;
	char	*temp_envs;

	count = 0;
	temp_envs = *envs;
	while (*temp_envs && *temp_envs != ':')
	{
		count++;
		temp_envs++;
		(*envs)++;
	}
	if (!count)
		return (NULL);
	if (**envs)
		(*envs)++;
	ptr = (char *)malloc(sizeof(char) * (count + 1));
	ptr[count] = 0;
	while(--count > -1)
		ptr[count] = *(--temp_envs);
	str_addchar(&ptr, '/');
	own_strjoin(&ptr, search_arg_name);
	return (ptr);
}

void	control_path(char **dst, char *content)
{
	char	*control_ptr;

	while (content && *content)
	{
		control_ptr = create_search_arg(&content, *dst);
		if (!access(control_ptr, F_OK))
		{
			free(*dst);
			*dst = control_ptr;
			return ;
		}
		free(control_ptr);
	}
}

void	expand_from_env(char **dst)
{
	t_env	*temp_env;

	temp_env = core.env_table;
	while (temp_env)
	{
		if (str_compare("PATH", temp_env->env_name))
		{
			control_path(dst, temp_env->content);
			return ;
		}
		temp_env = temp_env->next;
	}
}
