#include<stdio.h>
#include<stdlib.h>
void saveTheGame(int gameSize,char Grid[2*gameSize+1][2*gameSize+1],int playerTurn,char player1[256],char player2[256],int p1Score,int p2Score,int player1Moves,int player2Moves,int z, int dfsFlag, int botFlag,int savedTime){
    FILE *fb;
     char saveSlot='1';
    do
    {
    system("cls");
    if(saveSlot-'0'>3 ||saveSlot-'0'<=0) {
    printf("invalid value");
    }
    printf("choose saveslot from 1 to 3\n");
    scanf("%c",&saveSlot);
    } while ( saveSlot-'0'>3 ||saveSlot-'0'<=0);
    if(saveSlot=='1'){
        fb=fopen("saveSlot1.bin","w+");
    }
    else if(saveSlot=='2'){
         fb=fopen("saveSlot2.bin","w+");
    }
    else if(saveSlot=='3'){
         fb=fopen("saveSlot3.bin","w+");
    }
    char numericalGameData[100];
    sprintf(numericalGameData,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d.",gameSize,playerTurn,dfsFlag,botFlag,savedTime,p1Score,p2Score,player1Moves,player2Moves,z);
    fwrite(numericalGameData,sizeof(char),100,fb);
    int i;
    for(i=0;i<=2*gameSize;i++){
        fwrite(Grid[i],sizeof(char),2*gameSize+1,fb);
    }
    fwrite(player1,sizeof(char),256,fb);
    fwrite(player2,sizeof(char),256,fb);

    fclose(fb);
}
