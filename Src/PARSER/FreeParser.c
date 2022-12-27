#include "../../Include/minishell.h"

void	free_filelist(t_filelist *files)
{
	t_filelist	*temp_files;

	while (files)
	{
		temp_files = files;
		files = files->next;
		if (temp_files->fd > Stderr && temp_files->fd != core.heradoc_fd)
			close(temp_files->fd);
		free(temp_files);
	}
}

void	free_parser()
{
	t_cmdlist	*parser;
	t_cmdlist	*temp_parser;

	parser = core.cmd_table;
	while (parser)
	{
		temp_parser = parser;
		parser = parser->next;
		free_filelist(temp_parser->files);
		if (temp_parser->path)
			free(temp_parser->path);
		free(temp_parser);
	}
}
