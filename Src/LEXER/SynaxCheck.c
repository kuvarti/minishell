#include "../../Include/minishell.h"

int		print_lex_error(t_lexlist *lex_list)
{
	print_error("-bash: syntax error near unexpected token '", lex_list->content, "'\n");
	core.exec_output = 2;
	free_lexer_without_heradoc(lex_list);
	return (0);
}

int		check_file_error(t_lexlist *lex_list)
{
	if (!lex_list->next || (lex_list->next && lex_list->next->type != TEXT))
	{
		if (lex_list->next)
			return (print_lex_error(lex_list->next));
		else
		{
			print_error("-bash: syntax error near unexpected token '", "newline", "'\n");
			core.exec_output = 2;
			free_lexer_without_heradoc(lex_list);
			return(0);
		}
	}
	return (1);
}

int		pipe_error_check(t_lexlist *lex_list)
{
	char	*ptr;

	if (lex_list->next && lex_list->next->type == SIGN_PIPE)
		return (print_lex_error(lex_list));
	else if (!lex_list->next)
	{
		while (1)
		{
			ptr = readline("> ");
			if (!ptr || !*ptr)
				continue;
			else if (*ptr)
			{
				create_lexlist(ptr, &lex_list);
				classify(lex_list);
			}
			str_addchar(&core.cmd, ' ');
			own_strjoin(&core.cmd, ptr);
			free(ptr);
			if (str_compare(lex_list->next->content, PIPE))
				return (0);
			break;
		}
	}
	return (1);
}

void	syntax_check()
{
	t_lexlist	*lex_list;

	lex_list = core.lex_table;
	while(lex_list)
	{
		if (lex_list == core.lex_table && lex_list->type == SIGN_PIPE)
		{
			print_lex_error(lex_list);
			break;
		}
		else if (lex_list->type != TEXT && lex_list->type != SIGN_PIPE)
		{
			if (!check_file_error(lex_list))
				break;
		}
		else if (lex_list->type == SIGN_PIPE && !pipe_error_check(lex_list))
			continue;
		lex_list = lex_list->next;
	}
}
