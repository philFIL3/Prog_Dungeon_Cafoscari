#include <stdio.h>
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

int main(){
    char valorekonami = menuprincipale();
    if(konami(valorekonami)){
        menuprincipaletrucchi();
    }
    return 0;
}