#include "../../Include/minishell.h"

void	check_dollar(char **dst, char **src)
{
	char	*ptr;

	ptr = (*src) + 1;
	if (*ptr == *DOLLAR)
		double_dollar(dst, src);
	else if (*ptr == *QUSTION_MARK)
		question_mark(dst, src);
	else if (*ptr == ' ' || !*ptr || *ptr == *DOUBLE_QUOTE
	|| *ptr == *SINGLE_QUOTE )
		single_dollar(dst);
	else
		set_envs(dst, src);
}

void	double_dollar(char **dst, char **src)
{
	char	*line;

	line = ft_itoa(getpid());
	own_strjoin(dst, line);
	free(line);
	(*src)++;
}

void	question_mark(char **dst, char **src)
{
	char	*line;

	line = ft_itoa(core.old_exec_output);
	own_strjoin(dst, line);
	free(line);
	(*src)++;
}

void	single_dollar(char **dst)
{
	str_addchar(dst, *DOLLAR);
}


