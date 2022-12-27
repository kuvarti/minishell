#include "../../Include/minishell.h"

int		raise_file_error(t_filelist *file, int *file_output)
{
	int		error;
	char	*file_name;

	file_name = file->filename;
	error = 0;
	while (file_name && *file_name)
	{
		if (*(file_name++) == '/')
		{
			error = 1;
			print_error("-bash: ", file->filename, ": Is a directory\n");
			break;
		}
	}
	if (!error && *file->filename == '\"')
	{
		error = 1;
		print_error("-bash: : No such file or directory\n", NULL, NULL);
	}
	else if (!error && *file->filename == '$')
	{
		error = 1;
		print_error("-bash: ", file->filename, ": ambiguous redirect\n");
	}
	if (!error)
		return (error);
	file->fd = Stderr;
	*file_output = file->fd;
	core.exec_output = error;
	return (error);
}
