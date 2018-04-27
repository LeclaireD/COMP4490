#pragma once
#include "Vec3.h"
class Light {
public:
	virtual float getIntensity() = 0;
	virtual Vec3 getLoc() = 0 ;
	virtual Vec3 getDir() = 0 ;
	virtual Vec3 getColour() = 0;
	virtual bool hasLoc() = 0;

};