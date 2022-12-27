#ifndef LEXER_H
# define LEXER_H

#include <stdio.h>
#include "utilits.h"

typedef struct s_lexlist
{
	char				type;
	char				*content;
	struct s_lexlist	*next;
} t_lexlist;

size_t		trim_spaces(char **cmd_line);
t_lexlist	*add_newnode(t_lexlist **lex_table);

size_t		get_cmdlen(char *cmd_line);
size_t		get_quotelen(char *cmd_line);

void		classify(t_lexlist *lex_table);

void		lexer();

void		create_lexlist(char *cmdline, t_lexlist **lex_table);
void		parse_cmd(char **cmd_line, t_lexlist *last_node);

int			check_file_error(t_lexlist *lex_list);
int			print_lex_error(t_lexlist *lex_list);
int			pipe_error_check(t_lexlist *lex_list);
void		syntax_check();

void		free_lexer_without_heradoc(t_lexlist *stop_list);
void		free_lexer();

void		print_lexer();

#endif
