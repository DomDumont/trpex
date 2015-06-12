#ifndef __AUDIO_H__
#define __AUDIO_H__

#include <al.h>
#include <alc.h>

class Audio
{
public:
	bool Init ();
	void Shutdown ();

private:
	ALCdevice* device;
	ALCcontext* context;
};


#endif