//
// Created by Caio on 09/05/2023.
//

#ifndef SECOND_WORK_INDEX_H
#define SECOND_WORK_INDEX_H

#include "calculateMoney.h"
#include "calculatePopulation.h"
#include "cupPlay.h"
#include "calculateFibonacci.h"
#include "isNumberPrime.h"
#include "calculateExponential.h"
#include "calculateDividers.h"
#include "selectHighestSalary.h"
#include "calculateAverageGrades.h"

const int algorithmsAmount = 9;

void runAlgorithm(int id) {
    switch (id) {
        case 1:
            calculateMoney();
            break;
        case 2:
            isNumberPrime();
            break;
        case 3:
            calculateDividers();
            break;
        case 4:
            calculateExponential();
            break;
        case 5:
            calculateFibonacci();
            break;
        case 6:
            calculateAverageGrades();
            break;
        case 7:
            selectHighestSalary();
            break;
        case 8:
            calculatePopulation();
            break;
        case 9:
            executeCupPlay();
            break;
    }
}

#endif //SECOND_WORK_INDEX_H
