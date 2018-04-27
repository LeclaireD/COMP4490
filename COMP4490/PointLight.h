#pragma once
#include "Vec3.h"
#include "Light.h"
class PointLight : public Light{

float intensity, atten;
Vec3 loc, colour;
bool aLoc;

public:
	PointLight(Vec3, Vec3, float);
	float getIntensity();
	Vec3 getColour();
	Vec3 getLoc();
	Vec3 getDir();
	bool hasLoc();
};