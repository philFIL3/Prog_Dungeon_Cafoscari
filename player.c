//struttura del giocatore(Hp, coins, armi ecc)
//funzioni che modificano le statistiche(cure, danni ecc)

#include <stdio.h>
#include "player.h"

int player_alive(Player*p){
    if (p-> HP > 0)
    return 1;
    else return 0;
}

void take_damage(Player* p, int damage) {
    p->HP -= damage;
}

void collect_coins(Player* p, int denaro){
    p->coins += denaro;
}

void adventure(Player* p){
    p->missions_completed++;
}

/*In caso venga scelto l'opzione dei trucchi si potrà selezionare un salvataggio e modificare punti vita del personaggio,
monete del personaggio, e sbloccare la missione finale*/
void esecuzionetrucchi(Player *p, /*dare un parametro degli salvataggi*/){
    printf("Seleziona un salvataggio");
    scanf("%d", /*salvataggi*/ );
    // devi gestirtela tu un po' qua filippo perchè non so come hai fatto i salvataggi perciò non riesco a farlo io
    printf("Inserisci la nuova quantita' dei punti vita");
    scanf ("%d", &(p->HP));
    printf("Inserisci la nuova quantita' delle monete");
    scanf("%d", &(p->coins));
    // carico direttamente la funzione per andare nella missione
}