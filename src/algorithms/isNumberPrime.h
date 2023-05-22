//
// Created by caior on 21/05/2023.
//

#ifndef SECOND_WORK_ISNUMBERPRIME_H
#define SECOND_WORK_ISNUMBERPRIME_H

#include <stdio.h>

void isNumberPrime() {
    int numero;

    printf("Digite um número: ");
    scanf("%d",&numero);

    int quantidadeDeNumerosDivisiveis = 0;

    for(int numeroSendoDividendo = 2;numeroSendoDividendo < numero; numeroSendoDividendo++){
        if(numero % numeroSendoDividendo == 0){
            quantidadeDeNumerosDivisiveis += 1;
            printf("É divisivel por: %d\n", numeroSendoDividendo);
        }
    }

    if(quantidadeDeNumerosDivisiveis == 0){
        printf("\nEsse número é primo! ");
    } else{
        printf("\nEsse número não é primo! ");
    }
}

#endif //SECOND_WORK_ISNUMBERPRIME_H
