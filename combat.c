#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "combat.h"

int scontro_SignoreOscuro(){

int round_corrente = 0;
int round_eroe_vinti = 0;
int round_signoreOscuro_vinti = 0;
int scelta_eroe = 0;
int scelta_signoreOscuro = 0;

while(round_eroe_vinti < 3 && round_signoreOscuro_vinti < 3){
  round_corrente++;
  printf("\n\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
  printf("SCONTRO FINALE | ROUND %d SU 5 | EROE: %d  ~  SIGNORE OSCURO: %d\n", round_corrente, round_eroe_vinti, round_signoreOscuro_vinti);
  printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
  printf("\nMosse disponibili\n 1. Scudo\n 2. Magia\n 3. Spada\n"); //ROCCIA = SCUDO / CARTA = MAGIA / FORBICI = SPADA
  printf("\nSeleziona una delle opzioni del menu [1-3]:   ");
  scanf("%d", &scelta_eroe);
  scelta_signoreOscuro = (rand() % 3) + 1;
  printf("\nIl Signore Oscuro ha scelto %d\n", scelta_signoreOscuro);

  if(scelta_eroe == scelta_signoreOscuro){
    printf("\nPareggio!\n");
    round_corrente--; //SE PAREGGIO IL ROUND NON VIENE CONTATO E VA RIPETUTO
  }else if( scelta_eroe == 1 && scelta_signoreOscuro == 3 || scelta_eroe == 2 && scelta_signoreOscuro == 1 || scelta_eroe == 3 && scelta_signoreOscuro == 2){
    printf("\nL'eroe ha vinto il round!\n");
    round_eroe_vinti++;
  }else{
    printf("\nIl signore Oscuro ha vinto il round!\n");
    round_signoreOscuro_vinti++;
  }
}

  if(round_eroe_vinti == 3){
    printf("\n\n~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\nCongratulazioni hai vinto!\n~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n");
    return 1;
  }else{
    printf("\n\n~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n        GAME OVER\n~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n");
    return 0;
  }
}