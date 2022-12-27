#include "../../Include/minishell.h"

void	run_heradocs(t_cmdlist *node)
{
	t_filelist	*temp_file;

	while (node)
	{
		temp_file = node->files;
		while (temp_file)
		{
			if (temp_file->metachar[1] == DOUBLE_LESS[1])
			{
				close_heradoc_file();
				open_heradoc_file("WRITE");
				read_heradoc(temp_file->filename);
				temp_file->fd = core.heradoc_fd;
			}
			temp_file = temp_file->next;
		}
		node = node->next;
	}
	if (core.heradoc_fd > Stderr)
	{
		close_heradoc_file();
		open_heradoc_file("READ");
	}
}

void	read_heradoc(char *eof)
{
	char	*heradoc_lines;

	heradoc_lines = get_heradoc_values(eof);
	write(core.heradoc_fd, heradoc_lines, ft_strlen(heradoc_lines));
	free(heradoc_lines);
}

char	*get_heradoc_values(char *eof)
{
	char	*line;
	char	*newline;
	int		is_begin;

	line = 	NULL;
	is_begin = 0;
	while (1)
	{
		newline = readline("> ");
		str_addchar(&core.cmd, '\n');
		own_strjoin(&core.cmd, newline);
		if (str_compare(eof, newline))
		{
			free(newline);
			break;
		}
		else if (is_begin++)
			str_addchar(&line, '\n');
		own_strjoin(&line, newline);
		if (newline)
			free(newline);
	}
	str_addchar(&line, '\n');
	return (line);
}
