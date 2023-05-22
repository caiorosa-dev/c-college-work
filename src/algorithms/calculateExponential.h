//
// Created by caior on 21/05/2023.
//

#ifndef SECOND_WORK_CALCULATEEXPONENTIAL_H
#define SECOND_WORK_CALCULATEEXPONENTIAL_H

#include <stdio.h>

void calculateExponential() {
    int numero;
    printf("Digite um numero: ");
    scanf("%d",&numero);

    int expoente;
    printf("Digite o numero do expoente: ");
    scanf("%d",&expoente);

    int resultado = 1;
    int i = 0;
    while(i != expoente){
        resultado = resultado * numero;
        i++;
    }

    printf("Resultado: %d", resultado);
}

#endif //SECOND_WORK_CALCULATEEXPONENTIAL_H
