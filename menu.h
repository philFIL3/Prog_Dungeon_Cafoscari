#ifndef MENU_H
#define MENU_H

char menuprincipale();
char menuprincipaletrucchi();
void seleziona_missione(Player *p);
saveNode* nuova_partita(saveNode* head, Player* currentplayer);
void carica_partita(saveNode * head, Player *currentplayer);
saveNode* menuVillaggio(saveNode*head, Player* p, int counter);

#endif