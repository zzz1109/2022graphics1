#include <windows.h>
#include <stdio.h>
int main()
{
    printf("PlaySound()���e\n");
    PlaySound("badbad.wav",NULL,SND_SYNC);
    printf("PlaySound()����\n");
}
