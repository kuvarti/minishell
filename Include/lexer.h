/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 05:54:34 by aozsayar          #+#    #+#             */
/*   Updated: 2022/12/28 05:54:34 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "tables.h"
# include "macros.h"

//MAIN
void		lexer(void);

//CREATELEXTABLE
void		create_lexlist(char *cmdline, t_lexlist **lex_table);
void		parse_cmd(char **cmd_line, t_lexlist *last_node);

t_lexlist	*add_new_lex_node(t_lexlist **cmd_table);

size_t		get_quotelen(char *cmd_line);
size_t		get_cmdlen(char *cmd_line);

//CLASSIFY
void		classify(t_lexlist *lex_table);

//SYNTAXCHECK
void		syntax_check(void);
int			syntax_error_check(t_lexlist *lex_list);

int			pipe_error_check(t_lexlist *lex_list);
int			get_unclosed_pipe_arg(t_lexlist *lex_list);
int			control_valid_arg(char *ptr);

int			file_error_check(t_lexlist *lex_list);

//FREELEXER
void		free_lexer(void);
void		free_lexer_without_heradoc(t_lexlist *stop_list);
int			skip_heradoc(t_lexlist **lexer, t_lexlist *stop_list, int *flag);

void		print_lexer(void);

#endif
