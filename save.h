#ifndef SAVE_H
#define SAVE_H
#include "player.h"
typedef struct SaveNode{
    
    Player data; //struttura del player come dato
    struct SaveNode *next; //puntatore per il nuovo salvataggio

}SaveNode;
typedef struct SaveNode saveNode;


saveNode* createSave(Player player);
saveNode* insertSave(saveNode* head, Player player);
saveNode* deleteSave(saveNode* head, int i);
void printSave(saveNode* head);
int loadSave(Player*p, saveNode*head, int index);
int updateSave(saveNode*head, Player p, int index);


#endif