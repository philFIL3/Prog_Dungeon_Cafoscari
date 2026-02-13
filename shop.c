#include <stdio.h>
#include <stdlib.h>
#include "shop.h"
#include "player.h"

void avvia_negozio(Player *p) {
    int scelta;
    
    printf("\n--- NEGOZIO DI MISSIONE ---\n");
    printf("Monete correnti: %d\n", p->coins);
    printf("1. Pozione (4 Monete) - Cura da 1 a 6 HP\n");
    if (!p->spada_eroe && !p->spada) printf("2. Spada (5 Monete) - +1 Attacco\n");
    if (!p->armatura) printf("3. Armatura (10 Monete) - -1 Danno\n");
    printf("4. Esci\n");
    printf("Scelta: ");
    scanf("%d", &scelta);

    switch(scelta) {
        case 1:
            if (p->coins >= 4) {
                p->coins -= 4;
                int cura = (rand() % 6) + 1;
                p->HP += cura;
                if (p->HP > 20) p->HP = 20;
                printf("Cura: +%d PV!\n", cura);
            } else printf("Monete insufficienti!\n");
            break;
        case 2:
            if (!p->spada && !p->spada_eroe && p->coins >= 5) {
                p->coins -= 5;
                p->spada = 1;
                printf("Hai ottenuto la Spada!\n");
            } else printf("Non disponibile.\n");
            break;
        case 3:
            if (!p->armatura && p->coins >= 10) {
                p->coins -= 10;
                p->armatura = 1;
                printf("Hai ottenuto l'Armatura!\n");
            } else printf("Non disponibile.\n");
            break;
        default:
            printf("Uscita dal negozio.\n");
            break;
    }
}