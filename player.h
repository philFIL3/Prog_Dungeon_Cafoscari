#ifndef PLAYER_H
#define PLAYER_H

struct player {
    int HP;
    int coins;
    const char*items[5];
    int mission_complete;

};

void take_damage(int hp, int damage) {
    hp-= damage;
}

void collect_coins(int coins, int denaro){
    coins += denaro;
}

void adventure(int mission_complete){
    mission_complete++;
}

#endif