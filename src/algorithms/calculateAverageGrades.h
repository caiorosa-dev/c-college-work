//
// Created by Caio on 22/05/2023.
//

#ifndef SECOND_WORK_CALCULATEAVERAGEGRADES_H
#define SECOND_WORK_CALCULATEAVERAGEGRADES_H

#include <stdio.h>

void calculateAverageGrades() {
    int alunos;

    printf("Digite quantos alunos tem na sala: ");
    scanf("%d",&alunos);
    fflush(stdin);

    float nota;
    float soma = 0.0f;
    float resultado;

    for(int i = 1; i <= alunos; i++){
        printf("Digite a nota do aluno %d: ", i);
        scanf("%f",&nota);
        fflush(stdin);

        soma = soma + nota;
    }

    resultado = soma / alunos;
    printf("A média dos alunos é: %.2f", resultado);
}




#endif //SECOND_WORK_CALCULATEAVERAGEGRADES_H
