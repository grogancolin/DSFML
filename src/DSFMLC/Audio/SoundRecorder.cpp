/*
DSFML - The Simple and Fast Multimedia Library for D

Copyright (c) <2013> <Jeremy DeHaan>

This software is provided 'as-is', without any express or implied warranty.
In no event will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial applications,
and to alter it and redistribute it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software.
If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.

2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any source distribution


***All code is based on code written by Laurent Gomila***


External Libraries Used:

SFML - The Simple and Fast Multimedia Library
Copyright (C) 2007-2013 Laurent Gomila (laurent.gom@gmail.com)

All Libraries used by SFML - For a full list see http://www.sfml-dev.org/license.php
*/

//Headers
#include <DSFMLC/Audio/SoundRecorder.h>
#include "SoundRecorderStruct.h"


sfSoundRecorder* sfSoundRecorder_construct(SoundRecorderCallBacks* newCallBacks)
{
	return new sfSoundRecorder(newCallBacks);
}

void sfSoundRecorder_destroy(sfSoundRecorder* soundRecorder)
{
	delete soundRecorder;
}

void sfSoundRecorder_start(sfSoundRecorder* soundRecorder, DUint sampleRate)
{
	soundRecorder->This.start(sampleRate);
}

void sfSoundRecorder_stop(sfSoundRecorder* soundRecorder)
{
	soundRecorder->This.stop();
}

DUint sfSoundRecorder_getSampleRate(const sfSoundRecorder* soundRecorder)
{
	return soundRecorder->This.getSampleRate();
}

DBool sfSoundRecorder_setDevice(sfSoundRecorder* soundRecorder, const char* name, size_t length)
{
	return soundRecorder->This.setDevice(std::string(name, length));
}

const char * sfSoundRecorder_getDevice(const sfSoundRecorder* soundRecorder)
{
	return soundRecorder->This.getDevice().c_str();
}

const char ** sfSoundRecorder_getAvailableDevices (size_t* count)
{
    static std::vector<const char *> devices;

    // Populate the array on first call
    if (devices.empty())
    {
        const std::vector<std::string>& SFMLDevices = sf::SoundRecorder::getAvailableDevices();
        for (std::vector<std::string>::const_iterator it = SFMLDevices.begin(); it != SFMLDevices.end(); ++it)
        {

            devices.push_back(it->c_str());
        }
    }

    if (count)
        *count = devices.size();

    return !devices.empty() ? &devices[0] : NULL;
}

const char * sfSoundRecorder_getDefaultDevice (void)
{
	return sf::SoundRecorder::getDefaultDevice().c_str();
}

DBool sfSoundRecorder_isAvailable(void)
{
	return sf::SoundRecorder::isAvailable() ? DTrue : DFalse;
}

void sfSoundRecorder_setProcessingInterval(sfSoundRecorder* soundRecorder, DUlong time)
{
	soundRecorder->This.setProcessingIntervalD(time);
}
