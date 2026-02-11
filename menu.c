#include <stdio.h>
#include <stdbool.h>
#include "player.h"
#include "save.h"
//menu iniziale di gioco

// funzione per controllare se viene inserito uno dei caratteri di konami
bool controllokonami(char konami){
  char codice[11]={'w','w','s','s','a','d','a','d','b','a',' '};
  for(int i = 0; i<11 ;i++){
   if (konami == codice[i]) return true;
  }
  return false;
}

char menuprincipale(){
  char scelta;
  printf("Menu Principale:\n\n");
  printf("    1. Nuova partita\n");
  printf("    2. Carica Salvataggio\n\n");
  printf("Seleziona una delle opzioni del menu [1-2]:");
  scanf(" %c", &scelta);
  if ( scelta != '1' && scelta != '2' && !controllokonami(scelta)){

    return menuprincipale();
  }
else {
  return scelta;
    }
  }

char menuprincipaletrucchi(){
  char sceltatrucchi;
  printf("Menu Principale:\n\n");
  printf("    1. Nuova partita\n");
  printf("    2. Carica Salvataggio\n");
  printf("    3. Trucchi\n");
  printf("Seleziona una delle opzioni del menu [1-3]:");
  scanf(" %c", &sceltatrucchi);
  return sceltatrucchi;
}
//menu del Villaggio
//menu missioni
void seleziona_missione(Player *p){
  printf("Menu di selezione missione:\n\n");
 if(p->stato_missioni[0] == 0){
  printf("1. Palude Putrescente\n"); //se la missione è completata(1) non stampa nulla
 }
 if(p->stato_missioni[1] == 0){
  printf("2. Magione Infestata\n");
 }
 if(p->stato_missioni[2] == 0){
  printf("3. Grotta di Cristallo\n");
 }
  if(p->missions_completed == 3){
  printf("4. Castello del Signore Oscuro\n"); //stampa questo solo quando tutte le missioni sono state completate
 }

 printf("\nSeleziona una delle opzioni del menu [1-3]:  ");
 int scelta_missione;
 scanf("%d", &scelta_missione);
 if(scelta_missione == 1){
 if(p->stato_missioni[0] == 0){   //controllo per verificare che non vengano selezionate missioni completate
  //RICHIAMARE FUNZIONE PER INIZIARE LA MISSIONE
 }else{
  printf("\nMissione gia' completata!\n");
 }
 }
 if(scelta_missione == 2){
 if(p->stato_missioni[1] == 0){
  //RICHIAMARE FUNZIONE PER INIZIARE LA MISSIONE
 }else{
  printf("\nMissione gia' completata!\n");
 }
 }
 if(scelta_missione == 3){
 if(p->stato_missioni[2] == 0){
  //RICHIAMARE FUNZIONE PER INIZIARE LA MISSIONE
 }else{
  printf("\nMissione gia' completata!\n");
 }


 }
 if(scelta_missione == 4){
 if(p->missions_completed == 3){
  //RICHIAMARE FUNZIONE PER AFFRONTARE LA MISSIONE FINALE
 }else{
  printf("\nNon hai ancora completato tutte le missioni!\n");
 }
 }
}
//missioni selection menu


saveNode* nuovaParita(saveNode* head, Player* currentplayer){
 //creo struttura del nuovo player
  Player nuovo;

  nuovo.coins = 0;
  nuovo.HP = 20;
  nuovo.missions_completed = 0;
  nuovo.spada_eroe = 0;
  nuovo.chiave_castello = 0;
  nuovo.stato_missioni[3];
 
  head = insertSave(head, nuovo); // cosi inserisco nella lista la head

  *currentplayer = nuovo; //aggiorno i puntatori del current con il nuovo

  printf("nuova partita creata\n");
  return head;
}

void caricaPartita(saveNode * head, Player *currentplayer){
  printf("ecco i salvataggi:\n");
  printSave(head);

  int scelta;
  printf("quale dei salvataggi vorresti caricare?\n");
  scanf("%d", &scelta);
  
  loadSave(currentplayer, head, scelta - 1); //perche uso indice con base 0
  printf("salvataggio completato\n");
}

void menuVillaggio(){}
