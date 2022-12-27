#include "../../Include/minishell.h"


void	close_heradoc_file()
{
	if (core.heradoc_fd > Stderr)
		core.heradoc_fd = close(core.heradoc_fd);
}

void	open_heradoc_file(char	*create_mode)
{
	char	*heracoc_path;
	char	ptr[256];

	heracoc_path = NULL;
	own_strjoin(&heracoc_path, (char *)getcwd(ptr, 256));
	str_addchar(&heracoc_path, '/');
	own_strjoin(&heracoc_path, "heradoc");
	if (str_compare(create_mode, "READ"))
		core.heradoc_fd = open(heracoc_path, O_RDONLY, 777);
	else
		core.heradoc_fd = open(heracoc_path, O_WRONLY | O_CREAT | O_TRUNC);
	free(heracoc_path);
}
