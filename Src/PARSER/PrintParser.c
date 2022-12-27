#include "../../Include/minishell.h"

void	print_parser()
{
	int			node_count;
	int			index;
	t_cmdlist	*temp_cmdlist;
	t_filelist	*temp_filelist;

	node_count = 1;
	temp_cmdlist = core.cmd_table;
	while (temp_cmdlist)
	{
		index = 0;
		printf("------------NODE %d------------\n", node_count++);
		printf("PATH: ");
		while (temp_cmdlist->path && temp_cmdlist->path[index])
			printf("%s; ", (temp_cmdlist->path[index++]));

		printf("\nCMD: %s\n", temp_cmdlist->cmd);
		printf("infile: %d\n", temp_cmdlist->infile);
		printf("outfile: %d\n", temp_cmdlist->outfile);
		printf("pid: %d\n", temp_cmdlist->pid);
		printf("~files~\n");
		temp_filelist = temp_cmdlist->files;
		while (temp_filelist)
		{
			printf("{fd: %d, ridrect : %s, filename : %s} ", temp_filelist->fd, temp_filelist->metachar, temp_filelist->filename);
			temp_filelist = temp_filelist->next;
		}
		printf("\n\n");
		temp_cmdlist = temp_cmdlist->next;
	}
}
