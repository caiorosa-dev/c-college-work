//
// Created by Caio on 11/05/2023.
//

#include "libs/utils.h"

#ifndef ANIMATIONS
#define ANIMATIONS

const char menuMessageLines[][50] = { "1- Calcular cedulas e moedas",
                                   "2- Verificar numero primo",
                                   "3- Calcular divisores",
                                   "4- Calcular potencia",
                                   "5- Calcular Fibonacci",
                                   "6- Calcular media das notas",
                                   "7- Descobrir maior salario",
                                   "8- Calcular tempo para ultrapassar populacao",
                                   "9- Jogo dos copos",
                                   "0- Sair"
                                   };

const char goodbyeMessageLines[][70] = { "--------------------------------------",
                                  "",
                                  "Muito obrigado por usar o nosso software!",
                                  "",
                                  "Desenvolvido por:",
                                  "- Caio Furtado Rosa (https://caiorosadev.com)",
                                  "   * Menu",
                                  "   * Libs",
                                  "   * Exercicios 1, 8 e 9.",
                                  "",
                                  "- Gabriel Silveira",
                                  "   * Exercicios 3, 5 e 7.",
                                  "",
                                  "- Guilherme Silvestre da Rosa",
                                  "   * Exercicios 2, 4 e 6.",
                                  "",
                                  "--------------------------------------"
};

const char defaultSeparator[] = "---------------------------------------";
const char loadingBashAnimation[] = {
        '-', '\\', '|', '/'
};

void separator() {
    printf(defaultSeparator);
}

void nextLine()
{
    printf("\n\n");
}

int currentBashFrame = 0;

char getLoadingChar() {
    currentBashFrame++;
    if (currentBashFrame > 3) {
        currentBashFrame = 0;
    }

    return loadingBashAnimation[currentBashFrame];
}

void printGoodbyeMessage(int linesToRender, int lines) {
    int spacedLines = lines - linesToRender;

    for (int i = 0; i < spacedLines; ++i) {
        printf("\n");
    }

    for (int i = 0; i < linesToRender; ++i) {
        printf("%s", goodbyeMessageLines[i]);
        printf("\n");
    }
}

void animatedGoodbyeMessage() {
    const int totalLines = 17;

    for (int i = 1; i <= totalLines; ++i) {
        clearTerminal();
        printGoodbyeMessage(i, totalLines);
        sleepMs(300);
    }
}

void animatedMenuMessage() {
    separator();
    printf("\nCarregando...\n\n");

    for (int i = 0; i < 11; i++) {
        char* currentMessage = menuMessageLines[i];

        animatePrintf(currentMessage);
        printf("\n");
    }

    printf("\n");
    separator();
}

#endif //ANIMATIONS
