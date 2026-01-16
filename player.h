#ifndef PLAYER_H
#define PLAYER_H

#include <stdbool.h>

typedef struct {
    int HP;
    int coins;

    bool spada_eroe;
    bool chiave_castello;

    int missions_completed;
    int stato_missioni[3];
} Player;

void take_damage(Player* p, int damage);
void collect_coins(Player* p, int denaro);
void adventure(Player* p);

#endif
