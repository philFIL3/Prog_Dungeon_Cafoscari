#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "cheats.h"
#include "menu.h"
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
    srand(time(NULL));
    char opzione= menuprincipale();
    if(konami(opzione)){
       opzione = menuprincipaletrucchi();
    };
    if (opzione == '1'){

    }else if (opzione == '2'){

    }else if(opzione == '3'){
        esecuzionetrucchi(/*metto il personaggio*/);
    }
    
    return 0;
}

