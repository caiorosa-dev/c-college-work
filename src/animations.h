//
// Created by Caio on 11/05/2023.
//

#include "libs/utils.h"



const char menuMessages[][50] = { "1- Calcular cedulas e moedas",
                                   "2- Verificar numero primo",
                                   "3- Converter binario",
                                   "4- Calcular divisores",
                                   "5- Calcular potencia",
                                   "6- Calcular Fibonacci",
                                   "7- Calcular media",
                                   "8- Descobrir maior salario",
                                   "9- Calcular tempo para ultrapassar populacao",
                                   "10- Jogo dos copos"
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

    for (int i = 0; i < 11; i++) {
        char* currentMessage = menuMessages[i];

        animatePrintf(currentMessage);
        printf("\n");
    }

    printf("\n");
    separator();
}
