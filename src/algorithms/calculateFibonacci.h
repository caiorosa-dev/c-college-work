//
// Created by caior on 21/05/2023.
//

#ifndef SECOND_WORK_CALCULATEFIBONACCI_H
#define SECOND_WORK_CALCULATEFIBONACCI_H

#include <stdio.h>

void calculateFibonacci() {
    int n1=1;
    int n2=0;
    int resultado;

    int sequencia;
    printf("Escreva qual termo da Sequencia de Fibonacci voce deseja: ");
    scanf("%d", &sequencia);

    printf("\n");
    int i=1;
    while(i<=sequencia){
        if(i % 2 == 0){
            resultado = n1 + n2;
            n2 = resultado;
            printf("Termo %d = %d\n",i, resultado);
            i++;
        }else{
            resultado = n1 + n2;
            n1 = resultado;
            printf("Termo %d = %d \n",i, resultado);
            i++;
        }
    }

    printf("\nO termo %d da sequencia de fibonacci e: %d", sequencia, resultado);
}

#endif //SECOND_WORK_CALCULATEFIBONACCI_H
