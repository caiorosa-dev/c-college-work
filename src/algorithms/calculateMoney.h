//
// Created by caior on 11/05/2023.
//

#include "../libs/utils.h"
#include "../animations.h"

const float coinTypesValues[] = {100.0f, 50.0f, 20.0f, 10.0f, 5.0f, 2.0f, 1.0f, 0.5f, 0.25f, 0.10f, 0.05f, 0.01f};
const char coinTypesNames[][20] = { "Cedula R$100",
                                    "Cedula R$50",
                                    "Cedula R$20",
                                    "Cedula R$10",
                                    "Cedula R$5",
                                    "Cedula R$2",
                                    "Moeda R$1",
                                    "Moeda 50 centavos",
                                    "Moeda 25 centavos",
                                    "Moeda 10 centavos",
                                    "Moeda 5 centavos",
                                    "Moeda 1 centavo",
                                    };

void calculateMoney() {
    separator();
    animatePrintf("\n\nInforme a quantia a ser processado abaixo!\n\n");
    separator();
    animatePrintf("\n\nQuantia para processamento: ");
    float number = readFloat();
    float numberWithoutProcess = number;

    clearTerminal();
    separator();
    printf("\n\nQuantia para processamento: R$%.2f\nResultado do processamento para cedulas e moedas: \n", numberWithoutProcess);

    do {
        bool processed = false;

        for (int i = 0; i < 12; ++i) {
            float value = coinTypesValues[i];

            if (number < value || processed){
                continue;
            }

            processed = true;
            number -= value;

            char* name = coinTypesNames[i];
            animatePrintf("\n * ");
            printf(name);
        }
    } while (number > 0.01);

    sleepMs(250);
}