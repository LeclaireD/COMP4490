#pragma once
#include "Vec3.h"
class Ray {
	Vec3 a, b;
	float t ;
public:
	Ray(Vec3, Vec3);
	Vec3 getA();
	Vec3 getB();
	float getT();
	void setT(float);
};