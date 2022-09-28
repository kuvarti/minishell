# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>

int main(int argc, char const *argv[])
{
	char	*ptr;

	while (1)
	{
		ptr = readline("Gir :");
		add_history(ptr);
		free(ptr);
	}
	return 0;
}
