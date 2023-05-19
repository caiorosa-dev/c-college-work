//
// Created by caior on 18/05/2023.
//

#include <stdio.h>

const int speedToUpdateYear = 6;

void calculatePopulation() {
    separator();
    printf("\n\nOla, para comecar basta apertar o botao ENTER!\n\n");
    separator();
    readChar();

    float cityAPopulation = 5000000.0f;
    float cityBPopulation = 7000000.0f;
    float cityAGrowthRate = 0.03f;
    float cityBGrowthRate = 0.02f;

    int years = 0;
    int frame = 0;

    while (cityAPopulation < cityBPopulation) {
        char loadingChar = getLoadingChar();

        separator();
        nextLine();
        printf("%c Ano atual: %d.", loadingChar, years);
        printf("\n\nTaxa de Natalidade A: %.0f%% ao ano.\nTaxa de Natalidade B: %.0f%% ao ano.", cityAGrowthRate * 100, cityBGrowthRate * 100);
        printf("\n\nPopulacao A: %.0f pessoas.\nPopulacao B: %.0f pessoas.", cityAPopulation, cityBPopulation);
        nextLine();
        separator();

        sleepMs(125);
        clearTerminal();

        frame++;
        if (frame > speedToUpdateYear) {
            frame = 0;
        }

        if (frame != 0) continue;

        cityAPopulation += cityAPopulation * cityAGrowthRate;
        cityBPopulation += cityBPopulation * cityBGrowthRate;
        years++;
    }

    clearTerminal();
    separator();
    nextLine();
    printf("Finalizado! Anos totais: %d.", years);
    printf("\n\nTaxa de Natalidade A: %.0f%%.\nTaxa de Natalidade B: %.0f%%.", cityAGrowthRate * 100, cityBGrowthRate * 100);
    printf("\n\nPopulacao A: %.1f.\nPopulacao B: %.1f.", cityAPopulation, cityBPopulation);
}