#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "player.h"
#include "menu.h"

// funzione per generare un numero da 1 a 6
int dado(){
return 1 + rand() % 6;
}

// creo la struct con le stanze
typedef struct {
    char *nome;
    int colpofatale;
    int danno;
    int monete;
} stanza;

bool vincitore(Player* p, stanza nemici){
    printf("L'eroe incontra un %s e inizia il combattimento\n\n", nemici.nome);
    int verifica = 0;
    if(nemici.colpofatale == 0){       // faccio prima un controllo se è una trappola
        printf("L'eroe è caduto in una trappola!\n\n");
        p->HP -= nemici.danno;         // essendo una trappola l'eroe non guadagna monete, subisce solamente il danno
        if(p->HP <= 0){
            printf("Sei stato sconfitto! :( ");
            return false;
        }
        printf("La trappola infligge %d danni all'eroe. L'eroe rimane con %d punti vita\n\n", nemici.danno, p->HP);
    }else{ 
    while (verifica == 0){
        printf("Viene lanciato un dado per stabilire l'attacco dell'eroe\n\n");
        int tiro = dado();   // lancio il dado 
        printf("Il risultato: %d.\n\n", tiro);
    if (tiro > nemici.colpofatale){ // controllo se riesco a battere il nemico
        p->coins += nemici.monete; 
        verifica = 1;
        printf("Il/lo %s viene sconfitto (Attacco=%d > Colpo fatale=%d). L'eroe rimane con %d punti vita, e riceve %d monete.\n\n",nemici.nome, tiro, nemici.colpofatale, p->HP, nemici.monete);
    }else{    
        printf("Attacco non sufficiente per sconfiggere il/lo %s (%d < Colpo fatale=%d)\n\n", nemici.nome, tiro, nemici.colpofatale);
        p->HP -= nemici.danno;
       
        if(p->HP <= 0){     // controllo se i punti vita sono stati azzerati
            printf("Sei stato sconfitto! :( \n\n");
            return false;
        }
         printf("Il/lo %s infligge %d danni all'eroe. L'eroe rimane con %d punti vita. \n\n", nemici.nome, nemici.danno, p->HP );
    }
}
    }
    return true;  
}

// creo il primo generatore di stanze della palude putrescente
void paludeputrescente(Player *p){
    int tiro = dado();
    stanza stanza_appoggio;    // creo una struct di appoggio per tutte le stanze in modo che sopravviva anche all'esterno degli if
if (tiro == 1) {
    stanza_appoggio.nome = "Cane Selvaggio";
    stanza_appoggio.colpofatale = 2;
    stanza_appoggio.danno = 1;
    stanza_appoggio.monete = 0;
}
else if (tiro == 2) {
    stanza_appoggio.nome = "Goblin";
    stanza_appoggio.colpofatale = 3;
    stanza_appoggio.danno = 2;
    stanza_appoggio.monete = 2;
}
else if (tiro == 3) {
    stanza_appoggio.nome = "Scheletro";
    stanza_appoggio.colpofatale = 4;
    stanza_appoggio.danno = 2;
    stanza_appoggio.monete = 4;
}
else if (tiro == 4) {
    stanza_appoggio.nome = "Orco";
    stanza_appoggio.colpofatale = 3;
    stanza_appoggio.danno = 4;
    stanza_appoggio.monete = 6;
}
else if (tiro == 5) {
    stanza_appoggio.nome = "Acquitrino Velenoso";
    stanza_appoggio.colpofatale = 0; 
    stanza_appoggio.danno = dado();
    stanza_appoggio.monete = 0;
}
else {
    stanza_appoggio.nome = "Generale Orco";
    stanza_appoggio.danno = 3;
    stanza_appoggio.monete = 12;
    if (/*bisogna fare una funzione esterna o anche dentro l'if per controllare se il giocatore ha la spada dell'eroe oppure no*/){
        stanza_appoggio.colpofatale = 6; // se non ha la spada dell'eroe
    }else{
        stanza_appoggio.colpofatale = 5;
    }
}
if (vincitore(p, stanza_appoggio)){ // Mi sto chiedendo se il giocatore è riuscito a sopravvivere al combattimento contro il nemico
   // se ha vinto si torna al menù di missione
}else{
    menuprincipale(); // se la vita del giocatore è stato azzerata si torna al menù iniziale
}
}

