#include "../../Include/minishell.h"

void	update_exec_output()
{
	core.exec_output = core.exec_output ^ core.old_exec_output;
	core.old_exec_output = core.exec_output ^ core.old_exec_output;
	core.exec_output = core.exec_output ^ core.old_exec_output;
	core.exec_output = 0;
}

int	main(int argc, char **argv, char **env)
{
	init_core(env);
	while (1)
	{
		core.cmd = readline(core.title.full_title);
		update_exec_output();
		lexer();
		//print_lexer();
		expander();
		//print_expander();
		parser();
		//print_parser();
		executer();
		update_history(core.cmd);
		free_for_loop();
	}
	free_core();
}
