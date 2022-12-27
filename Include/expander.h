#ifndef EXPANDER_H
# define EXPANDER_H

#include "lexer.h"


# define SINGLE_QUOTE "'"
# define DOUBLE_QUOTE "\""
# define DOLLAR "$"
# define DOUBLE_DOLLAR "$$"
# define QUSTION_MARK "?"
# define TILDA "~"

//EXPANDER
void	expander();
void	edit_text(t_lexlist *lex_table, int is_after_meta);

void	expand_order(char **dst, char **src);
void	set_envs(char **dst, char **src);
void	expand_envs(char **dst, char *ptr);

char	*create_search_arg(char **envs, char *search_arg_name);
void	control_path(char **dst, char *content);
void	expand_from_env(char **dst);


void	check_dollar(char **dst, char **src);
void	double_dollar(char **dst, char **src);
void	question_mark(char **dst, char **src);
void	single_dollar(char **dst);

void	control_null_content();

void	print_expander();

#endif
