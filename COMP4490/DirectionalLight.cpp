#include "DirectionalLight.h"

DirectionalLight::DirectionalLight(Vec3 dir, Vec3 colour, float intensity) {
	this->dir = dir;
	this->colour = colour;
	this->intensity = intensity;
	this->aLoc = false;
}
Vec3 DirectionalLight::getLoc() { return Vec3(); }
Vec3 DirectionalLight::getDir() { return dir; }
float DirectionalLight::getIntensity() { return intensity; }
Vec3 DirectionalLight::getColour() { return colour; }
bool DirectionalLight::hasLoc() { return aLoc; }