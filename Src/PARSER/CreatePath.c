#include "../../Include/minishell.h"

char	**create_path(t_lexlist *lex_list)
{
	int		count;
	char	*meta;
	char	**path;

	count = 0;
	while (lex_list && lex_list->type != SIGN_PIPE)
	{
		meta = compare_metachars(lex_list->content);
		if (!meta || lex_list->type == TEXT)
			count++;
		else
		{
			lex_list = lex_list->next;
			if (lex_list)
				lex_list = lex_list->next;
			continue;
		}
		lex_list = lex_list->next;
	}
	if (!count)
		return (NULL);
	path = (char **)malloc(sizeof(char *) * (count + 1));
	path[count] = NULL;
	return (path);
}
