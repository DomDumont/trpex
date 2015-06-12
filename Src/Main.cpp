
#include "Audio.h"

int main()
{
	Audio * audio = new Audio();
	audio->Init();
	audio->Shutdown();
	return 0;
}