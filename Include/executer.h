#ifndef EXECUTER_H
# define EXECUTER_H

#include "parser.h"
#include <unistd.h>
#include <sys/wait.h>

#define ECHO 1
#define	CD 2
#define PWD 3
#define EXPORT 4
#define UNSET 5
#define ENV 6
#define EXIT 7

char	*get_cmd(char *cmd);
void	run_command(t_cmdlist *cmd_node, int *fd, int fd_index);

void	executer();

void	run_echo(t_cmdlist *cmd_node);

void	run_cd(t_cmdlist *cmd_node);
int		change_dir(char *path);
void	cd_single_arg();
void	cd_double_arg(t_cmdlist *cmd_node);
void	handle_oldpwd(char *oldpwd, int is_pwdaccess);

void	run_pwd(t_cmdlist *cmd_node);

int		change_env(char *envname, char *arg, int is_equal);
void	single_export_arg(t_cmdlist *cmd_node);
void	double_export_arg(char *env_cmd);
void	run_export(t_cmdlist *cmd_node);
int		env_arg_control(char *env);

void	delete_env(char *name);
void	run_unset(t_cmdlist *cmd_node);

void	run_env(t_cmdlist *cmd_node);

void	run_exit();

char	**get_env_cpy();
void	run_execve(t_cmdlist *cmd_node, int *fd, int fd_index);

int		cmd_table_len(t_cmdlist *cmd_list);
int		*create_pipe();
void	clear_pipe(int *fd);

void	create_dup(t_cmdlist *cmd_list, int *fd, int fd_index);

void	run_single_command(t_cmdlist *cmd_list, int *fd);
void	run_multiple_command(t_cmdlist *cmd_list);

void	run_process(t_cmdlist *cmd_list, int *fd, int fd_index);
void	wait_all();

int		is_builtin(char *cmd);
void	run_builtin(t_cmdlist *cmd_node, int builtin, int *fd, int fd_index);

#endif
