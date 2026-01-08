//ogni nodo un salvataggio, lista concatenata

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "player.h"


//creaiamo la lista


typedef struct SaveNode{
    
    Player data; //struttura del player come dato
    struct SaveNode *next; //puntatore per il nuovo salvataggio

}SaveNode;
typedef struct SaveNode saveNode;

//metodo per creare il primo salvataggio
saveNode* createSave(Player player){  //creo il primo salvataggio, HEAD, il primo nodo

    saveNode* head = malloc(sizeof(saveNode)); //allocchiamo la grandezza del nodo
    if (head == NULL) return NULL;
    head->data = player;
    head->next = NULL;
    return head;

}
//metodo per inserire un nuovo salvataggio
saveNode* insertSave(saveNode* head,Player player){
    saveNode *newNode = malloc(sizeof(saveNode));
    newNode-> data = player; // copiamo la nuova struct player
    newNode->next = head;
    head = newNode; //nuovo salvataggio
    return newNode;
}
//metodo per stampare i salvataggi
void printSave(saveNode* head) {
    int i = 1;
while (head!= NULL) //controlliamo se il nodo e' nullo
{
    printf("%d) %d HP, %d coins, %d items, %d missions completed\n"  ,
    i,
    head->data.HP,
    head->data.coins,
    head->data.items,
    head->data.missions_completed);
    head = head->next;
    i++;

        }; 

    };
// per eliminare un nodo da una lista dobbiamo giocare un po con i puntatori, in particolar modo con il nodo del nodo precedente
//sorge il problema di quando dobbiamo eliminare il nodo con puntatore head, cioe il primo nodo.
//abbiamo quindi tre casi:
/*1. la lista e' vuota
  2. si elimina la testa
  3. non si elimina la testa ma un next.
PER CANCELLARE UN NODO SI CAMBIANO SOLO I PUNTATORI, IN SEGUITO IL NODO VERRA' POI ELIMINATO, NON SERVE SVUOTARNE DAI DATI
*/
saveNode* deleteSave(saveNode* head, int i){ 
   if(head == NULL){
    return NULL; //non c'e la head percio non c'e' il salvataggio

   } else if(i == 0){// itero con i uguale a 0 per poter eliminare la testa
   SaveNode*temp = head; //il nodo da eliminare
    head = head->next; //nuova head, si sposta la head al puntatore next
    free(temp);  
    return head;
   }

   saveNode* current = head; //eliminamo un nodo intero che non sia la testa
   for (i = 0; i <i -1 && current->next != NULL; i++){ //controlliamo con un ciclo for se i va bene
    current = current -> next; // il current va al puntatore
   } 
   if (current->next != NULL) { //se il puntatore dopo il current non e' nullo
    saveNode*temp = current->next; //il puntatore va al next
    current->next = temp->next; //il puntatore temp va al next
    free(temp); //elimino il nodo temp
   } 
   }
  //NEL MAIN SI DOVRA' USARLA QUINDI CON head = deleteSave(head, 0); // cancella la testa
//head = deleteSave(head, 2); // cancella il terzo nodo
//PERCIO SI DOVRA CHIEDERE CHE SALVATAGGIO ELIMINARE AL PLAYER


//IL LOAD AL CONTRARIO CARICA I DATI DEL NODO

saveNode* loadSave(Player player, saveNode*head, int i){
}


//load save sono le prossime funzioni da implementare

