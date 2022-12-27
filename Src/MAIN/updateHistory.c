#include "../../Include/minishell.h"

void	update_history(char *cmd)
{
	char	*ptr;

	if (!cmd)
		return ;
	ptr = cmd;
	trim_spaces(&ptr);
	if (!*ptr)
		return ;
	add_history(cmd);
}
