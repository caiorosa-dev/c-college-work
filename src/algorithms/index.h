//
// Created by Caio on 09/05/2023.
//

#ifndef SECOND_WORK_INDEX_H
#define SECOND_WORK_INDEX_H

#include "calculateMoney.h"

const int algorithmsAmount = 9;

void runAlgorithm(int id) {
    switch (id) {
        case 1:
            calculateMoney();
            break;
    }
}

#endif //SECOND_WORK_INDEX_H
