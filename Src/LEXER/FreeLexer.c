#include "../../Include/minishell.h"

int		skip_heradoc(t_lexlist **lexer, t_lexlist *stop_list, int *flag)
{
	if (stop_list == *lexer)
		*flag |= 1;
	if ((*lexer)->type == SIGN_DOUBLE_LESS && !*flag)
	{
		if ((*lexer)->next && (*lexer)->next != stop_list)
			*lexer = (*lexer)->next;
		return (1);
	}
	return (0);
}

void	free_lexer_without_heradoc(t_lexlist *stop_list)
{
	t_lexlist	*lexer;
	t_lexlist	*temp_lexer;
	int			flag;

	lexer = core.lex_table;
	temp_lexer = core.lex_table;
	flag = 0;
	while (lexer)
	{
		if (skip_heradoc(&lexer, stop_list, &flag))
		{
			temp_lexer = lexer;
			lexer = lexer->next;
			continue;
		}
		if (lexer == core.lex_table)
			core.lex_table = core.lex_table->next;
		temp_lexer->next = lexer->next;
		free(lexer->content);
		free(lexer);
		lexer = temp_lexer->next;
	}
}


void	free_lexer()
{
	t_lexlist	*lexer;
	t_lexlist	*temp_lexer;

	lexer = core.lex_table;
	while (lexer)
	{
		temp_lexer = lexer;
		lexer = lexer->next;
		if (temp_lexer->content)
			free(temp_lexer->content);
		free(temp_lexer);
	}
	core.lex_table = NULL;
}
