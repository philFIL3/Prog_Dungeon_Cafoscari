#ifndef PLAYER_H
#define PLAYER_H

struct player {
    int HP;
    int coins;
    const char*items[5];
    int missions_completed;
    int stato_missioni[3];
};



typedef struct player Player;


void take_damage(int hp, int damage);

void collect_coins(int coins, int denaro);

void adventure(Player* p);

#endif