//
// Created by caior on 21/05/2023.
//

#ifndef SECOND_WORK_CALCULATEDIVIDERS_H
#define SECOND_WORK_CALCULATEDIVIDERS_H

#include <stdio.h>

void calculateDividers() {
    int num;
    int divisorinicial;
    int divisorfinal;

    printf("Escreva um numero: ");
    scanf("%d", &num);
    fflush(stdin);

    printf("Escreva o divisor inicial: ");
    scanf("%d", &divisorinicial);
    fflush(stdin);

    printf("Escreva o divisor final: ");
    scanf("%d", &divisorfinal);

    while(divisorinicial < divisorfinal) {
        if(num % divisorinicial == 0){
            printf("\n%d e um divisor.", divisorinicial);
        }
        divisorinicial++;
    }
}

#endif //SECOND_WORK_CALCULATEDIVIDERS_H
