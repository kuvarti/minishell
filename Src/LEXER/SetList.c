#include "../../Include/minishell.h"

/*
	Gelen komutu bosluk gordukce adres uzerinde arttirir boylece geldigi fonksiyonda da artmis olur.
*/
size_t	trim_spaces(char **cmd_line)
{
	size_t	count;

	count = 0;
	if (!*cmd_line)
		return (count);
	while (**cmd_line == 32)
	{
		count++;
		(*cmd_line)++;
	}
	return (count);
}
/*
	gonderilen bagli liste adresinin icini kontrol eder eger ici bos ise icine heap bellekte yeni bir tane node acar.
	Eger ici bos degil ise listenin sonuna gider ve sonuna yeni bir tane node yapisi olusturur. Ardindan node'un icerisinde ki
	tum degerleri NULL'lar ve bu olusturulan node'u return eder.
*/
t_lexlist	*add_newnode(t_lexlist **cmd_table)
{
	t_lexlist	*new_node;

	if (!*cmd_table)
	{
		new_node = (t_lexlist *)malloc(sizeof(t_lexlist));
		new_node->content = NULL;
		new_node->type = 0;
		new_node->next = NULL;
		*cmd_table = new_node;
		return (*cmd_table);
	}
	new_node = *cmd_table;
	while (new_node->next)
		new_node = new_node->next;
	new_node->next = (t_lexlist *)malloc(sizeof(t_lexlist));
	new_node->next->content = NULL;
	new_node->next->type = 0;
	new_node->next->next = NULL;
	return (new_node->next);
}
