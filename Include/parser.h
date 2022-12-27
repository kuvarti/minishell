#ifndef PARSER_H
#define PARSER_H

#include <unistd.h>
#include "lexer.h"

#define Stdin 0
#define Stdout 1
#define Stderr 2

#define NO_ERR 0
#define NO_FILE 1
#define EMPTY_FILE 2
#define NO_ACCESS 3
#define ARG_META 4

typedef struct s_filelist
{
	char				*metachar;
	char				*filename;
	int					fd;
	struct s_filelist	*next;
} t_filelist;

typedef struct s_cmdlist
{
	int					infile;
	int					outfile;
	int					pid;
	char				*cmd;
	char				**path;
	t_filelist			*files;
	struct s_cmdlist	*next;
} t_cmdlist;

void		parser();

void		create_cmdtable(t_lexlist *lex_table);
void		create_cmdtable_nodes(int	count);
void		fill_cmdtable_node(t_cmdlist *node);

void		fill_cmdtable();
void		fill_cmdnode(t_cmdlist *node, t_lexlist **lex_list);

char		**create_path(t_lexlist *lex_list);

int			create_new_filelist(t_cmdlist *node, t_lexlist **lex_list);
t_filelist	*add_filelist(t_filelist **file_list, char * filename, char *meta);

void		create_files(t_cmdlist *node);

void		create_outfile (t_cmdlist *node, t_filelist *file);

void		create_infile (t_cmdlist *node, t_filelist *file);

void		run_heradocs(t_cmdlist *node);
void		read_heradoc(char *eof);
char		*get_heradoc_values(char *eof);
void		open_heradoc_file(char	*create_mode);
void		close_heradoc_file();

int			raise_file_error(t_filelist *file, int *file_output);

void		free_parser();
void		free_filelist(t_filelist *files);

void		print_parser();
#endif
