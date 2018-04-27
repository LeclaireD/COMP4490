#pragma once
#include "Vec3.h"
#include "Light.h"

class DirectionalLight : public Light {

	float intensity, atten;
	Vec3 dir, colour;
	bool aLoc;

public: 
	DirectionalLight(Vec3, Vec3, float);
	float getIntensity();
	Vec3 getColour();
	Vec3 getLoc();
	Vec3 getDir();
	bool hasLoc();
};