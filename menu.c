#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "player.h"
#include "save.h"
#include "combat.h"
#include "dungeon.h"
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
 if (p->missione_completata == 3) {
  printf("\nSeleziona una delle opzioni del menu [1-4]: ");
 } else {
  printf("\nSeleziona una delle opzioni del menu [1-3]: ");
 }
  int scelta_missione;
  scanf("%d", &scelta_missione);
 if(scelta_missione == 1){
 if(p->stato_missioni[0] == 0){   //controllo per verificare che non vengano selezionate missioni completate
  if (dungeon_controller(p, PALUDE)) {
  p->stato_missioni[0] = 1; 
  p->missione_completata++; 
  }
 }else{
  printf("\nMissione gia' completata!\n");
 }
 }
 if(scelta_missione == 2){
 if(p->stato_missioni[1] == 0){
  if (dungeon_controller(p, MAGIONE)) {
  p->stato_missioni[1] = 1;
  p->missione_completata++;
 }
 }else{
  printf("\nMissione gia' completata!\n");
 }
 }
 if(scelta_missione == 3){
 if(p->stato_missioni[2] == 0){
  if (dungeon_controller(p, GROTTA)) {
  p->stato_missioni[2] = 1;
  p->missione_completata++;
  }
 }else{
  printf("\nMissione gia' completata!\n");
 }


 }
 if(scelta_missione == 4){
 if(p->missione_completata == 3){
  if(scontro_SignoreOscuro() == 1){ 
  exit(0);
 }
 }else{
  printf("\nNon hai ancora completato tutte le missioni!\n");
 }
 }
}
//missioni selection menu


saveNode* nuova_partita(saveNode* head, Player* currentplayer){
 //creo struttura del nuovo player
  Player nuovo;

  nuovo.coins = 0;
  nuovo.HP = 20;
  nuovo.spada_eroe = 0;
  nuovo.spada = 0;
  nuovo.armatura = 0;
  nuovo.chiave_castello = 0;
  nuovo.missione_completata =0;
  nuovo.stato_missioni[0] = 0;
  nuovo.stato_missioni[1] = 0;
  nuovo.stato_missioni[2] = 0;


  head = insertSave(head, nuovo); // cosi inserisco nella lista la head

  *currentplayer = nuovo; //aggiorno i puntatori del current con il nuovo

  printf("\nNuova partita creata\n\n");
  return head;
}

int carica_partita(saveNode * head, Player *currentplayer){
  if (head == NULL) {
  printf("Non ci sono salvataggi disponibili!\n");
  return -1;
  }
  printf("ecco i salvataggi:\n");
  printSave(head);

  int scelta;
  printf("quale dei salvataggi vorresti caricare?\n");
  scanf("%d", &scelta);
if (loadSave(head, scelta - 1, currentplayer)) { //perche uso indice con base 0
  printf("salvataggio completato\n");
  return scelta - 1;
}
}

saveNode* menuVillaggio(saveNode*head, Player* p, int counter) {
int scelta;
 do {
   printf("------IL VILLAGGIO------\n");
   printf("1. Intraprendi una missione\n");
   printf("2. Riposati\n");
   printf("3. Inventario\n");
   printf("4. Salva la partita\n");
   printf("5. Esci dal menu\n");
  printf("Cosa scegli? ");
  scanf("%d", &scelta);
   switch (scelta)
   {
   case 1:
    seleziona_missione(p);
    break;
    case 2:
    p->HP = 20;
    printf("Ti stanno ritornando le forze, HP ripristinati\n");
    break;
    case 3:
    stampa_inventario(p);
    break;
    case 4:
    updateSave(head,*p, counter);
    break;
    case 5:
    printf("ritorna al menu\n");
   default:
   printf("scelta non valida\n");
    break;
   }
  }
   while (scelta !=5 && p->HP > 0);
   return head;
}
