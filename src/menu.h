//
// Created by Caio on 09/05/2023.
//

#ifndef SECOND_WORK_MENU_H
#define SECOND_WORK_MENU_H

#include <stdbool.h>
#include "libs/utils.h"
#include "algorithms/index.h"
#include "animations.h"

const char menuMessage[] = "\nCarregamento Finalizado.\n\n1- Calcular cedulas e moedas\n2- Verificar numero primo\n3- Converter binario\n4- Calcular divisores\n5- Calcular potencia\n6- Calcular Fibonacci\n7- Calcular media\n8- Descobrir maior salario\n9- Calcular tempo para ultrapassar populacao\n10- Jogo dos copos\n\n";
const char goodbyeMessage[] = "Muito obrigado por usar nosso software!";

/*
 * Utility functions
 */

void executeFunction(int option) {
    clearTerminal();
    runAlgorithm(option);

    nextLine();
    separator();

    nextLine();
    printf("Caso queira executar esta funcao novamente, digite 'y', caso nao, aperte ENTER.\n\nExecutar novamente? ");

    bool executeAgain = readChar() == 'y';
    if (executeAgain == 1) {
        executeFunction(option);
    }
}

/*
 * Main Function
 */

void menu() {
    int option = 1;

    while (option != 0) {
        clearTerminal();
        animatedMenuMessage();
        clearTerminal();
        sleepMs(500);
        separator();
        printf(menuMessage);
        separator();

        nextLine();
        printf("Executar funcao: ");

        option = readInt();

        if (option == 0) continue;

        if (option <= 0 || option > algorithmsAmount) {
            clearTerminal();
            printf("Opção inválida! Aperte ENTER para tentar novamente.");
            readChar();
            continue;
        }

        clearTerminal();
        separator();
        printf("\n\nCarregando funcao...\n\n");
        separator();
        sleepMs(750);
        executeFunction(option);
    }

    clearTerminal();
    printf(goodbyeMessage);
}

#endif //SECOND_WORK_MENU_H
