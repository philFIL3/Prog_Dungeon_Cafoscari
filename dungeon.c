#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "player.h"
#include "menu.h"
#include <string.h>

// MANCA DA IMPLEMENTARE IL FATTO COSA FARE CHE QUANDO UN EROE COMPLETA UNA STANZA, NE ESCE VINCITORE DI AVERE UN CONTATORE PER LE STANZE, E MANCA ANCHE IL FATTO DI
// FORZARE LE STANZE IN CASO NON ESCANO QUELLE PER LE MISSIONI CHE SERVONO 
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

bool vincitore_palude_magione(Player* p, stanza nemici){        // ho creato una funzione sia per la palude putrescente sia per la magione infestata,
    int verifica = 0;                                           // essendo molto simili e si possono gestire praticamente nello stesso modo
    if(nemici.colpofatale == 0){       // faccio prima un controllo se è una trappola
        printf("L'eroe è entrato nella stanza %s ed è caduto in una trappola!\n\n", nemici.nome);
        if(nemici.danno == 0){
        nemici.danno = dado();
        printf("Viene lanciato un dado per stabilire l'attacco della trappola\n\n");
        printf("Il risultato: %d\n\n", nemici.danno);
        p->HP -= nemici.danno;         // essendo una trappola l'eroe non guadagna monete, subisce solamente il danno
    }
        if(p->HP <= 0){
        printf("Sei stato sconfitto! :( \n\n");
        return false;
        }
        printf("La trappola infligge %d danni all'eroe. L'eroe rimane con %d punti vita\n\n", nemici.danno, p->HP);
    }else{ 
        printf("L'eroe incontra un/uno %s e inizia il combattimento\n\n", nemici.nome);
    while (verifica == 0){
        printf("Viene lanciato un dado per stabilire l'attacco dell'eroe\n\n");
        int tiro = dado();   // lancio il dado 
        printf("Il risultato: %d.\n\n", tiro);
    if (tiro > nemici.colpofatale){ // controllo se riesco a battere il nemico
        p->coins += nemici.monete;  // aumento le monete
        verifica = 1;               // pongo verifica = 1 così posso uscire dal ciclo while
        printf("Il/lo %s viene sconfitto (Attacco=%d > Colpo fatale=%d). L'eroe rimane con %d punti vita, e riceve %d monete.\n\n",nemici.nome, tiro, nemici.colpofatale, p->HP, nemici.monete);
    }else{    
        printf("Attacco non sufficiente per sconfiggere il/lo %s (Attacco=%d < Colpo fatale=%d)\n\n", nemici.nome, tiro, nemici.colpofatale);
        p->HP -= nemici.danno;
       
        if(p->HP <= 0){     // controllo se i punti vita sono stati azzerati
            printf("Sei stato sconfitto! :( \n\n");
            return false;
        }
         printf("Il/lo %s infligge %d danni all'eroe. L'eroe rimane con %d punti vita. \n\n", nemici.nome, nemici.danno, p->HP );
    }
}   // nel caso di aver sconfitto il demone custode della magione infestata bisogna ottenere anche
    // la chiave del Castello del signore oscuro quindi facciamo un if di controllo con magari visto 
    // che siamo in questo caso l'unica stanza che ha 10 monete è demone custode possiamo appunto mettere 
    // un if di controllo con le monete, se sono 10, otteniamo la chiave del castello del signore oscuro perchè se 
    // siamo arrivati fino a questa riga sicuramente lo abbiamo sconfitto
    } 
    return true;  
}

// creo il primo generatore di stanze della palude putrescente
void paludeputrescente(Player *p){
    int tiro = dado();
    stanza stanza_appoggio;    // creo una struct di appoggio per tutte le stanze in modo che sopravviva anche all'esterno degli if
    stanza_appoggio.danno = 0;
    stanza_appoggio.monete = 0;
    stanza_appoggio.colpofatale = 0;
   
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
if (vincitore_palude_magione(p, stanza_appoggio)){ // Mi sto chiedendo se il giocatore è riuscito a sopravvivere al combattimento contro il nemico
   // se ha vinto si torna al menù di missione
}else{
    menuprincipale(); // se la vita del giocatore è stato azzerata si torna al menù iniziale
}
}


// creo il generatore delle stanze di Magione Infestata

void magione_infestata(Player *p){
    int tiro = dado();
    stanza stanza_appoggio;
    stanza_appoggio.danno = 0;
    stanza_appoggio.monete = 0;
    stanza_appoggio.colpofatale = 0;  
if (tiro == 1) {
    stanza_appoggio.nome = "Botola buia";
    stanza_appoggio.colpofatale = 0;
    stanza_appoggio.danno = 3;
    stanza_appoggio.monete = 0;
}
else if (tiro == 2) {
    stanza_appoggio.nome = "Pipistrello";
    stanza_appoggio.colpofatale = 2;
    stanza_appoggio.danno = 2;
    stanza_appoggio.monete = 1;
}
else if (tiro == 3) {
    stanza_appoggio.nome = "Zombie";
    stanza_appoggio.colpofatale = 3;
    stanza_appoggio.danno = 2;
    stanza_appoggio.monete = 2;
}
else if (tiro == 4) {
    stanza_appoggio.nome = "Fantasma";
    stanza_appoggio.colpofatale = 5;
    stanza_appoggio.danno = 2;
    stanza_appoggio.monete = 4;
}
else if (tiro == 5) {
    stanza_appoggio.nome = "Vampiro Superiore";
    stanza_appoggio.colpofatale = 4;
    stanza_appoggio.danno = 4;
    stanza_appoggio.monete = 7;
}
else {
    stanza_appoggio.nome = "Demone Custode";
    stanza_appoggio.colpofatale = 4;
    stanza_appoggio.danno = 6;
    stanza_appoggio.monete = 10;
}
if (vincitore_palude_magione(p, stanza_appoggio)){
    // devo tornare al menù di missione se vince
}else{
    menuprincipale();
}
}


// Grotta di Cristallo


int testaocroce(){
    return rand() % 2;
}

int padovansequenze(int n){     // funzione ricorsiva della sequenza di Padovan
    if(n <= 2) return 1;
    return padovansequenze(n-2) + padovansequenze(n-3);
}

bool verificanumerogenerato(int x){     // verifico se il numero generato fa parte della sequenza di Padovan oppure no
    int verifica = 0;
    for(int i = 0; verifica < x; i++){  // faccio un ciclo for che parte da 0 e va fino a al numero generato casualmente 
        verifica = padovansequenze(i);  // metto ogni risultato della funzione padovansequenze nella variabile verifica, quindi nel caso di i = 0 avrò in verifica 1
        if(verifica == x) return true;  // qua faccio il vero controllo se il numero generato fa veramente parte della sequenza
    }
    return false;
}

void danno_opzionale(Player *p){    // creo funzione che mi dice se l'utente è riuscito ad azzeccare il numero se fa parte della sequenza padovan oppure no
    char opzione[10];   // ho messo la possibilità di scrivere fino a 9 caratteri perchè magari l'utente sbaglia a scrive qualcosa + 1 ovviamente per il carattere \0
    int verifica = 0;   // mi serve soltanto come variabile per controllare se l'utente scriva Si o no
    printf("Hai ancora una possibilità per non ricevere danno!\n"
            "Devi riconoscere se un numero intero, che è stato generato casualmente tra 1 e 500,\n"
            "appartiene o meno alla sequenza di Padovan\n\n");
    int num_generato = 1 + rand() % 500;           // generatore di numeri casuali da 1 a 500
    int contenuto = verificanumerogenerato(num_generato);
    while(verifica == 0){
    printf("Il numero generato casualmenente è %d. Riconosci faccia parte della sequenza citata prima? [Si/No]: ", num_generato);
    scanf("%s", opzione);
    if(strcmp(opzione, "Si") == 0 || strcmp(opzione, "No") == 0){    // faccio un controllo che l'utente abbia veramente scritto "Si" oppure "No"
        verifica = 1;
        if(!strcmp(opzione, "Si")){         // nel caso l'utente inserisca Si 
            if(contenuto){                  // qua controllo se il numero generato fa parte o no della sequenza
                printf("Complimenti, risposta corretta! Il danno è pari a 0");
            }else{
                printf("Risposta sbagliata! Al tuo eroe gli verranno tolti 10 punti vita.");
                p->HP -= 10;
            }
        }else if(!strcmp(opzione, "No")){   // nel caso l'utente inserisca no
             if(!contenuto){
                printf("Complimenti, risposta corretta! Il danno è pari a 0");
            }else{
                printf("Risposta sbagliata! Al tuo eroe gli verranno tolti 10 punti vita.");
                p->HP -= 10;
            }
        }
    }else{
        printf("Devi scrivere esattamente 'Si' oppure 'No'. Ricominciamo nuovamente.");
    }
    }
}

bool vincitore_grotta(Player *p, stanza nemici, int tiro){
    if(tiro == 1){  // controllo se l'eroe è entrato in una stanza vuota
        printf("L'eroe è entrato in una stanza vuota. Tornerai nel menu di missione\n\n");
        return true;
    }else if(tiro == 2 || tiro == 3 || tiro == 4 || tiro == 5){   // controllo se l'eroe cadrà in trappola
        printf("L'eroe è entrato nella stanza %s ed è caduto in una trappola!\n\n", nemici.nome);
        if(tiro == 2){
            p->HP -= nemici.danno;
            printf("La trappola infligge %d danni all'eroe. L'eroe rimane con %d punti vita.\n\n", nemici.danno, p->HP);
        }else if(tiro == 3){
            p->coins -= nemici.monete;
            printf("La trappola fa perdere all'eroe %d monete\n\n", nemici.monete);
        }else if(tiro == 4){
            printf("Viene lanciato una moneta, se esce testa ottieni %d monete, altrimenti subisci %d danno.\n\n", nemici.monete, nemici.danno);
            if(testaocroce()){
                printf("E' uscita testa! Complimenti l'eroe ha ottenuto le monete.\n\n");
                p->coins += nemici.monete;
            }else{
                printf("Sfortunatamente è uscito croce. L'eroe dovrà subire i danni");
                p->HP -= nemici.danno;
            }
        }else if(tiro == 5){
            printf("Viene lanciato un dado per stabilire il danno della trappola");
            int danno = dado();
            printf("Il risultato : %d", danno);
            p->HP -= danno;
            printf("La trappola infligge %d danni all'eroe. L'eroe rimane con %d punti vita.\n\n", danno, p->HP);
        }
          if(p->HP <= 0){
            printf("Essendo che i punti vita dell'eroe sono 0 o negativi, Sei Stato Sconfitto! :( \n\n");
            return false;
        }
    }else{
        printf("L'eroe incontra un drago antico e inizia il combattimento\n\n");
        int verifica = 0;
        while(verifica == 0){
        printf("Viene lanciato un dado per stabilire l'attacco dell'eroe\n\n");
        int attacco = dado();
        printf("Il risultato: %d\n\n", attacco);
        if(attacco>nemici.colpofatale){
            printf("Il drago antico viene sconfitto (Attacco = %d > Colpo fatale = %d)."
                    "L'eroe rimane con %d punti vita, e oltre a ricevere 12 monete," 
                    "riceve anche la Spada dell'eroe.\n\n", attacco, nemici.colpofatale, p->HP);
            p->coins += nemici.monete;
            // bisogna scrivere qualcosa in modo che ottenga anche la spada dell'eroe IMPORTANTE!!
            verifica = 1;
        }else{
            printf("Attacco non sufficiente per sconfiggere il drago antico (Attacco = %d < Colpo Fatale = 2)", attacco);
            danno_opzionale(p);
            if(p->HP <= 0){
            printf("Essendo che i punti vita dell'eroe sono 0 o negativi, Sei Stato Sconfitto! :( \n\n");
            return false;
        }
    }
    }
}
    return true;
}

// creo il generatore di stanze di Grotta di Cristallo

void grottadicristallo(Player* p){
    int tiro = dado();
    stanza stanza_appoggio;
    stanza_appoggio.danno = 0;
    stanza_appoggio.monete = 0;
    stanza_appoggio.colpofatale = 0;
    if (tiro == 1) {
    stanza_appoggio.nome = "Stanza Vuota";
}
else if (tiro == 2) {
    stanza_appoggio.nome = "Cristalli Cadenti";
    stanza_appoggio.danno = 2;
}
else if (tiro == 3) {
    stanza_appoggio.nome = "Ponte Pericolante";
    stanza_appoggio.monete = 3;
}
else if (tiro == 4) {
    stanza_appoggio.nome = "Forziere Misterioso";
    stanza_appoggio.danno = 2;
    stanza_appoggio.monete = 10;
}
else if (tiro == 5) {
    stanza_appoggio.nome = "Rupe scoscesa";
}
else {
    stanza_appoggio.nome = "Drago Antico";
    stanza_appoggio.colpofatale = 5;
    stanza_appoggio.monete = 12;
    // bisogna mettere anche che ottiene la spada dell'eroe però non c'è ancora il codice
}

if (vincitore_grotta(p, stanza_appoggio, tiro)){ // Mi sto chiedendo se il giocatore è riuscito a sopravvivere al combattimento contro il nemico
   // se ha vinto si torna al menù di missione
}else{
    menuprincipale(); // se la vita del giocatore è stato azzerata si torna al menù iniziale
}
}

