#ifndef DUNGEON_H
#define DUNGEON_H
#include <stdbool.h>
#include "player.h"

typedef enum {
    PALUDE,
    GROTTA,
    MAGIONE
} TipoMissione;

bool dungeon_controller(Player* p, TipoMissione tipo);
bool paludeputrescente(Player *p, bool forzata, char** nome_stanza);
bool magione_infestata(Player *p, bool forzata, char** nome_stanza);
bool grottadicristallo(Player* p, bool forzata, char** nome_stanza);
#endif