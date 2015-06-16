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


int Audio::LoadWavFile(std::string fullPath)
 {
	BOOL bResult = FALSE;
	_WAVEDESCR descriptor;
	_WAVEFORMAT format;
	LPBYTE m_lpData = NULL;
	DWORD m_dwSize = 0;
 
       // Load .WAV file
       FILE* file = fopen(fullPath.c_str(), "rb");
       if (file != NULL)
       {
           // Read .WAV descriptor
           fread(&descriptor, sizeof(_WAVEDESCR), 1, file);
   
           // Check for valid .WAV file
           if (strncmp((LPCSTR)descriptor.wave, "WAVE", 4) == 0)
           {
               // Read .WAV format
               fread(&format, sizeof(_WAVEFORMAT), 1, file);
   
               // Check for valid .WAV file
               if ((strncmp((LPCSTR)format.id, "fmt", 3) == 0) && (format.format == 1))
              {
                  // Read next chunk
                  BYTE id[4];
                  DWORD size;
                  fread(id, sizeof(BYTE), 4, file);
                  fread(&size, sizeof(DWORD), 1, file);
                  DWORD offset = ftell(file);
  
                  // Read .WAV data
                  LPBYTE lpTemp = (LPBYTE)malloc(descriptor.size*sizeof(BYTE));
                  while (offset < descriptor.size)
                  {
                      // Check for .WAV data chunk
                      if (strncmp((LPCSTR)id, "data", 4) == 0)
                      {
                          if (m_lpData == NULL)
                              m_lpData = (LPBYTE)malloc(size*sizeof(BYTE));
                          else
                              m_lpData = (LPBYTE)realloc(m_lpData, (m_dwSize+size)*sizeof(BYTE));
                          fread(m_lpData+m_dwSize, sizeof(BYTE), size, file);
                          m_dwSize += size;
                      }
                      else
                          fread(lpTemp, sizeof(BYTE), size, file);
  
                      // Read next chunk
                      fread(id, sizeof(BYTE), 4, file);
                      fread(&size, sizeof(DWORD), 1, file);
                      offset = ftell(file);
                  }
                  free(lpTemp);
  
                  bResult = TRUE;
              }
          }
  
          // Close .WAV file
          fclose(file);
      }
  

	  // Création du tampon OpenAL
      ALuint Buffer;
      alGenBuffers(1, &Buffer);

	  // Remplissage avec les échantillons lus
		alBufferData(Buffer, AL_FORMAT_MONO16, m_lpData, m_dwSize , 44100);

    // Vérification des erreurs
    if (alGetError() != AL_NO_ERROR)
        return 0;

	// Création d'une source
	ALuint Source;
	alGenSources(1, &Source);
	// On attache le tampon contenant les échantillons audio à la source
alSourcei(Source, AL_BUFFER, Buffer);

// Lecture du son
alSourcePlay(Source);
      return bResult;
  }