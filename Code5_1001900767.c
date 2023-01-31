/*Diwas Sapkota 1001900767 	Coding Assignment 5  */
#include "GameLib.h"
#include <string.h>
#include <stdlib.h>
int main(void)
{
	char Phrase[MAX_INPUT] = {};
	char DashedPhrase[MAX_INPUT] = {};
	char UpperPhrase[MAX_INPUT] = {};
	int Strikes = 0;
	int i;
	
    StartGame(Phrase);
    DashIt(Phrase, DashedPhrase);
    for(int x=0; x<strlen(Phrase); x++)
    {
        UpperPhrase[x]=toupper(Phrase[x]);
    }
	
	printf("\nHere's the phrase you need to guess\n");

	do
	{
		if(GuessALetter(Phrase, DashedPhrase, UpperPhrase)==0)
		{
			Strikes++;
			printf("\nStrike %d", Strikes);
		}
	}
        while((strchr(DashedPhrase, '-')!=NULL) && (Strikes<STRIKES));

	if (Strikes < STRIKES)
	{
		printf("\n\nYou figured it out!!\n\nThe phrase was \n\n%s", Phrase);
		printf("\n\nYOU WIN!!!!\n");
	}
	else
	{
		printf("\n\n");
		printf("%d STRIKES - YOU'RE OUT!!\n\n", STRIKES);
		printf("Game over\n\n");
	}
	return 0;
}
