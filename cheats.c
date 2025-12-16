#include <stdbool.h>
#include <stdio.h>
#include "menu.h"

bool konami(char valorekonami){
    char verificatrucchi = valorekonami;
    char codice[11]={'w','w','s','s','a','d','a','d','b','a',' ',};     // Creo il mio array di controllo
    if(verificatrucchi == 'w'){                                         // Verifico se il primo valore inserito è uguale alla mia prima lettera dell'array
      for(int i=1; i<11; i++){  
      printf("Seleziona una delle opzioni del menu [1-2]:");            // Se è uguale inizio a iterare sull'array dalla seconda lettera fino all'undicesima, l'ultima          
    do {                                                                // Faccio un ciclo do-while per far si che riesca a controllarmi anche il carattere ' ' , cioè lo spazio
      scanf("%c", &verificatrucchi);                                    
    } while (verificatrucchi == '\n');
    if (verificatrucchi != codice[i]){                                  // Verifico che il carattere inserito sia uguale in modo da poter continuare ad iterare sul ciclo for
    return false;                                                       // Ritorno falso se diverso
    }
  }                                                                    
} else return false;                                                    // Faccio l'else del primo if, quindi in caso il primo carattere inserito non sia uguale a 'w' ritorno subito falso
  return true;                                                          // Se fino ad adesso è andato tutto bene ritorno semplicemente true
}