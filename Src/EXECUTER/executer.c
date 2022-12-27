#include "../../Include/minishell.h"

void	executer()
{
	if (!core.cmd_table)
		return ;
	else if (!core.cmd_table->next)
		run_single_command(core.cmd_table, NULL);
	else
		run_multiple_command(core.cmd_table);
}


