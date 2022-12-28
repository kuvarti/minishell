/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PipeErrorCheck.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 02:34:15 by aozsayar          #+#    #+#             */
/*   Updated: 2022/12/28 02:34:15 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	control_valid_arg(char *ptr)
{
	char	*str;

	if (!ptr)
		return (0);
	str = ptr;
	trim_spaces(&str);
	if (!*str)
		return (0);
	return (1);
}

int	get_unclosed_pipe_arg(t_lexlist *lex_list)
{
	char	*ptr;

	while (1)
	{
		ptr = readline("> ");
		if (!control_valid_arg(ptr))
			continue ;
		create_lexlist(ptr, &lex_list);
		classify(lex_list);
		str_addchar(&g_core.cmd, ' ');
		own_strjoin(&g_core.cmd, ptr);
		free(ptr);
		if (str_compare(lex_list->next->content, PIPE))
			return (-1);
		break ;
	}
	return (1);
}

int	pipe_error_check(t_lexlist *lex_list)
{
	if (lex_list->next && lex_list->next->type == SIGN_PIPE)
		return (print_lex_error(lex_list));
	else if (!lex_list->next)
		return (get_unclosed_pipe_arg(lex_list));
	return (1);
}
