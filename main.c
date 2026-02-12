#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "cheats.h"
#include "menu.h"
#include <time.h>
#include "combat.h"
#include <stdlib.h>
#include "save.h"
#include "player.h"
//gameloop
//gestione del gioco

/*dove gestisco cosa faccio dopo aver scelto l'opzione del menù principale scrivo io farei
degli if, cioè if(menuprincipale() == 1){fai questo}
if(menuprincipale() == 2){fai questo}
poi scriverei un ciclo while
while(menuprincipaletrucchi()!=0){e facciamo altri tre if con le varie condizioni su cosa fanno}
*/
int main(){
    srand(time(NULL));
    saveNode*head = NULL;
    Player currentplayer;
    char opzione; //= menuprincipale();
    int runGame = 1;
    int counter = 0;
    while (runGame)
    {
        opzione = menuprincipale();
        
        if (konami(opzione)){
            opzione = menuprincipaletrucchi();
    }
    
    switch (opzione)
    {
    case '1':
        head = nuova_partita(head, &currentplayer);
        counter = 0;
        head = menuVillaggio(head, &currentplayer, counter);
  
        break;
        case '2':
        counter = carica_partita(head, &currentplayer);
        head = menuVillaggio(head, &currentplayer, counter);

        break;
        case'3':
        esecuzionetrucchi(&currentplayer, head);

        
        break;
        case'4':
        runGame = 0;
        break;
    
    default:
        printf("opzione invalida, scegli correttamente\n");
    break;
    }
}

    return 0;
}