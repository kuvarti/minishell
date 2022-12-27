#include "../../Include/minishell.h"

void	change_title()
{
	char	cwd[256];

	if (core.title.full_title)
		free(core.title.full_title);
	core.title.full_title = NULL;
	own_strjoin(&core.title.full_title, core.title.head);
	own_strjoin(&core.title.full_title, (char *)getcwd(cwd, 256));
	own_strjoin(&core.title.full_title, "$ ");
}

/*
	burada her dongunun basinda yazilacak prompt olusturulur env'den expand edilerek yapilir.
*/
void	set_title()
{
	char	cwd[256];

	core.title.head = NULL;
	core.title.full_title = NULL;
	expand_envs(&core.title.head, "LOGNAME");
	str_addchar(&core.title.head, '@');
	expand_envs(&core.title.head, "NAME");
	str_addchar(&core.title.head, ':');
	own_strjoin(&core.title.full_title, core.title.head);
	own_strjoin(&core.title.full_title, (char *)getcwd(cwd, 256));
	own_strjoin(&core.title.full_title, "$ ");
}

