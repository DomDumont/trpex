#include "Global.h"
#include "Audio.h"
#include "Utils.h"




bool Audio::Init()
{
	

	 this->device = alcOpenDevice(NULL);
    if (this->device == NULL)
		{
		UTI_Log("Error in Audio::Init\n");
        return false;
		}

	// Création du contexte
    this->context = alcCreateContext(this->device, NULL);
    if (this->context == NULL)
		{
		UTI_Log("Error in Audio::Init, cannot create context\n");
        return false;
		}
 
    // Activation du contexte
    if (alcMakeContextCurrent(this->context) == NULL)
		{
		UTI_Log("Error in Audio::Init, cannot set current context\n");
        return false;
		}

	UTI_Log("Audio::Init OK\n");
	return true;
}

void Audio::Shutdown()
{
	UTI_Log("Audio::Shutdown\n");
}
