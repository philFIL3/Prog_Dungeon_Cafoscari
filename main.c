#include <stdio.h>
#include "cheats.h"
#include "menu.h"
#include <time.h>
#include "combat.h"
#include <stdlib.h>
//gameloop
//gestione del gioco

/*dove gestisco cosa faccio dopo aver scelto l'opzione del menù principale scrivo io farei
degli if, cioè if(menuprincipale() == 1){fai questo}
if(menuprincipale() == 2){fai questo}
poi scriverei un ciclo while
while(menuprincipaletrucchi()!=0){e facciamo altri tre if con le varie condizioni su cosa fanno}
*/
int game_state = 1;

int main(){
    char valorekonami = menuprincipale();
    if(konami(valorekonami)){
        menuprincipaletrucchi();
    }

    srand(time(NULL));
    int risultato_scontro = scontro_SignoreOscuro();

    if(risultato_scontro == 1){  //Vittoria dell'eroe
        return 0;
    }else{
        menuprincipale(); //In caso di sconfitta si ritorna al menu principale
    }

    return 0;
}