//
// Created by Caio on 11/05/2023.
//

#include "libs/utils.h"

#ifndef ANIMATIONS
#define ANIMATIONS

const char menuMessages[][50] = { "1- Calcular cedulas e moedas",
                                   "2- Verificar numero primo",
                                   "3- Calcular divisores",
                                   "4- Calcular potencia",
                                   "5- Calcular Fibonacci",
                                   "6- Calcular media",
                                   "7- Descobrir maior salario",
                                   "8- Calcular tempo para ultrapassar populacao",
                                   "9- Jogo dos copos"
                                   };
const char defaultSeparator[] = "---------------------------------------";

void separator() {
    printf(defaultSeparator);
}

void nextLine()
{
    printf("\n\n");
}


void animatedMenuMessage() {
    separator();
    printf("\nCarregando...\n\n");

    for (int i = 0; i < 9; i++) {
        char* currentMessage = menuMessages[i];

        animatePrintf(currentMessage);
        printf("\n");
    }

    printf("\n");
    separator();
}

#endif //ANIMATIONS
