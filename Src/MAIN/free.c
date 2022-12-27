#include "../../Include/minishell.h"

void	free_core()
{
	free_metachars();
	free_envtable();
	free_title();
}

void	free_for_loop()
{
	if (core.cmd)
	{
		free(core.cmd);
		core.cmd = NULL;
	}
	free_lexer();
	free_parser();
	close_heradoc_file();
}
