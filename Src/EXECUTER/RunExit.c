#include "../../Include/minishell.h"

void	run_exit()
{
	free_for_loop();
	free_core();
	exit(EXIT_SUCCESS);
}
