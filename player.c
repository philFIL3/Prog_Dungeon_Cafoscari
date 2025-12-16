//struttura del giocatore(Hp, coins, armi ecc)
//funzioni che modificano le statistiche(cure, danni ecc)

#include <stdio.h>
#include "player.h"

int player_alive(struct player*p){
    if (p-> HP > 0)
    return 1;
    else return 0;
}