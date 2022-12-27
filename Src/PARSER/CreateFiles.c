#include "../../Include/minishell.h"

void	create_files(t_cmdlist *node)
{
	t_filelist	*temp_file;

	if (!node)
		return;
	run_heradocs(node);
	if (core.exec_output)
		return ;
	while (node)
	{
		temp_file = node->files;
		while (temp_file)
		{
			if (*temp_file->metachar == *SINGLE_GREAT)
				create_outfile(node, temp_file);
			else
				create_infile(node, temp_file);
			if (temp_file->fd == Stderr)
			{
				core.exec_output = 127;
				break;
			}
			temp_file = temp_file->next;
		}
		node = node->next;
	}
}
