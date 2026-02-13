//ogni nodo un salvataggio, lista concatenata

#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "save.h"




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
    printf("%d) HP: %d, Coins: %d, Chiave del Castello:%d, Spada:%d, Spada dell'Eroe:%d, Armatura:%d, Missioni:%d\n",
    i,
    head->data.HP,
    head->data.coins,
    head->data.chiave_castello,
    head->data.spada,
    head->data.spada_eroe,
    head->data.armatura,
    head->data.missione_completata);
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

//qua ho preso in esame il delete node che c'e' sul libro, stessa logica, solo che "elimino" il nodo non in base al valore ma all'indice che dovra' essere chiesto al player
saveNode* deleteSave(saveNode* head, int i){ 
   if(head == NULL){
    return NULL; //non c'e' la head perciò non c'e' il salvataggio

   } else if(i == 0){// itero con i uguale a 0 per poter eliminare la testa
   SaveNode*temp = head; //il nodo da eliminare
    head = head->next; //nuova head, si sposta la head al puntatore next
    free(temp);  
    return head;
   }

   saveNode* current = head; //eliminamo un nodo intero che non sia la testa
   for (int j = 0; j < i - 1 && current->next != NULL; i++){ //controlliamo con un ciclo for se i va bene
    current = current -> next; // il current va al puntatore
   } 
   if (current->next != NULL) { //se il puntatore dopo il current non e' nullo
    saveNode*temp = current->next; //il puntatore va al next
    current->next = temp->next; //il puntatore temp va al next
    free(temp); //elimino il nodo temp
   } 
   return head;
   }
//IL LOAD AL CONTRARIO CARICA I DATI DEL NODO

int loadSave(saveNode* head, int index, Player* p){
    //se la lista e' vuota
    if(head == NULL || p == NULL )
    return 0;

    saveNode* current = head;

    //scorriamo l'indice 
    for(int i = 0; i< index && current != NULL; i ++){
        current = current->next; //guardiamo al prossimo nodo
    }
    
    //counter non compreso nella lista return 0
    if (current == NULL)
    {
        return 0;
    }
    

    //copiamo i dati 
    *p = current->data;

    return 1; 
}


//con updatesave aggiorniamo i dati di un file gia esistente, non si modificano i puntatori
int updateSave(saveNode*head, Player player, int counter){
    
    //troviamo il salvataggio
    saveNode*current = head;

    for (int i = 0; i< counter && current != NULL; i++)
    {
        current = current -> next;
    }
    //se la lista e' vuota
    if (current == NULL){
        return 0;
    }
   //copia dei dati nello stesso salvataggio
    current -> data = player;
    return 1;
    
}

