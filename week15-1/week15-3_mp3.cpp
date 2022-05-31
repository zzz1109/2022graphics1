#include <stdio.h>
#include "CMP3_MCI.h"
CMP3_MCI mp3;

int main()
{
    mp3.Load("badbad.mp3");
    mp3.Play();

    printf("隨便等你輸入數字,程式就卡住囉: ");
    int N;
    scanf("%d",&N);
}
