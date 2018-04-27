#include "PointLight.h"

PointLight::PointLight(Vec3 loc, Vec3 colour, float intensity) {
	this->loc = loc;
	this->colour = colour;
	this->intensity = intensity;
	this->aLoc = true;
}
Vec3 PointLight::getLoc() { return loc; }
Vec3 PointLight::getDir() { return Vec3(); }
float PointLight::getIntensity() { return intensity; }
Vec3 PointLight::getColour() { return colour; }
bool PointLight::hasLoc() { return aLoc; }