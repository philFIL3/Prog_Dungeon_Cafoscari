#ifndef PLAYER_H
#define PLAYER_H

#include <stdbool.h>
typedef struct {
    int HP;
    int coins;
    bool spada_eroe;
    bool spada;
    bool chiave_castello;
    bool armatura;
    int stato_missioni[3];
    int missione_completata;
} Player;

void take_damage(Player* p, int damage);
void collect_coins(Player* p, int denaro);
void adventure(Player* p);
void esecuzionetrucchi(Player *p, saveNode* head);
#endif
