#include "../../Include/minishell.h"

void	control_null_content()
{
	t_lexlist	*lex_list;
	t_lexlist	*temp_lex_list;

	lex_list = core.lex_table;
	if (lex_list)
	{
		temp_lex_list = lex_list;
		lex_list = lex_list->next;
		if (!temp_lex_list->content)
		{
			if (core.lex_table == temp_lex_list)
				core.lex_table = core.lex_table->next;
			free(temp_lex_list);
		}
	}
}

void	expander()
{
	t_lexlist *lex_table;

	lex_table = core.lex_table;
	while (lex_table)
	{
		if (lex_table->type == TEXT)
			edit_text(lex_table, 0);
		else if (lex_table->next && lex_table->type != SIGN_PIPE)
		{
			if (lex_table->type != SIGN_DOUBLE_LESS)
				edit_text(lex_table->next, 1);
			lex_table = lex_table->next;
		}
		lex_table = lex_table->next;
	}
	control_null_content();
}
