/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FreeLexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 02:29:34 by aozsayar          #+#    #+#             */
/*   Updated: 2022/12/28 02:29:34 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	skip_heradoc(t_lexlist **lexer, t_lexlist *stop_list, int *flag)
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

	lexer = g_core.lex_table;
	temp_lexer = g_core.lex_table;
	flag = 0;
	while (lexer)
	{
		if (skip_heradoc(&lexer, stop_list, &flag))
		{
			temp_lexer = lexer;
			lexer = lexer->next;
			continue ;
		}
		if (lexer == g_core.lex_table)
			g_core.lex_table = g_core.lex_table->next;
		temp_lexer->next = lexer->next;
		free(lexer->content);
		free(lexer);
		lexer = temp_lexer->next;
	}
}

void	free_lexer(void)
{
	t_lexlist	*lexer;
	t_lexlist	*temp_lexer;

	lexer = g_core.lex_table;
	while (lexer)
	{
		temp_lexer = lexer;
		lexer = lexer->next;
		if (temp_lexer->content)
			free(temp_lexer->content);
		free(temp_lexer);
	}
	g_core.lex_table = NULL;
}
