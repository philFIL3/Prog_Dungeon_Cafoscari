//struttura del giocatore(Hp, coins, armi ecc)
//funzioni che modificano le statistiche(cure, danni ecc)

#include <stdio.h>
#include "player.h"
#include "save.h"

int player_alive(Player*p){
    if (p-> HP > 0)
    return 1;
    else return 0;
}

void take_damage(Player* p, int damage) {
    if (p->armatura)
    {
        damage--;
    }
    if (damage<0)
    {
        damage = 0;
    }
    
    p->HP -= damage;
}

void collect_coins(Player* p, int denaro){
    p->coins += denaro;
}

void adventure(Player* p){
    p->missione_completata++;
}


/*In caso venga scelto l'opzione dei trucchi si potrà selezionare un salvataggio e modificare punti vita del personaggio,
monete del personaggio, e sbloccare la missione finale*/
void esecuzionetrucchi(Player *p, saveNode* head){
    int scelta;
    printf("Seleziona un salvataggio");
    scanf("%d", &scelta );

    if (!loadSave(head,scelta-1, p)){
        printf("salvataggio non valido\n");
        return; 
    }
    printf("Inserisci la nuova quantita' dei punti vita");
    scanf ("%d", &(p->HP));
    printf("Inserisci la nuova quantita' delle monete");
    scanf("%d", &(p->coins));

    p->missione_completata = 3;
    p->stato_missioni[0] = 1;
    p->stato_missioni[1] = 1;
    p->stato_missioni[2] = 1;
    updateSave(head, *p, scelta-1);

    printf("trucchi funzionanti correttamente\n");

}