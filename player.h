#ifndef PLAYER_H
#define PLAYER_H

struct player {
    int HP;
    int coins;
    const char*items[5];
    int missions_completed;
};

typedef struct player Player;

int player_alive(Player*p);

void take_damage(Player* p, int damage);

void collect_coins(Player* p, int denaro);

void adventure(Player* p);

void esecuzionetrucchi(Player *p, /*dare un parametro degli salvataggi*/);
#endif