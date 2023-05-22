//
// Created by caior on 21/05/2023.
//

#ifndef SECOND_WORK_SELECTHIGHESTSALARY_H
#define SECOND_WORK_SELECTHIGHESTSALARY_H

#include <stdio.h>

void selectHighestSalary() {
    float salario;
    float maiorsalario;
    int numMaiorPessoa;

    printf("Escreva o seu salario, digite 0 quando quiser terminar.");
    printf("\nSeu salario: ");
    scanf("%f", &salario);
    printf("\n");

    maiorsalario=salario;
    numMaiorPessoa=1;

    int i=2;
    while(salario != 0){
        printf("Escreva o proximo salario: ");
        scanf("%f", &salario);

        if(salario>maiorsalario){
            maiorsalario=salario;
            numMaiorPessoa=i;
        }

        i++;
    }
    printf("\nO maior salario pertence a pessoa numero %d.\n", numMaiorPessoa);
    printf("Com o salario de: %.2f.", maiorsalario);
}

#endif //SECOND_WORK_SELECTHIGHESTSALARY_H
