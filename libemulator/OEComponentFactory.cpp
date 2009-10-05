
/**
 * libemulator
 * Component Factory
 * (C) 2009 by Marc S. Ressl (mressl@umich.edu)
 * Released under the GPL
 */

#include "OEComponentFactory.h"

#include "EventController.h"

#define buildComponent(name) if (className == "name") return new name()

OEComponent *OEComponentFactory::build(string className)
{
	buildComponent(EventController);
	
	return new OEComponent();
//	return NULL;
}