#ifndef __AUDIO_H__
#define __AUDIO_H__

#include <al.h>
#include <alc.h>

//TODO maybe should be elsewhere because it's dirty here.

#ifdef WIN32
#define TRPEX_WIN32 
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#endif

#include <string>

#pragma pack(1)
typedef struct __WAVEDESCR
	{
      BYTE riff[4];
      DWORD size;
      BYTE wave[4];
  
  } _WAVEDESCR, *_LPWAVEDESCR;
   
  typedef struct __WAVEFORMAT
  {
       BYTE id[4];
       DWORD size;
       SHORT format;
       SHORT channels;
       DWORD sampleRate;
       DWORD byteRate;
       SHORT blockAlign;
       SHORT bitsPerSample;
   
   } _WAVEFORMAT, *_LPWAVEFORMAT;
 #pragma pack()

class Audio
{
public:
	bool Init ();
	void Shutdown ();

private:
	ALCdevice* device;
	ALCcontext* context;

public:
  int LoadWavFile(std::string fullPath);
};


#endif