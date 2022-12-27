#include "../../Include/minishell.h"

void	expand_envs(char **dst, char *ptr)
{
	t_env	*copy_envs;

	copy_envs = core.env_table;
	while (copy_envs)
	{
		if (str_compare(ptr, copy_envs->env_name))
		{
			own_strjoin(dst, copy_envs->content);
			break;
		}
		copy_envs = copy_envs->next;
	}
}


void	expand_order(char **dst, char **src)
{
	if (**src == *DOLLAR)
		check_dollar(dst, src);
	else
		expand_envs(dst, "HOME");
}

void	set_envs(char **dst, char **src)
{
	int		count;
	char	*ptr;

	count = 0;
	ptr = (*src) + 1;
	while (*ptr != ' ' && *(ptr) && *ptr != *DOUBLE_QUOTE
		&& *ptr != *SINGLE_QUOTE && *ptr != '$')
	{
		count++;
		ptr++;
	}
	ptr = ft_strlcpy(NULL, (*src) + 1, count);
	expand_envs(dst, ptr);
	free(ptr);
	*src += count;
}


