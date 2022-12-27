#include "../../Include/minishell.h"

void	edit_text(t_lexlist *lex_table, int is_after_meta)
{
	char	*cmd;
	int		flag;
	char	*ptr;

	cmd = lex_table->content;
	ptr = NULL;
	flag = 0;
	while (*cmd)
	{
		if (*cmd == '\'' && (!flag || flag == 1))
			flag = flag ^ 1;
		else if (*cmd == '\"' && (!flag || flag == 2))
			flag = flag ^ 2;
		else if ((!flag || flag == 2) && (*cmd == *DOLLAR || *cmd == *TILDA))
			expand_order(&ptr, &cmd);
		else
			str_addchar(&ptr, *cmd);
		cmd++;
	}
	if (is_after_meta && !ptr)
		return;
	free(lex_table->content);
	lex_table->content = ptr;
}

