#include "../../Include/minishell.h"

void	create_infile (t_cmdlist *node, t_filelist *file)
{
	char	*pwd;
	int		is_access;
	char	ptr[256];

	if (file->metachar[1] == DOUBLE_LESS[1])
	{
		node->infile = core.heradoc_fd;
		return ;
	}
	if (raise_file_error(file, &node->infile))
		return;
	pwd = NULL;
	own_strjoin(&pwd, (char *)getcwd(ptr, 256));
	str_addchar(&pwd, '/');
	own_strjoin(&pwd, file->filename);
	is_access = access(pwd, F_OK);
	if (!is_access)
		file->fd =  open(pwd, O_RDONLY);
	else
	{
		print_error("-bash: ", file->filename, ": No such file or directory\n");
		core.exec_output = 1;
		file->fd = Stderr;
	}
	node->infile = file->fd;
	free(pwd);
}
