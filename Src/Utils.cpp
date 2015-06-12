#include "Global.h"

#include "Utils.h"





void UTI_Log(const std::string& _msg)
{
	printf(_msg.c_str());
	OutputDebugString(_msg.c_str());
}