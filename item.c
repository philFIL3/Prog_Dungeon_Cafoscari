//tipologie di items, statistiche ecc 
#include <stdio.h>
#include "item.h"
#include "player.h"

int dado(){
return 1 + rand() % 6;
}

int calcola_attacco(Player p) {
    if (p.spada_eroe) return dado() + 2;
    if (p.spada) return dado() + 1;
    return 0;
}

int applica_difesa(Player p, int danno_nemico) {
    if (p.armatura && danno_nemico > 0) {
        return danno_nemico - 1;
    }
    return danno_nemico;
}

void stampa_inventario(Player p) {
    printf("\n--- STATO EROE ---\n");
    printf("PV: %d/%d | MONETE: %d\n", p.HP,20, p.coins);
    printf("ARMA: %s\n", p.spada_eroe ? "Spada dell'Eroe (+2)" : (p.spada ? "Spada (+1)" : "Pugnale"));
    printf("DIFESA: %s\n", p.armatura ? "Armatura (-1)" : "Nessuna");
    if (p.chiave_castello) printf("OGGETTI: Chiave del Castello\n");
    printf("------------------\n");
}