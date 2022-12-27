#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "lexer.h"
#include "utilits.h"
#include "expander.h"
#include "parser.h"
#include "executer.h"

typedef struct s_core
{
	int			exec_output;
	int			old_exec_output;
	int			heradoc_fd;
	char		*cmd;
	char		**metachars;
	t_env		*env_table;
	t_lexlist	*lex_table;
	t_cmdlist	*cmd_table;
	t_title		title;
} t_core;

t_core	core;

void	init_core(char **env);
void	free_for_loop();
void	free_core();
void	update_history(char *cmd);

#endif

