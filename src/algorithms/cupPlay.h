//
// Created by Caio on 19/05/2023.
//

#ifndef SECOND_WORK_CUPPLAY_H
#define SECOND_WORK_CUPPLAY_H

#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "../libs/utils.h"
#include "../animations.h"

const int PLAYER_SECONDS = 5;

bool cups[3];

/**
 * Utility Functions
 */

void changePositions(int firstPosition, int secondPosition) {
    bool temporaryVar = cups[firstPosition];

    cups[firstPosition] = cups[secondPosition];
    cups[secondPosition] = temporaryVar;
}

/**
 * Game Functions
 */

void runPlay(int play) {
    switch (play) {
        case 0:
            changePositions(0, 1);
            break;
        case 1:
            changePositions(1, 2);
            break;
        case 2:
            changePositions(2, 0);
            break;
        default:
            break;
    }
}

int runRandomPlay() {
    int random = randomNumber(2);

    runPlay(random);

    return random;
}

int processBet(char bet) {
    int betNumber = 0;

    if (bet == 'a' || bet == 'A') betNumber = 0;
    if (bet == 'b' || bet == 'B') betNumber = 1;
    if (bet == 'c' || bet == 'C') betNumber = 2;

    return betNumber;
}

bool checkWin(int bet) {
    for (int i = 0; i < 3; ++i) {
        bool value = cups[i];

        if (value && bet == i) return true;
    }

    return false;
}

char getPositionChar() {
    for (int i = 0; i < 3; ++i) {
        bool value = cups[i];

        if (value == true) {
            switch (i) {
                case 1:
                    return 'B';
                case 2:
                    return 'C';
                default:
                    return 'A';
            }
        }
    }

    return 'A';
}

void initializeArray() {
    for (int i = 0; i < 3; ++i) {
        printf("Valor %d: %d\n", i, cups[i]);
        cups[i] = false;
    }

    int random = randomNumber(2);

    cups[random] = true;
}

void showTypeOfPlay(int typeOfPlay) {
    switch (typeOfPlay) {
        case 1:
            printf("A banca trocou de lugar os copos B e C.");
            break;
        case 2:
            printf("A banca trocou de lugar os copos C e A.");
            break;
        default:
            printf("A banca trocou de lugar os copos A e B.");
            break;
    }
}

void renderCupsWithPosition(int position) {
    for (int i = 0; i < 3; ++i) {
        char renderChar = i == position ? '*' : ' ';

        printf(" |%c| ", renderChar);
    }

    printf("\n  -    -    -  ");
    printf("\n  A    B    C  ");
}

void renderCups(bool showWhereIs) {
    for (int i = 0; i < 3; ++i) {
        char renderChar = cups[i] == true ? '*' : ' ';
        if (!showWhereIs) renderChar = ' ';

        printf(" |%c| ", renderChar);
    }

    printf("\n  -    -    -  ");
    printf("\n  A    B    C  ");
}

/**
 * Main Function
 */

void executeCupPlay() {
    printf("Ola! Primeiro, informe se quer jogar em 1 ou 2 jogadores.\n\n> ");

    bool isTwoPlayers = readChar() == '2';
    clearTerminal();
    separator();
    nextLine();

    if (isTwoPlayers) {
        printf("Muito bem! O jogo esta configurado para 2 jogadores.\n\nO jogo funcionara da seguinte forma:\n1. Turno da Banca: Escolhe qual movimento ira realiza (Ele realiza 3 movimentos por turno).\n2. Turno do espectador: Chuta em qual copo esta a moeda (Ele tem 5 segundos para ler as informacoes).\n3. O jogo acaba quando o espectador acertar o chute.\n\nAperte ENTER para jogar.");
    } else {
        printf("Muito bem! O jogo esta configurado para 1 jogador.\n\nO jogo funcionara da seguinte forma:\n1. Enquanto voce apertar ENTER, a banca ira realizar um movimento aleatorio.\n2. Enquanto voce quiser, a banca realizara movimentos aleatorios.\n3. Voce chuta em qual copo esta a moeda, e assim finaliza o jogo.\n\nAperte ENTER para jogar.");
    }

    nextLine();
    separator();

    readChar();
    clearTerminal();
    separator();
    nextLine();

    char playerName[50];
    char masterName[50];

    if (isTwoPlayers) {
        printf("Primeiramente, me informe o nome do primeiro jogador!\n\nNome do jogador Banca: ");
        strcpy(masterName, readString());

        clearTerminal();
        separator();
        nextLine();

        printf("Agora, me informe o nome do segundo jogador!\n\nNome do jogador da Banca: %s.\nNome do Espectador: ", masterName);
        strcpy(playerName, readString());
    } else {
        printf("Primeiramente, me informe o seu nome!\n\nNome do jogador: ");
        strcpy(playerName, readString());
        strcpy(masterName, "PC");
    }

    clearTerminal();

    nextLine();
    separator();

    initializeArray();

    bool runGame = true;
    bool isMasterTimeToPlay = true;

    bool gameFinished = false;
    bool win = false;
    bool firstPlay = !isTwoPlayers;

    char bet = '0';

    bool readyToPlay = false;
    int remainingSeconds = 5;

    bool outOfTime = false;
    int remainingPlayerSeconds = PLAYER_SECONDS;

    int countOfPlays = 0;
    int lastPlays[3];
    char lastPosition = ' ';

    while (runGame) {
        clearTerminal();
        separator();
        nextLine();

        // Check if bet was correct
        if (bet != '0') {
            int betNumber = processBet(bet);

            win = checkWin(betNumber);
            if (!isTwoPlayers) gameFinished = true;

            if (isTwoPlayers && win) {
                gameFinished = true;
            } else if (isTwoPlayers) {
                bet = '0';
                printf("\n\n%s, infelizmente voce errou! Aperte ENTER para a banca jogar novamente...", playerName);
                readChar();

                isMasterTimeToPlay = true;
                readyToPlay = false;
            }
        }

        // System to delay the play
        if (isTwoPlayers && !readyToPlay) {
            if (isMasterTimeToPlay) {
                printf("TURNO DA BANCA (%s).", masterName);
            } else {
                printf("TURNO DO ESPECTADOR (%s)", playerName);
            }

            printf("\n\nIniciando em %d segundos...", remainingSeconds);
            nextLine();
            separator();

            remainingSeconds--;
            if (remainingSeconds == 0) {
                readyToPlay = true;
                remainingSeconds = 5;
            }

            sleepMs(1000);
            continue;
        }

        bool shouldRenderCoinLocation = isMasterTimeToPlay && isTwoPlayers || gameFinished || firstPlay;
        renderCups(shouldRenderCoinLocation);

        // Verify if the game is ended before start a new play, only for singleplayer
        if (gameFinished && !isTwoPlayers) {
            printf("\n\nVoce chutou %c, e como pode ver...\n", bet);
            sleepMs(500);

            if (win)
                printf("A moeda estava no lugar correto!\n\nParabens %s!", playerName);
            else
                printf("A moeda estava no lugar errado :(\n\nA banca (PC) ganhou! Fica para a próxima %s :(", playerName);

            return;
        }

        // Verify if the game is ended before start a new play, multiplayer version
        if (gameFinished && isTwoPlayers) {
            printf("\n\nO espectador (%s) acertou chutando %c!\n", playerName, bet);
            printf("A banca (%s) realizou %d jogada (s).", masterName, countOfPlays);
            return;
        }

        // Singleplayer automatic master play
        if (isMasterTimeToPlay && !isTwoPlayers) {
            int typeOfPlay = runRandomPlay();
            countOfPlays++;
            if (firstPlay) {
                printf("\n\nA moeda comecou na posicao (*) acima. Depois desta jogada, a moeda sera ocultada!");
                firstPlay = false;
            }

            nextLine();
            showTypeOfPlay(typeOfPlay);

            printf("\nForam realizadas %d jogadas ate agora.\n\nAperte ENTER para a banca realizar outra jogada ou digite 'y' para continuar.\n\nDeseja realizar o seu chute? ", countOfPlays);

            if (readChar() == 'y') {
                isMasterTimeToPlay = false;
            }
            continue;
        }

        if (isMasterTimeToPlay) {
            printf("\n\nA moeda esta na posicao (*) marcada acima. Você pode executar as seguintes jogadas:\n\n1 - Trocar os copos A e B.\n2 - Trocar os copos B e C\n3 - Trocar os copos A e C\n\nE ai, %s, qual jogadas voce vai fazer? Digite 1, 2 ou 3.", masterName);
            lastPosition = getPositionChar();
            countOfPlays++;

            for (int i = 0; i < 3; ++i) {
                printf("\nJogada %d.\n> ", i + 1);
                int playToExecute = (readInt() - 1);

                lastPlays[i] = playToExecute;
                runPlay(playToExecute);
            }

            clearTerminal();

            separator();
            nextLine();
            renderCups(true);
            printf("\n\nAs jogadas resultaram na posicao (*) acima! Aperte ENTER para ir para o turno do espectador (%s)", playerName);
            nextLine();
            separator();
            readChar();

            isMasterTimeToPlay = false;
            readyToPlay = false;
            continue;
        }

        // Singleplayer logic
        if (!isTwoPlayers || outOfTime) {
            if (!isTwoPlayers) {
                printf("\n\n%d jogadas foram realizadas. %s, informe qual sera o seu chute!\n\nDigite A, B ou C!\n> ", countOfPlays, playerName);
                isMasterTimeToPlay = false;
            } else {
                printf("\n\nSeu tempo acabou! Agora chegou a hora de chutar.\n\nDigite A, B ou C!\n> ");
            }

            bet = readChar();
            clearTerminal();
            separator();
            printf("\n\nPreparando resultados...\n\n");
            separator();

            outOfTime = false;
            remainingPlayerSeconds = PLAYER_SECONDS;

            sleepMs(1500);
            continue;
        }

        printf("\n\nAgora chegou a sua vez! Tentar adivinhar a onde está a moeda.\n\nPosicao inicial: %c", lastPosition);
        printf("\nMovimentos realizados em ordem: ");
        for (int i = 0; i < 3; ++i) {
            int typeOfPlay = lastPlays[i];

            printf("\n");
            showTypeOfPlay(typeOfPlay);
        }

        printf("\n\nVocê tem %d segundos até as informacoes serem limpas e voce chutar!", remainingPlayerSeconds);
        remainingPlayerSeconds--;

        if (remainingPlayerSeconds == 0) {
            outOfTime = true;
        }
        sleepMs(1000);
    }
}

#endif //SECOND_WORK_CUPPLAY_H
