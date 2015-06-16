
#include "Audio.h"

int main()
{
	Audio * audio = new Audio();
	audio->Init();
	audio->LoadWavFile("../Data/Pickup_Coin.wav");
	while (1)
	{
	}
	audio->Shutdown();
	return 0;
}