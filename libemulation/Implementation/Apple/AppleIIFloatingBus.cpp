
/**
 * libemulator
 * Apple II Floating Bus
 * (C) 2011 by Marc S. Ressl (mressl@umich.edu)
 * Released under the GPL
 *
 * Implements the Apple II floating bus
 */

#include "AppleIIFloatingBus.h"

#include "AppleIIInterface.h"

AppleIIFloatingBus::AppleIIFloatingBus()
{
    video = NULL;
}

bool AppleIIFloatingBus::setRef(string name, OEComponent *ref)
{
	if (name == "video")
		video = ref;
	else
		return false;
	
	return true;
}

bool AppleIIFloatingBus::init()
{
    OECheckComponent(video);
    
    return true;
}

OEChar AppleIIFloatingBus::read(OEAddress address)
{
    OEChar value;
    
    video->postMessage(this, APPLEII_READ_FLOATINGBUS, &value);
    
	return value;
}
