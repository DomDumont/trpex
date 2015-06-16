#include "Global.h"

#include "Utils.h"





void UTI_Log(const std::string& _msg)
{
	printf(_msg.c_str());

#ifdef TRPEX_WIN32
	OutputDebugString(_msg.c_str());
#endif
}