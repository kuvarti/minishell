#include "../../Include/minishell.h"

void	fill_cmdnode(t_cmdlist *node, t_lexlist **lex_list)
{
	char	**path_holder;
	int		is_begin;

	node->path = create_path(*lex_list);
	path_holder = node->path;
	is_begin = 0;
	while (*lex_list && (*lex_list)->type != SIGN_PIPE)
	{
		if (create_new_filelist(node, lex_list))
			continue ;
		if (!(is_begin++))
			expand_from_env(&((*lex_list)->content));
		*(path_holder++) = (*lex_list)->content;
		*lex_list = (*lex_list)->next;
	}
	if (node->path)
		node->cmd = node->path[0];
}

void	fill_cmdtable()
{
	t_cmdlist	*temp_cmdtable;
	t_lexlist	*temp_lexlist;

	if (!core.cmd_table)
		return ;
	temp_cmdtable = core.cmd_table;
	temp_lexlist = core.lex_table;
	while (temp_cmdtable)
	{
		fill_cmdnode(temp_cmdtable, &temp_lexlist);
		if (temp_lexlist && *temp_lexlist->content == *PIPE)
			temp_lexlist = temp_lexlist->next;
		temp_cmdtable = temp_cmdtable->next;
	}
}
