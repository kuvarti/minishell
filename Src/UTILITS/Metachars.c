#include "../../Include/minishell.h"

/*
	global degiskende ki metachars degiskenine 2 boyutlu bir dizi olusturur ve icerisine teker teker belirlenen metakarakterleri atar.
	metakarakterler sirasiyla ">>", "<<", "<", ">", "|"'dir
*/
void	set_metachars()
{
	char	**meta_list;

	meta_list = (char **)malloc(sizeof(char *) * (METACHAR_NUM + 1));
	core.metachars = meta_list;
	*(meta_list++) = ft_strdup(DOUBLE_GREAT);
	*(meta_list++) = ft_strdup(DOUBLE_LESS);
	*(meta_list++) = ft_strdup(SINGLE_LESS);
	*(meta_list++) = ft_strdup(SINGLE_GREAT);
	*(meta_list++) = ft_strdup(PIPE);
	*(meta_list++) = NULL;
}

/*
	gonderilen karakter dizisi ile metakarakterleri kıyaslar eger var ise olan metakarakteri return eder.
*/
char	*compare_metachars(char *cmd_line)
{
	char	**meta_chars;

	if (!cmd_line)
		return (NULL);
	meta_chars = core.metachars;
	while (meta_chars && *meta_chars)
	{
		if ((*cmd_line == **meta_chars && !*(*meta_chars + 1))
		|| (*cmd_line == **meta_chars && *(*meta_chars + 1) == *(cmd_line + 1)))
			return (*meta_chars);
		meta_chars++;
	}
	return (NULL);
}
