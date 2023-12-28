#include<stdio.h>
#include<stdlib.h>

void saveTheGame(int gameSize, char arr[2 * gameSize + 1][2 * gameSize + 1], int playerTurn, char player1[256], char player2[256], int p1Score, int p2Score, int player1Moves, int player2Moves, int z, int dfsFlag, int botFlag, int savedTime) {
    FILE *fb, *fb2;
    char saveSlot = '1', x;
    int k = 0;

    do {
        k++;
        do {
            system("cls");
            if (k > 1) {
                printf(" there is a saved game in this slot Do you want to overwrite it? (y/n)\n");
                getchar();
                scanf("%c", &x);
                if (x == 'y') {
                    break;
                }
            }

            if (saveSlot - '0' > 3 || saveSlot - '0' <= 0) {
                printf("Invalid value\n");
            }

            printf("Choose save slot from 1 to 3\n");
            scanf(" %c", &saveSlot);
        } while (saveSlot - '0' > 3 || saveSlot - '0' <= 0);

        if (saveSlot == '1') {
            fb2 = fopen("saveSlot1.bin", "rb");
            fb = fopen("saveSlot1.bin", "wb+");
        } else if (saveSlot == '2') {
            fb2 = fopen("saveSlot2.bin", "rb");
            fb = fopen("saveSlot2.bin", "wb+");
        } else if (saveSlot == '3') {
            fb2 = fopen("saveSlot3.bin", "rb");
            fb = fopen("saveSlot3.bin", "wb+");
        }
          if (x == 'y') {
                    break;
                }
    } while (fb2 != NULL);

    char numericalGameData[100];
    sprintf(numericalGameData, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d.",
            gameSize, playerTurn, dfsFlag, botFlag, savedTime, p1Score, p2Score, player1Moves, player2Moves, z);
    fwrite(numericalGameData, sizeof(char), 100, fb);

    for (int i = 0; i <= 2 * gameSize; i++) {
        fwrite(arr[i], sizeof(char), 2 * gameSize + 1, fb);
    }

    fwrite(player1, sizeof(char), 256, fb);
    fwrite(player2, sizeof(char), 256, fb);

    fclose(fb);
    fclose(fb2);
}
