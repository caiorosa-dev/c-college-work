//
// Created by caior on 18/05/2023.
//

#include <stdio.h>

void calculatePopulation() {
    float cityAPopulation = 5000000.0f;
    float cityBPopulation = 7000000.0f;
    float cityAGrowthRate = 0.03f;
    float cityBGrowthRate = 0.02f;
    int years = 0;

    while (cityAPopulation < cityBPopulation) {
        cityAPopulation += cityAPopulation * cityAGrowthRate;
        cityBPopulation += cityBPopulation * cityBGrowthRate;
        years++;
    }

    printf("Anos: %d", years);
}