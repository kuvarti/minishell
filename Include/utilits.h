#ifndef UTILITS_H
#define UTILITS_H

#include "lexer.h"
#include <fcntl.h>

#define METACHAR_NUM 5
#define SINGLE_GREAT ">"
#define DOUBLE_GREAT ">>"
#define SINGLE_LESS "<"
#define DOUBLE_LESS "<<"
#define PIPE "|"

#define SIGN_SINGLE_GREAT 61
#define SIGN_DOUBLE_GREAT 122
#define SIGN_SINGLE_LESS 59
#define SIGN_DOUBLE_LESS 118
#define SIGN_SINGLE_QUOTE 39
#define SIGN_DOUBLE_QUOTE 34
#define SIGN_PIPE 123
#define TEXT 0

typedef struct s_title
{
	char	*head;
	char	*full_title;
}	t_title;


typedef	struct s_env
{
	char			*env_name;
	char			*content;
	struct s_env	*next;
} t_env;

int		get_numbercount(int number);
char	*ft_itoa(int number);

char	*ft_strdup(char *ptr);

char	*ft_strlcpy(char *dst, char *src, int count);

size_t	ft_strlen(char *ptr);

int		get_array_len(char **array);

int		str_compare(char *str1, char *str2);

t_env	*add_newenv(t_env **env_table, char *env);
void	fill_envs(char **env);
int		get_env_name_count(char *env_arg);
int		update_env(char *env_name, char *new_arg);
char	*get_env_name(char *content);

char	*compare_metachars(char *cmd_line);
void	set_metachars();

void	str_addchar(char **dst, char c);
void	own_strjoin(char **dst, char *src);

void	change_title();
void	set_title();

void	free_metachars();
void	free_envtable();
void	free_title();

void	print_error(char *ptr1, char *ptr2, char *ptr3);

#endif
