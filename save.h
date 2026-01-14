#ifndef SAVE_H
#define SAVE_H

typedef struct SaveNode{
    
    Player data; //struttura del player come dato
    struct SaveNode *next; //puntatore per il nuovo salvataggio

}SaveNode;
typedef struct SaveNode saveNode;


saveNode* createSave(Player player);
saveNode* insertSave(saveNode* head, Player player);
saveNode* deleteSave(saveNode* head, int i);
void printSave(saveNode* head);
int loadSave(saveNode*head, int index, Player*p);
int updateSave(saveNode*head,int index, Player p);


#endif