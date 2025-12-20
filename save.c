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

    saveNode* HEAD = malloc(sizeof(saveNode)); //allocchiamo la grandezza del nodo
    HEAD->data = player;
    HEAD->next = NULL;
    return HEAD;

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
    printf("%d) %d HP, %d coins, %d items, %d missions completed\n"  );
    i,
    head->data.HP,
    head->data.coins,
    head->data.items,
    head->data.missions_completed;
    head = head->next;
    i++;

        };

    };


//delete save, load save sono le prossime funzioni da implementare