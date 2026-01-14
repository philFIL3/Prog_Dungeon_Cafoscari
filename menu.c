#include <stdio.h>
#include <stdbool.h>
//menu iniziale di gioco

// funzione per controllare se viene inserito uno dei caratteri di konami 
bool controllokonami(char konami){
  char codice[11]={'w','w','s','s','a','d','a','d','b','a',' '};
  for(int i = 0; i<11 ;i++){
   if (konami == codice[i]) return true;
  }
  return false;
}

char menuprincipale(){
  char scelta;
  printf("Menu Principale:\n\n");
  printf("    1. Nuova partita\n");
  printf("    2. Carica Salvataggio\n\n");
  printf("Seleziona una delle opzioni del menu [1-2]:");
  scanf(" %c", &scelta);
  if ( scelta != '1' && scelta != '2' && !controllokonami(scelta)){
  
    return menuprincipale();
  }
else {
  return scelta;
    }
  }
  
char menuprincipaletrucchi(){
  char sceltatrucchi;
  printf("Menu Principale:\n\n");
  printf("    1. Nuova partita\n");
  printf("    2. Carica Salvataggio\n");
  printf("    3. Trucchi\n");
  printf("Seleziona una delle opzioni del menu [1-3]:");
  scanf(" %c", &sceltatrucchi);
  return sceltatrucchi;
}
//menu del Villaggio
//menu missionni
//missioni selection menu