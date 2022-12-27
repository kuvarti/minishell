#include "../../Include/minishell.h"

void	init_core(char **env)
{
	fill_envs(env);
	set_metachars();
	set_title();
	core.heradoc_fd = 0;
	core.exec_output = 0;
}
