#include "../../Include/minishell.h"

void	parser()
{
	core.cmd_table = NULL;
	if (core.exec_output)
		return;
	create_cmdtable(core.lex_table);
	fill_cmdtable();
	create_files(core.cmd_table);
}
