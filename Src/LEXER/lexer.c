#include "../../Include/minishell.h"


void	syntax_check();
/*
	Lexer 4 asamali prjenin ilk asamasidir. Burada amac girilen karisik komutlari sozcuk yapilarina ayirmaktir.
	orn komut: <a.txt cat| ls| wc -l | echo "ahmet $HOME''"selam
	lexer calistiktan sonra bagil liste deki contentlerin ciktisi soyle olmalidir:
	<, a.txt, cat, |, ls, |, wc, -l, |, echo, "ahmet $HOME''"selam'$PATH'
*/
void	lexer()
{
	core.lex_table = NULL;
	create_lexlist(core.cmd, &(core.lex_table));
	classify(core.lex_table);
	syntax_check();
}
