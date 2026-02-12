#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "cheats.h"
#include "menu.h"
#include <time.h>
#include "combat.h"
#include <stdlib.h>
#include "player.h"
#include "save.h"
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
    while (runGame)
    {
        opzione = menuprincipale();
        
        if (konami(opzione)){
            opzione = menuprincipaletrucchi();
    }
    
    int risultato_scontro = scontro_SignoreOscuro();

    if(risultato_scontro == 1){  //Vittoria dell'eroe
        return 0;
    }else{
        menuprincipale(); //In caso di sconfitta si ritorna al menu principale
        //DA VERIFICARE LA FUNZIONALITA' DEL MENU
    }}
    switch (opzione)
    {
    case '1':
        nuova_partita(&head, &currentplayer);
        menuVillaggio(&head, &currentplayer);
        break;
        case '2':
        carica_partita(&head, &currentplayer);
        menuVillaggio(&head, &currentplayer);
        break;
        case'3':
        esecuzionetrucchi();
        break;
        case'4':
        runGame = 0;
        break;
    
    default:
        printf("opzione invalida, scegli correttamente\n");

    }

    return 0;
}