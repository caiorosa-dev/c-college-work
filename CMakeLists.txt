cmake_minimum_required(VERSION 3.25)
project(second_work C)

set(CMAKE_C_STANDARD 11)

add_executable(second_work main.c src/menu.h src/libs/utils.h src/algorithms/index.h src/animations.h src/algorithms/calculateMoney.h src/algorithms/calculatePopulation.h src/algorithms/cupPlay.h src/algorithms/isNumberPrime.h src/algorithms/calculateExponential.h src/algorithms/calculateFibonacci.h src/algorithms/selectHighestSalary.h src/algorithms/calculateDividers.h)
